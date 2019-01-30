/*
** put_type_in_link.c for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/parsing_type
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Tue Feb 28 14:24:31 2017 PierreL
** Last update Fri Mar 31 15:47:12 2017 PierreL
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "arg.h"
#include "asm.h"
#include "op.h"

int		put_value_in_link(t_labels *lab, char *str,
				  int address, int *err)
{
  int		returned;
  int		i;

  i = 0;
  if ((is_it_on_array(str, LABEL_CHAR)) == EXIT_OK)
    {
      returned = put_label_in_link(lab, str, address, err);
      if (*err == EXIT_ERROR)
	return ((*err = EXIT_ERROR));
      return (returned);
    }
  while (((str[i] < VAL_MIN
	   || str[i] > VAL_MAX) && str[i] != END_OF_STRING)
	 && str[i] != NEG_OPERANT)
    i++;
  returned = my_getnbr(&str[i]);
  return (returned);
}

t_arg		*put_arg_in_link(t_labels *lab, char *str,
				 t_arg *ctrl, int address)
{
  int		err;

  ctrl->type = 0;
  err = 0;
  if (str[0] == INDIC_REG)
    ctrl->type = TYPE_REG;
  else if (str[0] == DIRECT_CHAR)
    ctrl->type = TYPE_DIRECT;
  else if (((str[0] >= INDIC_INDIRECT_S
	     && str[0] <= INDIC_INDIRECT_I)
	    || str[0] == NEG_OPERANT)
	   || str[0] == LABEL_CHAR)
    ctrl->type = TYPE_INDIRECT;
  ctrl->value = put_value_in_link(lab, str, address, &err);
  if (err == EXIT_ERROR)
    return (NULL);
  return (ctrl);
}

void	free_double_tab(char **tabl_str)
{
  int	i;

  i = 0;
  while (tabl_str[i] != END_OF_STRING)
    free(tabl_str[i++]);
  free(tabl_str);
}

t_arg		*pars_arg(t_labels *lab, char *tabl, int address)
{
  int		i;
  t_arg		*first;
  t_arg		*ctrl;
  char		**str;

  i = 0;
  first = NULL;
  if (((str = my_str_to_wordtab(tabl, SEPARATOR_CHAR)) == NULL)
      || ((first = new_link(NULL)) == NULL))
    return (free_struct(first, NULL));
  ctrl = first;
  while (str[i] != NULL)
    {
      if ((ctrl = put_arg_in_link(lab, str[i], ctrl, address)) == NULL)
	return (free_struct(first, str));
      if (str[++i] != NULL)
	if ((ctrl = new_link(ctrl)) == NULL)
	  return (free_struct(first, str));
      ctrl = ctrl->next;
    }
  if (i > MAX_ARGS_NUMBER)
    return (free_struct(first, str));
  free_double_tab(str);
  return (first);
}
