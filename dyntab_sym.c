/*
** dyntab_sym.c for dyntab_sym in /home/marcha_j//test/c/ftrace
** 
** Made by hugo marchadier
** Login   <marcha_j@epitech.net>
** 
** Started on  Mon Jun 18 17:03:29 2012 hugo marchadier
** Last update Fri Jun 22 15:47:41 2012 hugo marchadier
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

static t_list	*solve_dym_link(Elf64_Shdr *shdr, Elf_Scn *scn,
				unsigned int offset, t_list *list_name)
{
  Elf64_Rel	*rel;
  int		size;
  Elf_Data	*data;
  t_list	*tmp;
  int		i;

  size = 0;
  data = NULL;
  i = 0;
  if ((data = elf_getdata(scn, NULL)) == 0 || data->d_size == 0)
    {
      fprintf(stderr, "Error: No data in symbol table, %s\n", elf_errmsg(-1));
      return (list_name);
    }
  offset += 6;
  tmp = list_name;
  while (shdr != NULL && size < (int)shdr->sh_size)
    {
      if (tmp == NULL)
	{
	  fprintf(stderr, "Error: .plt and .rel(a).plt info isn't the same.\n");
	  return (list_name);
	}
      rel = (Elf64_Rel*)shdr->sh_addr;
      if (i != 0)
	{
	  if (tmp->data->addr == (shdr->sh_addr + size + offset + 6))
	    {
	      tmp->data->addr = (unsigned int)(shdr->sh_addr + size);
	      aff_tab_sym(tmp->data->name, tmp->data->addr, C_YELLOW);
	      tmp = tmp->next;
	    }
	  else
	    {
	      fprintf(stderr, "Error: .plt and .rel(a).plt info isn't the same.\n");
	      return (list_name);
	    }
	}
      offset -= 8;
      size += shdr->sh_entsize;
      i++;
    }
  return (list_name);
}

static t_list	*add_rel(Elf *elf, Elf64_Shdr *dynshdr, Elf_Data *dyndata,
			 Elf64_Shdr *shdr, Elf_Data *data, t_list *list_name)
{
  int		size;
  Elf64_Rel	*rel;
  t_sym		*tmp;
  char		*symname;
  Elf64_Sym	*sym;

  size = 0;
  while (shdr != NULL && size < (int)shdr->sh_size)
    {
      rel = data->d_buf + size;
      if (ELF64_R_TYPE(rel->r_info) == R_386_JMP_SLOT)
	{
	  sym = dyndata->d_buf + (ELF64_R_SYM(rel->r_info) * dynshdr->sh_entsize);
	  if ((symname = elf_strptr(elf, dynshdr->sh_link, sym->st_name)) != NULL)
	    {
	      tmp = xmalloc(sizeof(*tmp));
	      tmp->addr = rel->r_offset;
	      tmp->name = strdup(symname);
	      list_name = add_maillon(list_name, tmp);
	    }
	}
      size += shdr->sh_entsize;
    }
  return (list_name);
}

static t_list	*add_rela(Elf *elf, Elf64_Shdr *dynshdr, Elf_Data *dyndata,
			 Elf64_Shdr *shdr, Elf_Data *data, t_list *list_name)
{
  int		size;
  Elf64_Rela	*rela;
  t_sym		*tmp;
  char		*symname;
  Elf64_Sym	*sym;

  size = 0;
  while (shdr != NULL && size < (int)shdr->sh_size)
    {
      rela = data->d_buf + size;
      if (ELF64_R_TYPE(rela->r_info) == R_386_JMP_SLOT)
	{
	  sym = dyndata->d_buf + (ELF64_R_SYM(rela->r_info) * dynshdr->sh_entsize);
	  if ((symname = elf_strptr(elf, dynshdr->sh_link, sym->st_name)) != NULL)
	    {
	      tmp = xmalloc(sizeof(*tmp));
	      tmp->addr = rela->r_offset;
	      tmp->name = strdup(symname);
	      list_name = add_maillon(list_name, tmp);
	    }
	}
      size += shdr->sh_entsize;
    }
  return (list_name);
}

static t_list	*solve_dym_link_name(Elf64_Shdr *shdr, Elf_Scn *scn,
				     Elf *elf, t_list *list_name)
{
  Elf_Data	*data;
  Elf_Scn	*linked;
  Elf64_Shdr	*dynshdr;
  Elf_Data	*dyndata;

  data = NULL;
  if ((data = elf_getdata(scn, NULL)) == 0 || data->d_size == 0)
    {
      fprintf(stderr, "Error: No data in symbol table, %s\n", elf_errmsg(-1));
      return (list_name);
    }
  if ((linked = elf_getscn(elf, shdr->sh_link)) == NULL
      || (dynshdr = elf64_getshdr(linked)) == NULL
      || (dyndata = elf_getdata(linked, NULL)) == NULL)
    {
      fprintf(stderr, "Error recup info rel(a).plt\n");
      return (list_name);
    }
  if (shdr->sh_type == SHT_REL)
    return (add_rel(elf, dynshdr, dyndata, shdr, data, list_name));
  else if (shdr->sh_type == SHT_RELA)
    return (add_rela(elf, dynshdr, dyndata, shdr, data, list_name));
  return (list_name);
}

static t_list*	find_dyntab_sym(Elf *elf)
{
  int		i;
  Elf_Scn	*scn;
  Elf64_Shdr	*shdr;
  Elf_Data	*data;
  Elf64_Shdr	*save;
  t_list	*list_name;
  size_t	ndx;

  i = 1;
  scn = NULL;
  save = NULL;
  list_name = NULL;
  while ((scn = elf_nextscn(elf, scn)))
    {
      if ((shdr = elf64_getshdr(scn)) == NULL)
	{
	  fprintf(stderr, "Error getshdr failed, %s.\n", elf_errmsg(-1));
	  return (NULL);
	}
      elf_getshdrstrndx(elf, &ndx);
      if (strcmp(".plt", elf_strptr(elf, ndx, shdr->sh_name)) == 0)
	{
	  data = NULL;
	  if ((data = elf_getdata(scn, data)) == NULL || data->d_size == 0)
	    {
	      fprintf(stderr, "Error: No data in symbol table, %s\n", elf_errmsg(-1));
	      return (NULL);
	    }
	  Elf64_Rel	*rel = data->d_buf;
	  list_name = solve_dym_link(shdr, scn, rel->r_info, list_name);
	}
      if (strcmp(".rel.plt", elf_strptr(elf, ndx, shdr->sh_name)) == 0
	  || strcmp(".rela.plt", elf_strptr(elf, ndx, shdr->sh_name)) == 0)
	{
	  save = shdr;
	  list_name = solve_dym_link_name(save, scn, elf, list_name);
	}
      i = i + 1;
    }
  return (list_name);
}

t_list	*tab_dynsym(pid_t pid)
{
  int		fd;
  Elf		*elf;
  Elf64_Ehdr	*ehdr;
  Elf_Scn	*scn;
  Elf_Data	*data;
  t_list	*dyntab;

  aff_tab_header("Dynamic Symbole Table", C_YELLOW);
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
  if ((dyntab = find_dyntab_sym(elf)) == NULL)
    {
      fprintf(stderr, "Error: failed to find symbol's dyntab.\n");
      aff_tab_footer();
      return (NULL);
    }
  aff_tab_footer();
  elf_end(elf);
  close(fd);
  return (dyntab);
}

char	*find_name_dyntab(t_list *dyntab, unsigned int addr)
{
  while (dyntab != NULL)
    {
      if (dyntab->data != NULL && dyntab->data->addr == addr)
	return (dyntab->data->name);
      dyntab = dyntab->next;
    }
  return (NULL);
}

void	free_dyntab_sym(t_list *tab)
{
  while (tab != NULL)
    {
      if (tab->data != NULL)
	{
	  if (tab->data->name != NULL)
	    free(tab->data->name);
	  free(tab->data);
	}
      tab = remove_maillon(tab, tab);
    }
}
