/*
** check_if_ret.c for check_if_ret in /home/marcha_j//svn/c/ftrace-2015-2014s-marcha_j
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Fri Jun 22 14:58:22 2012 hugo marchadier
** Last update Tue Jun 26 17:57:19 2012 hugo marchadier
*/

#include <stdlib.h>
#include <stdio.h>

#include <sys/user.h>
#include <sys/ptrace.h>

#include "ftrace.h"
#include "tab_sym.h"
#include "xfct.h"
#include "decode_mode_rm.h"
#include "ncurse.h"

# define IS_RET_WITH_ARG(a)	((((a) & 0xff) == 0xc2) || (((a) & 0xff) == 0xca))
# define IS_RET(a)		(((a & 0xff) == 0xc3) || ((a & 0xff) == 0xcb))

static t_list*	list_save_rip(t_list *tmp, long return_rip,
			      int *pos, char *C_COLOR)
{
  t_list *save_rip;

  save_rip = tmp;
  while (save_rip != NULL)
    {
      if (save_rip->data != NULL
	  && save_rip->data->addr == return_rip)
	{
	  (*pos)--;
	  if (save_rip->prev != NULL && save_rip->prev->data != NULL)
	    aff_ret(save_rip->prev->data->name, C_COLOR, B_BLUE, *pos);
	  else
	    aff_ret(NULL, C_COLOR, B_BLUE, *pos);
	  return (tmp);
	}
      save_rip = save_rip->next;
    }
  return (tmp);
}

void	check_if_ret(pid_t pid, struct user_regs_struct *regs,
		     t_list *save_rip, int *pos)
{
  long	instr;
  long	arg;
  long	fct_rip;

  instr = 0;
  instr = xptrace(PTRACE_PEEKTEXT, pid, (void*)regs->rip, 0);
  if (IS_RET(instr))
    {
      fct_rip = xptrace(PTRACE_PEEKTEXT, pid, (void*)regs->rsp, 0);
      list_save_rip(save_rip, fct_rip, pos, C_RED);
    }
  if (IS_RET_WITH_ARG(instr))
    {
      arg = ((instr >> 8) & 0xff);
      fct_rip = xptrace(PTRACE_PEEKTEXT, pid, (void*)regs->rsp, 0);
      list_save_rip(save_rip, fct_rip, pos, C_WHITE);
    }
}
