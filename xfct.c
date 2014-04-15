/*
** xfct.h for xfct.h in /home/marcha_j//test/c/strace/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Thu May  3 16:05:37 2012 hugo marchadier
** Last update Wed May 23 15:44:20 2012 hugo marchadier
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>

long	xptrace(enum __ptrace_request request, pid_t pid,
		void *addr, void *data)
{
  long	r;

  errno = 0;
  if ((r = ptrace(request, pid, addr, data)) == -1)
    {
      fprintf(stderr, "Error: ptrace failed: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  return (r);
}

void	xexecvp(char *ex, char **arg)
{
  errno = 0;
  if (execvp(ex, arg) == -1)
    {
      fprintf(stderr, "Error: execvp failed: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
}

void	xwait(int *status)
{
  errno = 0;
  if (wait(status) == -1)
    {
      fprintf(stderr, "Error: wait failed: %s\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
}

void	*xmalloc(size_t size)
{
  void	*ptr;

  errno = 0;
  if ((ptr = malloc(size)) == NULL)
    {
      fprintf(stderr, "Error: malloc failed, %s.\n", strerror(errno));
      exit(EXIT_FAILURE);
    }
  return (ptr);
}
