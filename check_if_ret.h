/*
** check_if_ret.h for check_if_ret in /home/marcha_j//svn/c/ftrace-2015-2014s-marcha_j
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Fri Jun 22 14:59:52 2012 hugo marchadier
** Last update Fri Jun 22 16:38:11 2012 hugo marchadier
*/

#ifndef	CHECK_IF_RET_H_
# define CHECK_IF_RET_H_

#include "list.h"

void	check_if_ret(pid_t pid, struct user_regs_struct *regs,
		     t_list *save_rip, int *pos);

#endif /* !CHECK_IF_RET_H_ */
