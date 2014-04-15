/*
** decode_mode_rm.c for decode mode rm in /home/marcha_j//test/c/ftrace
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Thu May 31 16:22:19 2012 hugo marchadier
** Last update Fri Jun 22 14:45:05 2012 hugo marchadier
*/

#include <stdio.h>

#include <unistd.h>

#include "xfct.h"
#include "ftrace.h"
#include "decode_mode_rm.h"
#include "calc_disp.h"
#include "decode_sib.h"

t_rm	tab_rm[];

unsigned long	rm_recup_addr_with_ptrace(pid_t pid,
					  struct user_regs_struct *regs,
					  eSTATUS *status, unsigned long rm)
{
  switch (rm)
    {
    case 0:
      return (xptrace(PTRACE_PEEKTEXT, pid, (void*)regs->rax, 0));
    case 1:
      return (xptrace(PTRACE_PEEKTEXT, pid, (void*)regs->rcx, 0));
    case 2:
      return (xptrace(PTRACE_PEEKTEXT, pid, (void*)regs->rdx, 0));
    case 3:
      return (xptrace(PTRACE_PEEKTEXT, pid, (void*)regs->rbx, 0));
    case 4:
      *status = ERROR;
      return (0);
    case 5:
      return (xptrace(PTRACE_PEEKTEXT, pid, (void*)regs->rbp, 0));
    case 6:
      return (xptrace(PTRACE_PEEKTEXT, pid, (void*)regs->rsi, 0));
    case 7:
      return (xptrace(PTRACE_PEEKTEXT, pid, (void*)regs->rdi, 0));
    default:
      break;
    }
  printf("Error: unknow rm mode.\n");
  *status = ERROR;
  return (0);
}

static unsigned long	rm_recup_addr_with_reg(struct user_regs_struct *regs,
					       eSTATUS *status, unsigned long rm)
{
  switch (rm)
    {
    case 0:
      return (regs->rax);
    case 1:
      return (regs->rcx);
    case 2:
      return (regs->rdx);
    case 3:
      return (regs->rbx);
    case 4:
      *status = ERROR;
      return (0);
    case 5:
      return (regs->rbp);
    case 6:
      return (regs->rsi);
    case 7:
      return (regs->rdi);
    default:
      break;
    }
  printf("\tError: unknow rm mode.\t");
  *status = ERROR;
  return (0);
}

static unsigned long	fct_repart_tache(struct user_regs_struct *r,
					 eSTATUS *status, eTACHE tache,
					 unsigned long rm, t_info *info)
{
  switch (tache)
    {
    case NOTHING:
      return (0);
    case PTRACE:
      info->size_call = SIZE_CALL_FF_RM;
      return (rm_recup_addr_with_ptrace(info->pid, r, status, rm));
    case REG:
      info->size_call = SIZE_CALL_FF_RM;
      return (rm_recup_addr_with_reg(r, status, rm));
    case SIB:
      info->size_call = SIZE_CALL_FF_SIB;
      return (decode_sib(info->pid, r, status, info->instr));
    default:
      break;
    }
  *status = ERROR;
  printf("Error: unknow tache.\n");
  return (0);
}

unsigned long	decode_mode_rm(struct user_regs_struct *r,
			       eSTATUS *status, t_prefix mode_rm,
			       t_info *info)
{
  int	i;

  i = 0;
  while (tab_rm[i].tache != ANY)
    {
      if (mode_rm.pref.mod == tab_rm[i].mod
	  && mode_rm.pref.reg == tab_rm[i].reg
	  && mode_rm.pref.rm == tab_rm[i].rm)
	{
	  return (fct_repart_tache(r, status, tab_rm[i].tache, tab_rm[i].rm, info)
		  + check_disp(status, tab_rm[i].disp, tab_rm[i].tache, info->instr));
	}
      i++;
    }
  *status = ERROR;
  printf("Error: Invalid mod rm.\n");
  return (0);
}

