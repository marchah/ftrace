/*
** fct_annexe.h for fct_annexe in /home/marcha_j//svn/c/ftrace-2015-2014s-marcha_j
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Fri Jun 22 14:21:55 2012 hugo marchadier
** Last update Tue Jun 26 16:30:40 2012 hugo marchadier
*/

#ifndef FCT_ANNEXE_H_
# define FCT_ANNEXE_H_

void	init_info(t_info *info, pid_t pid);
void	print_graph_sym(t_list *sym, int pos, t_info *info);
void	xopen(char *path, t_info *info);
void	xwrite(char *msg, t_info *info);
void	xclose(t_info *info);

#endif /* !FCT_ANNEXE_H_ */
