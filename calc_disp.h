/*
** calc_disp.h for calc_disp in /home/marcha_j//test/c/ftrace
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Thu May 31 16:13:16 2012 hugo marchadier
** Last update Fri Jun 22 14:43:48 2012 hugo marchadier
*/

#ifndef	CALC_DISP_H_
# define CALC_DISP_H_

typedef enum    e_pos_disp
  {
    NO_SIB = 3,
    WITH_SIB = 4
  }             ePosDisp;

unsigned long	check_disp(eSTATUS *status, eDISP disp,
			   eTACHE tache, unsigned long instr);

# endif /* CALC_DISP_H_ */
