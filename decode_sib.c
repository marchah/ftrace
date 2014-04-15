/*
** decode_sib.c for decode_sib in /home/marcha_j//test/c/ftrace
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Thu May 31 16:41:28 2012 hugo marchadier
** Last update Fri Jun 22 14:45:32 2012 hugo marchadier
*/

#include <stdio.h>

#include <unistd.h>

#include "xfct.h"
#include "ftrace.h"
#include "decode_mode_rm.h"
#include "decode_sib.h"

t_sib	tab_sib[];

static unsigned long	sib_recup_addr_with_ptrace(pid_t pid,
						  struct user_regs_struct *regs,
						  eSTATUS *status, unsigned long index,
						  int mult)
{
  switch (index)
    {
    case 0:
      return (xptrace(PTRACE_PEEKTEXT, pid, (void*)(regs->rax * mult), 0));
    case 1:
      return (xptrace(PTRACE_PEEKTEXT, pid, (void*)(regs->rcx * mult), 0));
    case 2:
      return (xptrace(PTRACE_PEEKTEXT, pid, (void*)(regs->rdx * mult), 0));
    case 3:
      return (xptrace(PTRACE_PEEKTEXT, pid, (void*)(regs->rbx * mult), 0));
    case 4:
      *status = NONE;
      return (0);
    case 5:
      return (xptrace(PTRACE_PEEKTEXT, pid, (void*)(regs->rbp * mult), 0));
    case 6:
      return (xptrace(PTRACE_PEEKTEXT, pid, (void*)(regs->rsi * mult), 0));
    case 7:
      return (xptrace(PTRACE_PEEKTEXT, pid, (void*)(regs->rdi * mult), 0));
    default:
      break;
    }
  printf("Error: unknow sib index.\n");
  *status = ERROR;
  return (0);
}

static unsigned long fct_repart_tache(pid_t pid, struct user_regs_struct *r,
				      eSTATUS *status, eTACHE tache,
				      unsigned long index, unsigned int mult)
{
  switch (tache)
    {
    case NOTHING:
      return (0);
    case PTRACE:
      return (sib_recup_addr_with_ptrace(pid, r, status, index, mult));
    default:
      break;
    }
  *status = ERROR;
  printf("Error: unknow tache.\n");
  return (0);
}

unsigned long	decode_sib(pid_t pid, struct user_regs_struct *r,
			   eSTATUS *status, unsigned long instr)
{
  unsigned char *instr_tab;
  t_prefix	sib;
  int		i;

  i = 0;
  instr_tab = (unsigned char *)&instr;
  sib.c = instr_tab[1];
  while (tab_sib[i].tache != ANY)
    {
      if (sib.pref.mod == tab_sib[i].ss && sib.pref.reg == tab_sib[i].base
	  && sib.pref.rm == tab_sib[i].index)
	{
	  return (fct_repart_tache(pid, r, status, tab_sib[i].tache,
				   tab_sib[i].index, tab_sib[i].mult));
	}
      i++;
    }
  *status = ERROR;
  printf("Error: Invalid SIB.\n");
  return (0);
}

