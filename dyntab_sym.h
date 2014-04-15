/*
** dyntab_sym.h for dyntab in /home/marcha_j//test/c/ftrace
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Jun 18 17:14:10 2012 hugo marchadier
** Last update Mon Jun 18 17:14:57 2012 hugo marchadier
*/

#ifndef DYNTAB_SYM_H_
# define DYNTAB_SYM_H_

t_list	*tab_dynsym(pid_t pid);
char	*find_name_dyntab(t_list *dyntab, unsigned int addr);
void	free_dyntab_sym(t_list *tab);

#endif /* !DYNTAB_SYM_H_ */
