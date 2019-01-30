/*
** put_arg_in_link.c for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/vm/src/parsing_arg
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Thu Mar  9 13:08:22 2017 PierreL
** Last update Fri Mar 31 16:39:38 2017 PierreL
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "op.h"
#include "errors.h"
#include "my_vm_ar.h"

t_champ		*new_link(t_champ *befor)
{
  t_champ	*new;

  if ((new = malloc(sizeof(t_champ))) == NULL)
    return (NULL);
  new->file_name = NULL;
  new->content = NULL;
  new->prog_nbr = DEFAULT_VALUE;
  new->load_adress = DEFAULT_VALUE;
  new->next = NULL;
  befor->next = new;
  befor = befor->next;
  return (befor);
}

int		my_put_dump(int *dump, char **av)
{
  if (my_strcmp(av[1], DUMP_FLAG) == EXIT_OK)
    {
      if (str_isnum(av[2]) == EXIT_KO)
	{
	  my_fputstr(2, ERR_FORMAT, BAD_DUMP_NBR, "");
	  return (EXIT_FAILURE);
	}
      *dump = my_getnbr(av[2]);
      return (EXIT_FLAG);
    }
  else
    *dump = DEFAULT_DUMP;
  return (EXIT_OK);
}

t_champ		*put_arg_list(t_champ *first, char **av, int i)
{
  t_champ	*ctrl;

  ctrl = first;
  while (av[++i] != NULL)
    {
      if (my_strcmp(av[i], PROG_NBR_FLAG) == EXIT_OK)
	{
	  if ((ctrl = my_put_prog_nbr(first, ctrl, av[++i])) == NULL)
	    return (free_struct(first, NULL, NULL));
	}
      else if (my_strcmp(av[i], LOAD_ADR_FLAG) == EXIT_OK)
	{
	  if ((ctrl = my_put_load_adr(ctrl, av[++i])) == NULL)
	    return (free_struct(first, NULL, NULL));
	}
      else if (av[i][0] == CHAR_FLAG)
	return (free_struct(first, BAD_FLAG, av[i]));
      else if ((ctrl->file_name = av[i]))
	  if (av[i + 1] != NULL)
	    if (!(ctrl = new_link(ctrl)))
	      return (free_struct(first, NULL, NULL));
    }
  return (complet_nbr(first));
}

t_champ		*put_arg_in_link(char **av, int	*dump)
{
  int		i;
  int		ret;
  t_champ	*first;

  i = 1;
  if ((first = malloc(sizeof(t_champ))) == NULL)
    return (NULL);
  first->file_name = NULL;
  first->prog_nbr = DEFAULT_VALUE;
  first->load_adress = DEFAULT_VALUE;
  first->next = NULL;
  first->content = NULL;
  if (av[1] != NULL)
    {
      if ((ret = my_put_dump(dump, av)) == EXIT_FAILURE)
	return (free_struct(first, NULL, NULL));
      else if (ret == EXIT_FLAG)
	i = JUMP_DUMP_V;
    }
  if (put_arg_list(first, av, (i - 1)) == NULL)
    return (NULL);
  return (first);
}
