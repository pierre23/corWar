/*
** print_arg.c for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/asm/src/parsing_type
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Mon Mar  6 11:11:25 2017 PierreL
** Last update Mon Mar  6 14:57:08 2017 Sylvain Lefevre
*/

#include <stdio.h>
#include <unistd.h>
#include "asm.h"
#include "arg.h"
#include "my.h"

int	arg_len(t_arg *ctrl)
{
  int	i;

  i = 0;
  while (ctrl != NULL)
    {
      i += 1;
      ctrl = ctrl->next;
    }
  return (i);
}

void	print_arg(t_arg *ctrl, int cmd_id)
{
  int	caca;

  if (arg_len(ctrl) > 1 || cmd_id == AFF_ID)
    find_nbr_arg(ctrl);
  while (ctrl != NULL)
    {
      if (ctrl->type == 1)
	caca = 1;
      else if (ctrl->type == 2 && op_tab[cmd_id].nbr_cycles < 20)
	caca = DIR_SIZE;
      else
	caca = IND_SIZE;
      put_hex(ctrl->value, caca);
      ctrl = ctrl->next;
    }
}
