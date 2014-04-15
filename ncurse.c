/*
** ncurse.c for ncurse in /home/marcha_j//svn/c/ftrace-2015-2014s-marcha_j
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Fri Jun 22 15:08:44 2012 hugo marchadier
** Last update Tue Jun 26 17:47:49 2012 hugo marchadier
*/

#include <stdio.h>
#include <string.h>
#include <curses.h>

#include "ncurse.h"

void	aff_tab_sym(char *name, unsigned int addr, char *COLOR)
{
  color(COLOR);
  printf("  %x", addr);
  color(REINIT);
  printf("   ->\t");
  color(COLOR);
  printf("  %s\n", name);
  color(REINIT);
}

void	aff_tab_header(char *name, char *COLOR)
{
  printf("|-------------------------------|\n|\t");
  color(COLOR);
  printf("%s", name);
  color(REINIT);
  printf("\t|\n|-------------------------------|\n");
}

void	aff_tab_footer()
{
  printf("|-------------------------------|\n\n\n");
}

void	aff_sym(char *sym, char *C_COLOR, char *B_COLOR, int pos)
{
  int	i;

  i = 0;
  while (i < pos)
    {
      if (i >= (int)(SIZE_MAX_Y - strlen(sym) - 2))
	break;
      printf(" ");
      i++;
    }
  
  color(C_COLOR);
  color(B_COLOR);
  printf("%s", sym);
  color(REINIT);
  printf("\n");
}

void	aff_ret(char *sym, char *C_COLOR, char *B_COLOR, int pos)
{
  int	i;

  i = 0;
  while (i < pos && sym != NULL)
    {
      if (i >= (int)(SIZE_MAX_Y - strlen(sym) - 2))
	break;
      printf(" ");
      i++;
    }
  color(C_COLOR);
  color(B_COLOR);
  if (sym != NULL)
    printf("RET IN %s", sym);
  else
    printf("RET");
  color(REINIT);
  printf("\n");
}

