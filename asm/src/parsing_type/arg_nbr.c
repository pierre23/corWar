/*
** arg_nbr.c for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/asm/parsing_type
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Tue Feb 28 19:59:43 2017 PierreL
** Last update Fri Mar 31 15:43:57 2017 PierreL
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "arg.h"

int	count_link_nbr(t_arg *ctrl)
{
  int	i;

  i = INIT_VALUE;
  while (ctrl != NULL)
    {
      ctrl = ctrl->next;
      i++;
    }
  return (i);
}

char	find_nbr_arg(t_arg *ctrl)
{
  char	ret;
  int	i;

  ret = INIT_VALUE;
  i = INIT_VALUE;
  while (ctrl != NULL)
    {
      ret = ret << ONE_TYPE;
      ret += ctrl->type;
      ctrl = ctrl->next;
      i += ONE_TYPE;
    }
  if (i != SIZE_OF_OCT)
    ret = ret << (SIZE_OF_OCT - i);
  print_fd(ret, 0);
  return (ret);
}

void	*free_struct(t_arg *ctrl, char **tabl)
{
  int	i;
  t_arg *pos;

  i = 0;
  while (ctrl != NULL)
    {
      pos = ctrl->next;
      free(ctrl);
      ctrl = pos;
    }
  if (tabl != NULL)
    {
      while (tabl[i] != NULL)
	free(tabl[i++]);
      free(tabl);
    }
  return (NULL);
}
