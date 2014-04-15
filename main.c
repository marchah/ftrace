/*
** main.c for main in /home/marcha_j//test/c/strace/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Thu May  3 16:11:25 2012 hugo marchadier
** Last update Tue Jun 26 17:47:47 2012 hugo marchadier
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include <sys/types.h>
#include <sys/ptrace.h>

#include "xfct.h"
#include "ftrace.h"

static int	is_number(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (-1);
      i = i + 1;
    }
  return (1);
}

static int	is_attach(int argc, char **argv)
{
  int	i;
  int	j;

  i = 1;
  while (i != argc)
    {
      if (strcmp(argv[i], "-p") == 0)
	{
	  j = 1;
	  while (j != argc)
	    {
	      if (is_number(argv[j]) == 1)
		{
		  ptrace_attach(atoi(argv[j]));
		  return (-1);
		}
	      j = j + 1;
	    }
	}
      i = i + 1;
    }
  return (-1);
}

int     main(int argc, char **argv)
{
  pid_t                         pid;

  if (argc < 2)
    {
      printf("Usage: ./strace [-p] <pid | executable>\n");
      return (EXIT_SUCCESS);
    }
  if (is_attach(argc, argv) == -1)
    {
      if ((pid = fork()) == 0)
	{
	  xptrace(PTRACE_TRACEME, 0, NULL, 0);
	  xexecvp(argv[1], &argv[1]);
	}
      else if (pid != -1)
	strace(pid);
      else
	fprintf(stderr, "Error: fork failed\n");
    }
  return (0);
}
