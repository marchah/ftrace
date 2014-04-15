/*
** decode_mode_rm.h for decode_mode_rm in /home/marcha_j//test/c/ftrace
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Thu May 31 16:26:02 2012 hugo marchadier
** Last update Fri Jun 22 14:41:06 2012 hugo marchadier
*/

#ifndef DECODE_MODE_RM_H_
# define DECODE_MODE_RM_H_

typedef enum	e_tache
  {
    ANY = 0,
    NOTHING,
    PTRACE,
    REG,
    SIB = 4
  }		eTACHE;

typedef enum    e_disp
  {
    NO_DISP = 0,
    DISP8 = 1,
    DISP32 = 4
  }             eDISP;

typedef struct	s_rm
{
  unsigned long mod;
  unsigned long reg;
  unsigned long rm;
  eTACHE	tache;
  eDISP		disp;
}		t_rm;

unsigned long	decode_mode_rm(struct user_regs_struct *r, eSTATUS *status,
			       t_prefix prefix, t_info *info);

# endif /* DECODE_MODE_RM_H_ */
