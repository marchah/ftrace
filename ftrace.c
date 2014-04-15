/*
** strace.c for strace in /home/marcha_j//test/c/strace/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Fri May  4 14:54:50 2012 hugo marchadier
** Last update Tue Jun 26 16:33:09 2012 hugo marchadier
*/

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include <sys/user.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "xfct.h"
#include "ftrace.h"
#include "check_if_call.h"
#include "check_if_ret.h"
#include "tab_sym.h"
#include "dyntab_sym.h"
#include "fct_annexe.h"
#include "print.h"
#include "ncurse.h"

int	g_attached_pid;

# define INT128		0x80cd /* CD 80 = int128 */
# define SYSCALL	0x050f /* 0F 05 = syscall */
# define SYSCENTER	0x340f /* OF 34 = syscenter */

eTYPE	check_if_syscall(pid_t pid, struct user_regs_struct *regs)
{
  long	opcode;

  opcode = 0;
  opcode = xptrace(PTRACE_PEEKTEXT, pid, (void*)regs->rip, 0);
  opcode = opcode & 0xffff;
  if (opcode == INT128 || opcode == SYSCALL || opcode == SYSCENTER)
    return (eSYSCALL);
  return (eNO);
}

void	strace(pid_t pid)
{
  struct user_regs_struct	r;
  int				status;
  unsigned int			addr;
  t_sym				*tmp;
  t_info			info;
  static int			pos = 0;

  xwait(&status);
  tmp = NULL;
  init_info(&info, pid);
  aff_legende();
  while (!WIFEXITED(status))
    {
      info.size_call = 0;
      xptrace(PTRACE_GETREGS, pid, NULL, &r);
      if (check_if_syscall(pid, &r) != eNO)
	{
	  if ((int)r.rax >= 0 && r.rax < size_tab_syscall())
	    print_syscall(r.rax, pos, &info);
	  else if ((int)r.rax < 0)
	    printf("Unknow syscall: %ld\n", r.rax);
	}
      else if (check_if_call(&r, &addr, &info) != eNO)
	print_call(addr, &info, &r, &pos);
      check_if_ret(pid, &r, info.save_rip, &pos);
      xptrace(PTRACE_SINGLESTEP, pid, NULL, 0);
      xwait(&status);
    }
  free_tab_sym(info.tab);
  free_dyntab_sym(info.dyntab);
  xclose(&info);
}

void	hand(int s)
{
  (void)s;
  printf(" <unfinished ...>\nProcess %d detached\n", g_attached_pid);
  xptrace(PTRACE_CONT, g_attached_pid, 0, 0);
  exit(EXIT_SUCCESS);
}

void	ptrace_attach(pid_t pid)
{
  printf("Process %d attached - interrupt to quit\n", pid);
  xptrace(PTRACE_ATTACH, pid, NULL, 0);
  g_attached_pid = pid;
  signal(SIGINT, hand);
  strace(pid);
}

