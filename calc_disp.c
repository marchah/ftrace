/*
** calc_disp.c for calc_disp.c in /home/marcha_j//test/c/ftrace
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Thu May 31 16:12:06 2012 hugo marchadier
** Last update Fri Jun 22 14:43:28 2012 hugo marchadier
*/

#include <stdio.h>

#include <unistd.h>

#include "ftrace.h"
#include "decode_mode_rm.h"
#include "calc_disp.h"

static unsigned long	calc_disp(int nb_octet, ePosDisp pos,
				  unsigned long instr)
{
  unsigned long	disp;

  if (nb_octet == 1)
    disp = ((instr >> (pos * 4)) & 0xf);
  else
    disp = ((instr >> (pos * 4)) & 0xffff);
  return (disp);
}

unsigned long	check_disp(eSTATUS *status, eDISP disp, eTACHE tache,
			   unsigned long instr)
{
  if (disp == NO_DISP)
    return (0);
  else if (disp == DISP8 || disp == DISP32)
    return ((tache == SIB) ? calc_disp(disp, WITH_SIB, instr)
	    : calc_disp(disp, NO_SIB, instr));
  *status = ERROR;
  printf("Error: unknow disp.\n");
  return (0);
}