t_sib	tab_sib[] =
  {

    {0, 0, 0, PTRACE, 1},
    {0, 0, 1, PTRACE, 1},
    {0, 0, 2, PTRACE, 1},
    {0, 0, 3, PTRACE, 1},
    {0, 0, 4, NOTHING, 1},
    {0, 0, 5, NOTHING, 1},
    {0, 0, 6, PTRACE, 1},
    {0, 0, 7, PTRACE, 1},

    {0, 1, 0, PTRACE, 1},
    {0, 1, 1, PTRACE, 1},
    {0, 1, 2, PTRACE, 1},
    {0, 1, 3, PTRACE, 1},
    {0, 1, 4, NOTHING, 1},
    {0, 1, 5, NOTHING, 1},
    {0, 1, 6, PTRACE, 1},
    {0, 1, 7, PTRACE, 1},

    {0, 2, 0, PTRACE, 1},
    {0, 2, 1, PTRACE, 1},
    {0, 2, 2, PTRACE, 1},
    {0, 2, 3, PTRACE, 1},
    {0, 2, 4, NOTHING, 1},
    {0, 2, 5, NOTHING, 1},
    {0, 2, 6, PTRACE, 1},
    {0, 2, 7, PTRACE, 1},

    {0, 3, 0, PTRACE, 1},
    {0, 3, 1, PTRACE, 1},
    {0, 3, 2, PTRACE, 1},
    {0, 3, 3, PTRACE, 1},
    {0, 3, 4, NOTHING, 1},
    {0, 3, 5, NOTHING, 1},
    {0, 3, 6, PTRACE, 1},
    {0, 3, 7, PTRACE, 1},

    {0, 4, 0, PTRACE, 1},
    {0, 4, 1, PTRACE, 1},
    {0, 4, 2, PTRACE, 1},
    {0, 4, 3, PTRACE, 1},
    {0, 4, 4, NOTHING, 1},
    {0, 4, 5, NOTHING, 1},
    {0, 4, 6, PTRACE, 1},
    {0, 4, 7, PTRACE, 1},

    {0, 5, 0, PTRACE, 1},
    {0, 5, 1, PTRACE, 1},
    {0, 5, 2, PTRACE, 1},
    {0, 5, 3, PTRACE, 1},
    {0, 5, 4, NOTHING, 1},
    {0, 5, 5, NOTHING, 1},
    {0, 5, 6, PTRACE, 1},
    {0, 5, 7, PTRACE, 1},

    {0, 6, 0, PTRACE, 1},
    {0, 6, 1, PTRACE, 1},
    {0, 6, 2, PTRACE, 1},
    {0, 6, 3, PTRACE, 1},
    {0, 6, 4, NOTHING, 1},
    {0, 6, 5, NOTHING, 1},
    {0, 6, 6, PTRACE, 1},
    {0, 6, 7, PTRACE, 1},

    {0, 7, 0, PTRACE, 1},
    {0, 7, 1, PTRACE, 1},
    {0, 7, 2, PTRACE, 1},
    {0, 7, 3, PTRACE, 1},
    {0, 7, 4, NOTHING, 1},
    {0, 7, 5, NOTHING, 1},
    {0, 7, 6, PTRACE, 1},
    {0, 7, 7, PTRACE, 1},



    {1, 0, 0, PTRACE, 2},
    {1, 0, 1, PTRACE, 2},
    {1, 0, 2, PTRACE, 2},
    {1, 0, 3, PTRACE, 2},
    {1, 0, 4, NOTHING, 2},
    {1, 0, 5, PTRACE, 2},
    {1, 0, 6, PTRACE, 2},
    {1, 0, 7, PTRACE, 2},

    {1, 1, 0, PTRACE, 2},
    {1, 1, 1, PTRACE, 2},
    {1, 1, 2, PTRACE, 2},
    {1, 1, 3, PTRACE, 2},
    {1, 1, 4, NOTHING, 2},
    {1, 1, 5, PTRACE, 2},
    {1, 1, 6, PTRACE, 2},
    {1, 1, 7, PTRACE, 2},

    {1, 2, 0, PTRACE, 2},
    {1, 2, 1, PTRACE, 2},
    {1, 2, 2, PTRACE, 2},
    {1, 2, 3, PTRACE, 2},
    {1, 2, 4, NOTHING, 2},
    {1, 2, 5, PTRACE, 2},
    {1, 2, 6, PTRACE, 2},
    {1, 2, 7, PTRACE, 2},

    {1, 3, 0, PTRACE, 2},
    {1, 3, 1, PTRACE, 2},
    {1, 3, 2, PTRACE, 2},
    {1, 3, 3, PTRACE, 2},
    {1, 3, 4, NOTHING, 2},
    {1, 3, 5, PTRACE, 2},
    {1, 3, 6, PTRACE, 2},
    {1, 3, 7, PTRACE, 2},

    {1, 4, 0, PTRACE, 2},
    {1, 4, 1, PTRACE, 2},
    {1, 4, 2, PTRACE, 2},
    {1, 4, 3, PTRACE, 2},
    {1, 4, 4, NOTHING, 2},
    {1, 4, 5, PTRACE, 2},
    {1, 4, 6, PTRACE, 2},
    {1, 4, 7, PTRACE, 2},

    {1, 5, 0, PTRACE, 2},
    {1, 5, 1, PTRACE, 2},
    {1, 5, 2, PTRACE, 2},
    {1, 5, 3, PTRACE, 2},
    {1, 5, 4, NOTHING, 2},
    {1, 5, 5, PTRACE, 2},
    {1, 5, 6, PTRACE, 2},
    {1, 5, 7, PTRACE, 2},

    {1, 6, 0, PTRACE, 2},
    {1, 6, 1, PTRACE, 2},
    {1, 6, 2, PTRACE, 2},
    {1, 6, 3, PTRACE, 2},
    {1, 6, 4, NOTHING, 2},
    {1, 6, 5, PTRACE, 2},
    {1, 6, 6, PTRACE, 2},
    {1, 6, 7, PTRACE, 2},

    {1, 7, 0, PTRACE, 2},
    {1, 7, 1, PTRACE, 2},
    {1, 7, 2, PTRACE, 2},
    {1, 7, 3, PTRACE, 2},
    {1, 7, 4, NOTHING, 2},
    {1, 7, 5, PTRACE, 2},
    {1, 7, 6, PTRACE, 2},
    {1, 7, 7, PTRACE, 2},



    {2, 0, 0, PTRACE, 4},
    {2, 0, 1, PTRACE, 4},
    {2, 0, 2, PTRACE, 4},
    {2, 0, 3, PTRACE, 4},
    {2, 0, 4, NOTHING, 4},
    {2, 0, 5, PTRACE, 4},
    {2, 0, 6, PTRACE, 4},
    {2, 0, 7, PTRACE, 4},

    {2, 1, 0, PTRACE, 4},
    {2, 1, 1, PTRACE, 4},
    {2, 1, 2, PTRACE, 4},
    {2, 1, 3, PTRACE, 4},
    {2, 1, 4, NOTHING, 4},
    {2, 1, 5, PTRACE, 4},
    {2, 1, 6, PTRACE, 4},
    {2, 1, 7, PTRACE, 4},

    {2, 2, 0, PTRACE, 4},
    {2, 2, 1, PTRACE, 4},
    {2, 2, 2, PTRACE, 4},
    {2, 2, 3, PTRACE, 4},
    {2, 2, 4, NOTHING, 4},
    {2, 2, 5, PTRACE, 4},
    {2, 2, 6, PTRACE, 4},
    {2, 2, 7, PTRACE, 4},

    {2, 3, 0, PTRACE, 4},
    {2, 3, 1, PTRACE, 4},
    {2, 3, 2, PTRACE, 4},
    {2, 3, 3, PTRACE, 4},
    {2, 3, 4, NOTHING, 4},
    {2, 3, 5, PTRACE, 4},
    {2, 3, 6, PTRACE, 4},
    {2, 3, 7, PTRACE, 4},

    {2, 4, 0, PTRACE, 4},
    {2, 4, 1, PTRACE, 4},
    {2, 4, 2, PTRACE, 4},
    {2, 4, 3, PTRACE, 4},
    {2, 4, 4, NOTHING, 4},
    {2, 4, 5, PTRACE, 4},
    {2, 4, 6, PTRACE, 4},
    {2, 4, 7, PTRACE, 4},

    {2, 5, 0, PTRACE, 4},
    {2, 5, 1, PTRACE, 4},
    {2, 5, 2, PTRACE, 4},
    {2, 5, 3, PTRACE, 4},
    {2, 5, 4, NOTHING, 4},
    {2, 5, 5, PTRACE, 4},
    {2, 5, 6, PTRACE, 4},
    {2, 5, 7, PTRACE, 4},

    {2, 6, 0, PTRACE, 4},
    {2, 6, 1, PTRACE, 4},
    {2, 6, 6, PTRACE, 4},
    {2, 6, 3, PTRACE, 4},
    {2, 6, 4, NOTHING, 4},
    {2, 6, 5, PTRACE, 4},
    {2, 6, 6, PTRACE, 4},
    {2, 6, 7, PTRACE, 4},

    {2, 7, 0, PTRACE, 4},
    {2, 7, 1, PTRACE, 4},
    {2, 7, 2, PTRACE, 4},
    {2, 7, 3, PTRACE, 4},
    {2, 7, 4, NOTHING, 4},
    {2, 7, 5, PTRACE, 4},
    {2, 7, 6, PTRACE, 4},
    {2, 7, 7, PTRACE, 4},



    {3, 0, 0, REG, 8},
    {3, 0, 1, REG, 8},
    {3, 0, 2, REG, 8},
    {3, 0, 3, REG, 8},
    {3, 0, 4, REG, 8},
    {3, 0, 5, REG, 8},
    {3, 0, 6, REG, 8},
    {3, 0, 7, REG, 8},

    {3, 1, 0, REG, 8},
    {3, 1, 1, REG, 8},
    {3, 1, 2, REG, 8},
    {3, 1, 3, REG, 8},
    {3, 1, 4, REG, 8},
    {3, 1, 5, REG, 8},
    {3, 1, 6, REG, 8},
    {3, 1, 7, REG, 8},

    {3, 2, 0, REG, 8},
    {3, 2, 1, REG, 8},
    {3, 2, 2, REG, 8},
    {3, 2, 3, REG, 8},
    {3, 2, 4, REG, 8},
    {3, 2, 5, REG, 8},
    {3, 2, 6, REG, 8},
    {3, 2, 7, REG, 8},

    {3, 3, 0, REG, 8},
    {3, 3, 1, REG, 8},
    {3, 3, 2, REG, 8},
    {3, 3, 3, REG, 8},
    {3, 3, 4, REG, 8},
    {3, 3, 5, REG, 8},
    {3, 3, 6, REG, 8},
    {3, 3, 7, REG, 8},

    {3, 4, 0, REG, 8},
    {3, 4, 1, REG, 8},
    {3, 4, 2, REG, 8},
    {3, 4, 3, REG, 8},
    {3, 4, 4, REG, 8},
    {3, 4, 5, REG, 8},
    {3, 4, 6, REG, 8},
    {3, 4, 7, REG, 8},

    {3, 5, 0, REG, 8},
    {3, 5, 1, REG, 8},
    {3, 5, 2, REG, 8},
    {3, 5, 3, REG, 8},
    {3, 5, 4, REG, 8},
    {3, 5, 5, REG, 8},
    {3, 5, 6, REG, 8},
    {3, 5, 7, REG, 8},

    {3, 6, 0, REG, 8},
    {3, 6, 1, REG, 8},
    {3, 6, 2, REG, 8},
    {3, 6, 3, REG, 8},
    {3, 6, 4, REG, 8},
    {3, 6, 5, REG, 8},
    {3, 6, 6, REG, 8},
    {3, 6, 7, REG, 8},

    {3, 7, 0, REG, 8},
    {3, 7, 1, REG, 8},
    {3, 7, 2, REG, 8},
    {3, 7, 3, REG, 8},
    {3, 7, 4, REG, 8},
    {3, 7, 5, REG, 8},
    {3, 7, 6, REG, 8},
    {3, 7, 7, REG, 8},
    {0, 0, 0, ANY, 8}
  };
