/*
** print.c for print in /home/marcha_j//test/c/strace/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Fri May  4 15:01:10 2012 hugo marchadier
** Last update Tue Jun 26 17:57:01 2012 hugo marchadier
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#include <sys/user.h>
#include <sys/ptrace.h>
#include <sys/types.h>

#include "ftrace.h"
#include "dyntab_sym.h"
#include "fct_annexe.h"
#include "print.h"
#include "xfct.h"
#include "defines.h"
#include "ncurse.h"

unsigned long	size_tab_syscall(void)
{
  int	i;

  i = 0;
  while (g_tab_syscall[i].nargs != -1)
    i++;
  return (i);
}

void	print_syscall(int syscall_num, int pos, t_info *info)
{
  if (g_tab_syscall[syscall_num].token != NULL)
    {
      if (g_tab_syscall[syscall_num].is_signal == YES)
	aff_sym((char*)g_tab_syscall[syscall_num].sys_name, C_WHITE, B_RED, pos);
      else
	aff_sym((char*)g_tab_syscall[syscall_num].sys_name, C_BLACK, B_RED, pos);
      print_graph_sym(info->save_rip, pos, info);
    }
  else
    printf("Unimplemented system calls: %s().\n",
	   g_tab_syscall[syscall_num].sys_name);
}

static t_sym*	add_call(t_sym *tmp, char *name, t_info *info, int pos)
{
  info->status_call = NONE;
  tmp->name = name;
  info->save_rip = add_maillon(info->save_rip, tmp);
  print_graph_sym(info->save_rip, pos, info);
  return (NULL);
}

void	print_call(unsigned int addr, t_info *info,
		   struct user_regs_struct *r, int *pos)
{
  int		i;
  char		*name;
  static t_sym	*tmp = NULL;
  char		convert[50];

  i = 0;
  if (tmp == NULL)
    {
      tmp = xmalloc(sizeof(*tmp));
      tmp->addr = r->rip + info->size_call;
    }
  i = find_addr_in_tab_sym(info->tab, addr);
  if (i != -1)
    {
      tmp = add_call(tmp, info->tab[i]->name, info, *pos);
      if (info->size_call == SIZE_CALL_E8)
	aff_sym(info->tab[i]->name, C_BLUE, B_WHITE, *pos);
      else
	aff_sym(info->tab[i]->name, C_BLACK, B_WHITE, *pos);
      (*pos)++;
    }
  else if ((name = find_name_dyntab(info->dyntab, addr)) != NULL)
    {
      tmp = add_call(tmp, name, info, *pos);
      if (info->size_call == SIZE_CALL_E8)
	aff_sym(name, C_BLUE, B_WHITE, *pos);
      else
	aff_sym(name, C_BLACK, B_WHITE, *pos);
      (*pos)++;
    }
  else if (info->status_call == GOOD)
    {
      snprintf(convert, 49, "%x", addr);
      tmp = add_call(tmp, convert, info, *pos);
      if (info->size_call == SIZE_CALL_E8)
	aff_sym(convert, C_BLUE, B_WHITE, *pos);
      else
	aff_sym(convert, C_BLACK, B_WHITE, *pos);
      info->status_call = NONE;
      (*pos)++;
    }
  else
    info->status_call = ERROR;
}
