/*
** fct_annexe.c for fct_annexe in /home/marcha_j//svn/c/ftrace-2015-2014s-marcha_j
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Fri Jun 22 14:20:50 2012 hugo marchadier
** Last update Tue Jun 26 17:31:06 2012 hugo marchadier
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "ftrace.h"
#include "dyntab_sym.h"
#include "xfct.h"

void	xwrite(char *msg, t_info *info)
{
  if (info->fd != -1)
    write(info->fd, msg, strlen(msg));
}

void	xopen(char *path, t_info *info)
{
  if ((info->fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
      return ;
  xwrite("graph FTRACE {\n", info);
}

void	xclose(t_info *info)
{
  if (info->fd != -1)
    {
      xwrite("}\n", info);
      close(info->fd);
    }
}

void	print_graph_sym(t_list *sym, int pos, t_info *info)
{
  int		i = 0;

  if (pos != 0 && sym != NULL)
    {
      while (sym != NULL && i != pos)
	{
	  i++;
	  sym = sym->next;
	}
      if (sym != NULL && sym->prev != NULL && sym->prev->data != NULL
	  && sym->data != NULL)
	{
	  xwrite(sym->prev->data->name, info);
	  xwrite(" -- ", info);
	  xwrite(sym->data->name, info);
	  xwrite(";\n", info);
	}
    }
}

void	init_info(t_info *info, pid_t pid)
{
  info->pid = pid;
  info->save_rip = NULL;
  info->status_call = NONE;
  info->tab = tab_sym(pid);
  info->dyntab = tab_dynsym(pid);
  xopen(GRAPH_NAME, info);
}