t_rm	tab_rm[] =
  {

    {0, 0, 0, PTRACE, NO_DISP},
    {0, 0, 1, PTRACE, NO_DISP},
    {0, 0, 2, PTRACE, NO_DISP},
    {0, 0, 3, PTRACE, NO_DISP},
    {0, 0, 4, SIB, NO_DISP},
    {0, 0, 5, NOTHING, NO_DISP},
    {0, 0, 6, PTRACE, NO_DISP},
    {0, 0, 7, PTRACE, NO_DISP},

    {0, 1, 0, PTRACE, NO_DISP},
    {0, 1, 1, PTRACE, NO_DISP},
    {0, 1, 2, PTRACE, NO_DISP},
    {0, 1, 3, PTRACE, NO_DISP},
    {0, 1, 4, SIB, NO_DISP},
    {0, 1, 5, NOTHING, NO_DISP},
    {0, 1, 6, PTRACE, NO_DISP},
    {0, 1, 7, PTRACE, NO_DISP},

    {0, 2, 0, PTRACE, NO_DISP},
    {0, 2, 1, PTRACE, NO_DISP},
    {0, 2, 2, PTRACE, NO_DISP},
    {0, 2, 3, PTRACE, NO_DISP},
    {0, 2, 4, SIB, NO_DISP},
    {0, 2, 5, NOTHING, NO_DISP},
    {0, 2, 6, PTRACE, NO_DISP},
    {0, 2, 7, PTRACE, NO_DISP},

    {0, 3, 0, PTRACE, NO_DISP},
    {0, 3, 1, PTRACE, NO_DISP},
    {0, 3, 2, PTRACE, NO_DISP},
    {0, 3, 3, PTRACE, NO_DISP},
    {0, 3, 4, SIB, NO_DISP},
    {0, 3, 5, NOTHING, NO_DISP},
    {0, 3, 6, PTRACE, NO_DISP},
    {0, 3, 7, PTRACE, NO_DISP},

    {0, 4, 0, PTRACE, NO_DISP},
    {0, 4, 1, PTRACE, NO_DISP},
    {0, 4, 2, PTRACE, NO_DISP},
    {0, 4, 3, PTRACE, NO_DISP},
    {0, 4, 4, SIB, NO_DISP},
    {0, 4, 5, NOTHING, NO_DISP},
    {0, 4, 6, PTRACE, NO_DISP},
    {0, 4, 7, PTRACE, NO_DISP},

    {0, 5, 0, PTRACE, NO_DISP},
    {0, 5, 1, PTRACE, NO_DISP},
    {0, 5, 2, PTRACE, NO_DISP},
    {0, 5, 3, PTRACE, NO_DISP},
    {0, 5, 4, SIB, NO_DISP},
    {0, 5, 5, NOTHING, NO_DISP},
    {0, 5, 6, PTRACE, NO_DISP},
    {0, 5, 7, PTRACE, NO_DISP},

    {0, 6, 0, PTRACE, NO_DISP},
    {0, 6, 1, PTRACE, NO_DISP},
    {0, 6, 2, PTRACE, NO_DISP},
    {0, 6, 3, PTRACE, NO_DISP},
    {0, 6, 4, SIB, NO_DISP},
    {0, 6, 5, NOTHING, NO_DISP},
    {0, 6, 6, PTRACE, NO_DISP},
    {0, 6, 7, PTRACE, NO_DISP},

    {0, 7, 0, PTRACE, NO_DISP},
    {0, 7, 1, PTRACE, NO_DISP},
    {0, 7, 2, PTRACE, NO_DISP},
    {0, 7, 3, PTRACE, NO_DISP},
    {0, 7, 4, SIB, NO_DISP},
    {0, 7, 5, NOTHING, NO_DISP},
    {0, 7, 6, PTRACE, NO_DISP},
    {0, 7, 7, PTRACE, NO_DISP},



    {1, 0, 0, PTRACE, DISP8},
    {1, 0, 1, PTRACE, DISP8},
    {1, 0, 2, PTRACE, DISP8},
    {1, 0, 3, PTRACE, DISP8},
    {1, 0, 4, SIB, DISP8},
    {1, 0, 5, PTRACE, DISP8},
    {1, 0, 6, PTRACE, DISP8},
    {1, 0, 7, PTRACE, DISP8},

    {1, 1, 0, PTRACE, DISP8},
    {1, 1, 1, PTRACE, DISP8},
    {1, 1, 2, PTRACE, DISP8},
    {1, 1, 3, PTRACE, DISP8},
    {1, 1, 4, SIB, DISP8},
    {1, 1, 5, PTRACE, DISP8},
    {1, 1, 6, PTRACE, DISP8},
    {1, 1, 7, PTRACE, DISP8},

    {1, 2, 0, PTRACE, DISP8},
    {1, 2, 1, PTRACE, DISP8},
    {1, 2, 2, PTRACE, DISP8},
    {1, 2, 3, PTRACE, DISP8},
    {1, 2, 4, SIB, DISP8},
    {1, 2, 5, PTRACE, DISP8},
    {1, 2, 6, PTRACE, DISP8},
    {1, 2, 7, PTRACE, DISP8},

    {1, 3, 0, PTRACE, DISP8},
    {1, 3, 1, PTRACE, DISP8},
    {1, 3, 2, PTRACE, DISP8},
    {1, 3, 3, PTRACE, DISP8},
    {1, 3, 4, SIB, DISP8},
    {1, 3, 5, PTRACE, DISP8},
    {1, 3, 6, PTRACE, DISP8},
    {1, 3, 7, PTRACE, DISP8},

    {1, 4, 0, PTRACE, DISP8},
    {1, 4, 1, PTRACE, DISP8},
    {1, 4, 2, PTRACE, DISP8},
    {1, 4, 3, PTRACE, DISP8},
    {1, 4, 4, SIB, DISP8},
    {1, 4, 5, PTRACE, DISP8},
    {1, 4, 6, PTRACE, DISP8},
    {1, 4, 7, PTRACE, DISP8},

    {1, 5, 0, PTRACE, DISP8},
    {1, 5, 1, PTRACE, DISP8},
    {1, 5, 2, PTRACE, DISP8},
    {1, 5, 3, PTRACE, DISP8},
    {1, 5, 4, SIB, DISP8},
    {1, 5, 5, PTRACE, DISP8},
    {1, 5, 6, PTRACE, DISP8},
    {1, 5, 7, PTRACE, DISP8},

    {1, 6, 0, PTRACE, DISP8},
    {1, 6, 1, PTRACE, DISP8},
    {1, 6, 2, PTRACE, DISP8},
    {1, 6, 3, PTRACE, DISP8},
    {1, 6, 4, SIB, DISP8},
    {1, 6, 5, PTRACE, DISP8},
    {1, 6, 6, PTRACE, DISP8},
    {1, 6, 7, PTRACE, DISP8},

    {1, 7, 0, PTRACE, DISP8},
    {1, 7, 1, PTRACE, DISP8},
    {1, 7, 2, PTRACE, DISP8},
    {1, 7, 3, PTRACE, DISP8},
    {1, 7, 4, SIB, DISP8},
    {1, 7, 5, PTRACE, DISP8},
    {1, 7, 6, PTRACE, DISP8},
    {1, 7, 7, PTRACE, DISP8},



    {2, 0, 0, PTRACE, DISP32},
    {2, 0, 1, PTRACE, DISP32},
    {2, 0, 2, PTRACE, DISP32},
    {2, 0, 3, PTRACE, DISP32},
    {2, 0, 4, SIB, DISP32},
    {2, 0, 5, PTRACE, DISP32},
    {2, 0, 6, PTRACE, DISP32},
    {2, 0, 7, PTRACE, DISP32},

    {2, 1, 0, PTRACE, DISP32},
    {2, 1, 1, PTRACE, DISP32},
    {2, 1, 2, PTRACE, DISP32},
    {2, 1, 3, PTRACE, DISP32},
    {2, 1, 4, SIB, DISP32},
    {2, 1, 5, PTRACE, DISP32},
    {2, 1, 6, PTRACE, DISP32},
    {2, 1, 7, PTRACE, DISP32},

    {2, 2, 0, PTRACE, DISP32},
    {2, 2, 1, PTRACE, DISP32},
    {2, 2, 2, PTRACE, DISP32},
    {2, 2, 3, PTRACE, DISP32},
    {2, 2, 4, SIB, DISP32},
    {2, 2, 5, PTRACE, DISP32},
    {2, 2, 6, PTRACE, DISP32},
    {2, 2, 7, PTRACE, DISP32},

    {2, 3, 0, PTRACE, DISP32},
    {2, 3, 1, PTRACE, DISP32},
    {2, 3, 2, PTRACE, DISP32},
    {2, 3, 3, PTRACE, DISP32},
    {2, 3, 4, SIB, DISP32},
    {2, 3, 5, PTRACE, DISP32},
    {2, 3, 6, PTRACE, DISP32},
    {2, 3, 7, PTRACE, DISP32},

    {2, 4, 0, PTRACE, DISP32},
    {2, 4, 1, PTRACE, DISP32},
    {2, 4, 2, PTRACE, DISP32},
    {2, 4, 3, PTRACE, DISP32},
    {2, 4, 4, SIB, DISP32},
    {2, 4, 5, PTRACE, DISP32},
    {2, 4, 6, PTRACE, DISP32},
    {2, 4, 7, PTRACE, DISP32},

    {2, 5, 0, PTRACE, DISP32},
    {2, 5, 1, PTRACE, DISP32},
    {2, 5, 2, PTRACE, DISP32},
    {2, 5, 3, PTRACE, DISP32},
    {2, 5, 4, SIB, DISP32},
    {2, 5, 5, PTRACE, DISP32},
    {2, 5, 6, PTRACE, DISP32},
    {2, 5, 7, PTRACE, DISP32},

    {2, 6, 0, PTRACE, DISP32},
    {2, 6, 1, PTRACE, DISP32},
    {2, 6, 6, PTRACE, DISP32},
    {2, 6, 3, PTRACE, DISP32},
    {2, 6, 4, SIB, DISP32},
    {2, 6, 5, PTRACE, DISP32},
    {2, 6, 6, PTRACE, DISP32},
    {2, 6, 7, PTRACE, DISP32},

    {2, 7, 0, PTRACE, DISP32},
    {2, 7, 1, PTRACE, DISP32},
    {2, 7, 2, PTRACE, DISP32},
    {2, 7, 3, PTRACE, DISP32},
    {2, 7, 4, SIB, DISP32},
    {2, 7, 5, PTRACE, DISP32},
    {2, 7, 6, PTRACE, DISP32},
    {2, 7, 7, PTRACE, DISP32},



    {3, 0, 0, REG, NO_DISP},
    {3, 0, 1, REG, NO_DISP},
    {3, 0, 2, REG, NO_DISP},
    {3, 0, 3, REG, NO_DISP},
    {3, 0, 4, REG, NO_DISP},
    {3, 0, 5, REG, NO_DISP},
    {3, 0, 6, REG, NO_DISP},
    {3, 0, 7, REG, NO_DISP},

    {3, 1, 0, REG, NO_DISP},
    {3, 1, 1, REG, NO_DISP},
    {3, 1, 2, REG, NO_DISP},
    {3, 1, 3, REG, NO_DISP},
    {3, 1, 4, REG, NO_DISP},
    {3, 1, 5, REG, NO_DISP},
    {3, 1, 6, REG, NO_DISP},
    {3, 1, 7, REG, NO_DISP},

    {3, 2, 0, REG, NO_DISP},
    {3, 2, 1, REG, NO_DISP},
    {3, 2, 2, REG, NO_DISP},
    {3, 2, 3, REG, NO_DISP},
    {3, 2, 4, REG, NO_DISP},
    {3, 2, 5, REG, NO_DISP},
    {3, 2, 6, REG, NO_DISP},
    {3, 2, 7, REG, NO_DISP},

    {3, 3, 0, REG, NO_DISP},
    {3, 3, 1, REG, NO_DISP},
    {3, 3, 2, REG, NO_DISP},
    {3, 3, 3, REG, NO_DISP},
    {3, 3, 4, REG, NO_DISP},
    {3, 3, 5, REG, NO_DISP},
    {3, 3, 6, REG, NO_DISP},
    {3, 3, 7, REG, NO_DISP},

    {3, 4, 0, REG, NO_DISP},
    {3, 4, 1, REG, NO_DISP},
    {3, 4, 2, REG, NO_DISP},
    {3, 4, 3, REG, NO_DISP},
    {3, 4, 4, REG, NO_DISP},
    {3, 4, 5, REG, NO_DISP},
    {3, 4, 6, REG, NO_DISP},
    {3, 4, 7, REG, NO_DISP},

    {3, 5, 0, REG, NO_DISP},
    {3, 5, 1, REG, NO_DISP},
    {3, 5, 2, REG, NO_DISP},
    {3, 5, 3, REG, NO_DISP},
    {3, 5, 4, REG, NO_DISP},
    {3, 5, 5, REG, NO_DISP},
    {3, 5, 6, REG, NO_DISP},
    {3, 5, 7, REG, NO_DISP},

    {3, 6, 0, REG, NO_DISP},
    {3, 6, 1, REG, NO_DISP},
    {3, 6, 2, REG, NO_DISP},
    {3, 6, 3, REG, NO_DISP},
    {3, 6, 4, REG, NO_DISP},
    {3, 6, 5, REG, NO_DISP},
    {3, 6, 6, REG, NO_DISP},
    {3, 6, 7, REG, NO_DISP},

    {3, 7, 0, REG, NO_DISP},
    {3, 7, 1, REG, NO_DISP},
    {3, 7, 2, REG, NO_DISP},
    {3, 7, 3, REG, NO_DISP},
    {3, 7, 4, REG, NO_DISP},
    {3, 7, 5, REG, NO_DISP},
    {3, 7, 6, REG, NO_DISP},
    {3, 7, 7, REG, NO_DISP},
    {0, 0, 0, ANY, NO_DISP}
  };
