/*
** xfct.h for xfct in /home/marcha_j//test/c/ftrace/tp
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Wed May 23 15:42:47 2012 hugo marchadier
** Last update Wed May 23 15:45:05 2012 hugo marchadier
*/

#ifndef XFCT_H_
# define XFCT_H_

#include <sys/ptrace.h>

long	xptrace(enum __ptrace_request request, pid_t pid,
		void *addr, void *data);
void	xexecvp(char *ex, char **arg);
void	xwait(int *status);
void	*xmalloc(size_t size);

# endif /* XFCT_H_ */
