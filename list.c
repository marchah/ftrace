/*
** list.c for  in /home/karque_f//c/zappy-2015-2014s-marcha_j/Serveur
** 
** Made by fabien karquel
** Login   <karque_f@epitech.net>
** 
** Started on  Mon Jun  4 15:22:36 2012 fabien karquel
** Last update Mon Jun 18 14:49:53 2012 hugo marchadier
*/

#include <unistd.h>
#include <stdlib.h>

#include "list.h"
#include "tab_sym.h"
#include "xfct.h"

static t_list	*init_new_maillon(t_sym *data)
{
  t_list	*new;

  new = xmalloc(sizeof(*new));
  new->data = data;
  new->next = NULL;
  new->prev = NULL;
  return (new);
}

t_list		*add_maillon(t_list *list, t_sym *data)
{
  t_list	*new;
  t_list	*tmp;

  new = init_new_maillon(data);
  if (!list)
    return (new);
  tmp = list;
  while (tmp->next)
    tmp = tmp->next;
  new->prev = tmp;
  tmp->next = new;
  return (list);
}

t_list		*remove_maillon(t_list *list, t_list *to_rem)
{
  t_list	*tmp;

  tmp = list;
  if (tmp == NULL || to_rem == NULL)
      return (tmp);
  if (to_rem->prev == NULL && to_rem->next == NULL)
    {
      free(to_rem);
      return (NULL);
    }
  if (to_rem->prev != NULL)
    to_rem->prev->next = to_rem->next;
  if (to_rem->next != NULL)
    {
      if (to_rem->prev != NULL)
	to_rem->next->prev = to_rem->prev;
      else
	{
	  to_rem->next->prev = NULL;
	  tmp = to_rem->next;
	}
    }
  free(to_rem);
  return (tmp);
}

