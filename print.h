/*
** print.h for print in /home/marcha_j//test/c/strace/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Fri May  4 15:03:58 2012 hugo marchadier
** Last update Tue Jun 26 16:32:42 2012 hugo marchadier
*/

#ifndef PRINT_H_
# define PRINT_H_

unsigned long	size_tab_syscall(void);
void		print_syscall(int syscall_num, int pos, t_info *info);
void		print_call(unsigned int addr, t_info *info,
			   struct user_regs_struct *r, int *pos);

# endif /* PRINT_H_ */
