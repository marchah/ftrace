/*
** decode_sib.h for decode_sib.h in /home/marcha_j//test/c/ftrace
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Thu May 31 16:42:32 2012 hugo marchadier
** Last update Thu May 31 17:40:55 2012 hugo marchadier
*/

#ifndef DECODE_SIB_H_
# define DECODE_SIB_H_

unsigned long	decode_sib(pid_t pid, struct user_regs_struct *r,
			   eSTATUS *status, unsigned long instr);

typedef struct	s_sib
{
  unsigned long ss;
  unsigned long base;
  unsigned long index;
  eTACHE	tache;
  unsigned int	mult;
}		t_sib;


# endif /* DECODE_SIB_H_ */
