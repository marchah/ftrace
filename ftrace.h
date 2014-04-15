/*
** strace.h for strace in /home/marcha_j//test/c/strace/proj
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Fri May  4 14:56:39 2012 hugo marchadier
** Last update Tue Jun 26 16:35:46 2012 hugo marchadier
*/

#ifndef STRACE_H_
# define STRACE_H_

#include <unistd.h>
#include <sys/user.h>
#include "list.h"
#include "tab_sym.h"

#define SIZE_CALL_E8		5
#define SIZE_CALL_FF_RM		3
#define SIZE_CALL_FF_SIB	4

#define GRAPH_NAME		"graph.dot"

typedef enum	e_type
  {
    eNO = 0,
    eSYSCALL,
    eCALL
  }		eTYPE;

typedef enum	e_status
  {
    GOOD = 0,
    NONE,
    ERROR
  }		eSTATUS;

typedef union	u_prefix
{
  char	c;
  struct	pref
  {
    unsigned long rm:3;
    unsigned long reg:3;
    unsigned long mod:2;
  }			pref;
}		t_prefix;

typedef	struct	s_info
{
  pid_t		pid;
  t_list	*save_rip;
  size_t	size_call;
  long		instr;
  eSTATUS	status_call;
  t_sym		**tab;
  t_list	*dyntab;
  int		fd;
}		t_info;

void	strace(pid_t pid);
void	hand(int s);
void	ptrace_attach(pid_t pid);

# endif /* STRACE_H_ */
