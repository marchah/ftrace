/*
** ncurse_legend.c for ncurse_legend in /home/marcha_j//svn/c/ftrace-2015-2014s-marcha_j
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Fri Jun 22 17:40:08 2012 hugo marchadier
** Last update Fri Jun 22 17:51:14 2012 hugo marchadier
*/

#include <stdio.h>

#include "ncurse.h"

static void	aff_legende_ret()
{
  printf("|\tRETURN\t|\t");
  color(REINIT);
  color(B_BLUE);
  color(C_RED);
  printf("return without argument(C3 or CB)");
  color(REINIT);
  printf("\t");
  color(B_BLUE);
  color(C_WHITE);
  printf("return with argument(C2 or CA)");
  color(REINIT);
  color(HIGH_DENSITY);
  printf("\t     |\n");
}

static void	aff_legende_syscall()
{
  printf("|\tSYSCALL\t|\t");
  color(REINIT);
  color(B_RED);
  color(C_WHITE);
  printf("syscall");
  color(REINIT);
  printf("\t\t\t\t\t");
  color(B_RED);
  color(C_BLACK);
  printf("syscall signal");
  color(REINIT);
  color(HIGH_DENSITY);
  printf("\t\t\t     |\n");
}

static void	aff_legende_call()
{
  printf("|\tCALL\t|\t");
  color(REINIT);
  color(B_WHITE);
  color(C_BLUE);
  printf("call relatif(E8)");
  color(REINIT);
  printf("\t\t\t");
  color(B_WHITE);
  color(C_BLACK);
  printf("call absolute indirect(FF/2 or FF/3)");
  color(REINIT);
  color(HIGH_DENSITY);
  printf(" |\n");
}

static void	aff_border()
{
  int	i;

  i = 0;
  color(HIGH_DENSITY);
  printf("|");
  while (i != SIZE_BORDER)
    {
      printf("-");
      i++;
    }
  printf("|\n");
}

void	aff_legende()
{
  aff_border();
  printf("|\t\t\t\t\tLEGEND\t\t\t\t\t\t\t     |\n");
  aff_border();
  aff_legende_syscall();
  aff_border();
  aff_legende_call();
  aff_border();
  aff_legende_ret();
  aff_border();
  color(REINIT);
  printf("\n\n\n");
}
