/*
** put_label_in_link.c for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/asm/parsing_type
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Thu Mar  2 09:41:27 2017 PierreL
** Last update Wed Mar 15 20:23:47 2017 PierreL
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "asm.h"
#include "arg.h"

t_arg		*new_link(t_arg *ctrl)
{
  t_arg		*new_link;

  if ((new_link = malloc(sizeof(t_arg))) == NULL)
    return (NULL);
  new_link->value = INIT_VALUE;
  new_link->type = INIT_VALUE;
  new_link->next = NULL;
  if (ctrl != NULL)
    ctrl->next = new_link;
  else
    return (new_link);
  return (ctrl);
}

int	is_it_on_array(char *str, char car)
{
  int	i;

  i = 0;
  if (str != NULL)
    while (str[i] != END_OF_STRING)
      if (str[i++] == car)
	return (EXIT_OK);
  return (EXIT_FAILURE);
}

int	is_good_label(char *str, char *is)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] == DIRECT_CHAR || str[i] == LABEL_CHAR)
    i++;
  while (str[i] != 0 && is[j] != 0)
    if (str[i++] != is[j++])
      return (EXIT_FAILURE);
  if (str[i] == 0 && is[j] == 0)
    return (EXIT_OK);
  return (EXIT_FAILURE);
}

int		put_label_in_link(t_labels *ptr, char *name,
				  int address, int *err)
{
  t_labels	*lab;

  lab = ptr;
  if (lab == NULL || name == NULL)
    return ((*err = EXIT_ERROR));
  else if (lab->name == NULL)
    return ((*err = EXIT_ERROR));
  while (lab != NULL)
    {
      if (is_good_label(name, lab->name) == EXIT_OK)
	return (lab->address - address);
      lab = lab->next;
    }
  return ((*err = EXIT_ERROR));
}
