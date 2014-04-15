/*
** tab_sym.h for tab_sym in /home/marcha_j//test/c/ftrace
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Wed May 23 15:36:06 2012 hugo marchadier
** Last update Mon Jun 18 17:13:46 2012 hugo marchadier
*/

#ifndef TAB_SYM_H_
# define TAB_SYM_H_

typedef struct s_sym
{
  char		*name;
  unsigned int	addr;
}		t_sym;

#include	<elf.h>
#include	<libelf.h>

int	init_lib_elf(pid_t pid, Elf **elf);
int	init_var_elf(Elf *elf, Elf_Data **data,
		     Elf64_Ehdr **ehdr, Elf_Scn **scn);
t_sym	**tab_sym(pid_t pid);
void	free_tab_sym(t_sym **tab);
int	find_addr_in_tab_sym(t_sym **tab, unsigned int addr);

# endif /* TAB_SYM_H_ */
