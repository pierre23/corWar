/*
** fonction_parsing_arg.c for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/vm/src/parsing_arg
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Thu Mar  9 15:01:49 2017 PierreL
** Last update Fri Mar 31 12:59:10 2017 Elodie Billiot
*/

#include <stdlib.h>
#include "my_vm_ar.h"
#include "errors.h"
#include "op.h"
#include "my.h"

t_champ		*my_put_prog_nbr(t_champ *first, t_champ *ctrl, char *str)
{
  if (str_isnum(str) == EXIT_KO)
    {
      my_fputstr(2, ERR_FORMAT, BAD_LOAD_NBR, "");
      return (NULL);
    }
  else if (ctrl->prog_nbr != DEFAULT_VALUE)
    {
      my_fputstr(2, ERR_FORMAT, FEW_PRG_NBR, "");
      return (NULL);
    }
  else if (numbr_is_ok(first, my_getnbr(str)) == EXIT_FAILURE)
    {
      my_fputstr(2, ERR_FORMAT, CHAMP_SAME_PL, "");
      return (NULL);
    }
  else if ((ctrl->prog_nbr = my_getnbr(str)) == EXIT_KO
	   || my_getnbr(str) > MAX_CHAMP)
    {
      my_fputstr(2, ERR_FORMAT, BAD_LOAD_NBR, "");
      return (NULL);
    }
  else
    return (ctrl);
}

t_champ		*my_put_load_adr(t_champ *ctrl, char *str)
{
  if (str_isnum(str) == EXIT_KO)
    {
      my_fputstr(2, ERR_FORMAT, BAD_ADDR, str, "");
      return (NULL);
    }
  if (ctrl->load_adress != DEFAULT_VALUE)
    {
      my_fputstr(2, ERR_FORMAT, TWO_LOAD_NBR, "");
      return (NULL);
    }
  if ((ctrl->load_adress = (my_getnbr(str) % MEM_SIZE)) < 0)
    {
      my_fputstr(2, ERR_FORMAT, BAD_ADDR, str, "");
      return (NULL);
    }
  return (ctrl);
}

int		numbr_is_ok(t_champ *first, int nbr)
{
  t_champ	*stock;

  stock = first;
  while (stock != NULL)
    {
      if (stock->prog_nbr == nbr)
	return (EXIT_FAILURE);
      stock = stock->next;
    }
  return (EXIT_OK);
}

void		*free_struct(t_champ *ctrl, char *msg, char *str)
{
  t_champ	*stock;

  if (msg != NULL)
    {
      if (str != NULL)
	my_fputstr(2, ERR_FORMAT, msg, str, "");
      else
	my_fputstr(2, ERR_FORMAT, msg, "");
    }
  if (ctrl != NULL)
    {
      while (ctrl != NULL)
	{
	  stock = ctrl->next;
	  free(ctrl);
	  ctrl = stock;
	}
    }
  return (NULL);
}
