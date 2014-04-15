/*
** tab_sym.c for tab_sym in /home/marcha_j//test/c/ftrace
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Jun 18 17:06:27 2012 hugo marchadier
** Last update Fri Jun 22 15:48:10 2012 hugo marchadier
*/

#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <elf.h>
#include <libelf.h>

#include "xfct.h"
#include "tab_sym.h"
#include "list.h"
#include "ncurse.h"

int	init_lib_elf(pid_t pid, Elf **elf)
{
  int	fd;
  char	*path;

  errno = 0;
  if (asprintf(&path, "/proc/%u/exe", (unsigned int)pid) == -1
      || path == NULL || (fd = open(path, O_RDONLY)) == -1)
    {
      fprintf(stderr, "Error: open pid: %u failed, %s.\n",
	      (unsigned int)pid, strerror(errno));
      return (-1);
    }
  free(path);
  if (elf_version(EV_CURRENT) == EV_NONE)
    {
      fprintf(stderr, "ELF library init failed : %s.\n" , elf_errmsg(-1));
      return (-1);
    }
  if ((*elf = elf_begin(fd, ELF_C_READ, NULL)) == NULL)
    {
      fprintf(stderr, "file is not an ELF binary, %s.\n", elf_errmsg(-1));
      return (-1);
    }
  return (fd);
}

int	init_var_elf(Elf *elf, Elf_Data **data,
		     Elf64_Ehdr **ehdr, Elf_Scn **scn)
{
  if (((*ehdr = elf64_getehdr(elf)) == NULL) ||
      ((*scn = elf_getscn(elf, (*ehdr)->e_shstrndx)) == NULL) ||
      ((*data = elf_getdata(*scn, NULL)) == NULL))
    {
      fprintf(stderr, "Error: init var elf failed, %s.\n", elf_errmsg(-1));
      return (-1);
    }
  return (1);
}

static int	cond_keep_symbol(Elf64_Sym *sym)
{
  return (sym->st_name != 0 && sym->st_value != 0);
}

static int	find_size_tab(Elf64_Sym *sym, Elf64_Sym *lastsym)
{
  int	count;

  count = 0;
  while (sym < lastsym)
    {
      if (cond_keep_symbol(sym))
	count++;
      sym++;
    }
  return (count);
}

static t_sym	**create_tab_sym(Elf *elf, Elf_Data *data, Elf64_Shdr *shdr)
{
  char		*name;
  Elf64_Sym	*sym;
  Elf64_Sym	*lastsym;
  int		size;
  t_sym		**tab;
  int		i;

  i = 0;
  sym = (Elf64_Sym*)data->d_buf;
  lastsym = (Elf64_Sym*)((char*)data->d_buf + data->d_size);
  if ((size = find_size_tab(sym, lastsym)) == 0)
    return (NULL);
  tab = xmalloc(sizeof(*tab) * (size + 1));
  while (sym < lastsym)
    {
      if (cond_keep_symbol(sym))
	{
	  tab[i] = xmalloc(sizeof(**tab));
	  name = elf_strptr(elf, shdr->sh_link , (size_t)sym->st_name);
	  if (!name)
	    {
	      fprintf(stderr, "Error: elf_strptr failed, %s.\n",
		      elf_errmsg(elf_errno()));
	      return (NULL);
	    }
	  if ((tab[i]->name = strdup(name)) == NULL)
	    {
	      fprintf(stderr, "Error: strdup failed.\n");
	      return (NULL);
	    }
	  tab[i]->addr = (unsigned int)sym->st_value;
	  aff_tab_sym(tab[i]->name, tab[i]->addr, C_GREEN);
	  i++;
	}
      sym++;
    }
  tab[i] = NULL;
  return (tab);
}

static t_sym**	find_tab_sym(Elf *elf)
{
  int		i;
  Elf_Scn	*scn;
  Elf64_Shdr	*shdr;
  Elf_Data	*data;
  Elf64_Shdr	*save;

  i = 1;
  scn = NULL;
  save = NULL;
  while ((scn = elf_nextscn(elf, scn)))
    {
      if ((shdr = elf64_getshdr(scn)) == NULL)
	{
	  fprintf(stderr, "Error getshdr failed, %s.\n", elf_errmsg(-1));
	  return (NULL);
	}
      if (shdr->sh_type == SHT_SYMTAB)
	{
	  data = NULL;
	  if ((data = elf_getdata(scn, data)) == 0 || data->d_size == 0)
	    {
	      fprintf(stderr, "Error: No data in symbol table, %s\n", elf_errmsg(-1));
	      return (NULL);
	    }
	  return (create_tab_sym(elf, data, shdr));
	}
      i = i + 1;
    }
  fprintf(stderr, "Error: no symbol's tab.\n");
  return (NULL);
}

t_sym	**tab_sym(pid_t pid)
{
  int		fd;
  Elf		*elf;
  Elf64_Ehdr	*ehdr;
  Elf_Scn	*scn;
  Elf_Data	*data;
  t_sym		**tab;

  aff_tab_header("Static Symbole Table", C_GREEN);
  if ((fd = init_lib_elf(pid, &elf)) == -1)
    {
      fprintf(stderr, "Error: failed to init lib elf.\n");
      aff_tab_footer();
      return (NULL);
    }
  if (init_var_elf(elf, &data, &ehdr, &scn) == -1)
    {
      fprintf(stderr, "Error: failed to init var elf.\n");
      aff_tab_footer();
      return (NULL);
    }
  if ((tab = find_tab_sym(elf)) == NULL)
    {
      fprintf(stderr, "Error: failed to find symbol's tab.\n");
      aff_tab_footer();
      return (NULL);
    }
  elf_end(elf);
  close(fd);
  aff_tab_footer();
  return (tab);
}

void	free_tab_sym(t_sym **tab)
{
  int	i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      if (tab[i]->name != NULL)
	free(tab[i]->name);
      free(tab[i]);
      i = i + 1;
    }
  if (tab != NULL)
    free(tab);
}

int	find_addr_in_tab_sym(t_sym **tab, unsigned int addr)
{
  int	i;

  i = 0;
  while (tab != NULL && tab[i] != NULL)
    {
      if (tab[i]->addr == addr)
	return (i);
      i = i + 1;
    }
  return (-1);
}
