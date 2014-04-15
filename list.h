/*
** list.h for  in /home/karque_f//c/zappy-2015-2014s-marcha_j/Serveur
** 
** Made by fabien karquel
** Login   <karque_f@epitech.net>
** 
** Started on  Mon Jun  4 15:20:55 2012 fabien karquel
** Last update Mon Jun 18 14:50:40 2012 hugo marchadier
*/

#ifndef		LIST_H_
# define	LIST_H_

struct s_sym;

typedef struct	s_list
{
  struct s_sym	*data;
  struct s_list	*next;
  struct s_list	*prev;
}		t_list;

t_list		*add_maillon(t_list *list, struct s_sym *data);
t_list		*remove_maillon(t_list *list, t_list *to_rem);

#endif
