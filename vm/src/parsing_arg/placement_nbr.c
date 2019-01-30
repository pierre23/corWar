/*
** placement_nbr.c for  in /home/elodie.billiot/Corewar/CPE_2016_corewar/vm/src/parsing_arg
** 
** Made by Elodie Billiot
** Login   <elodie.billiot@epitech.net>
** 
** Started on  Fri Mar 31 12:58:15 2017 Elodie Billiot
** Last update Fri Mar 31 12:58:37 2017 Elodie Billiot
*/

#include <stdlib.h>
#include "my_vm_ar.h"
#include "errors.h"
#include "op.h"
#include "my.h"

t_champ         *complet_nbr_loop(t_champ *first, int i, t_champ *ctrl)
{
  while (numbr_is_ok(first, i) != EXIT_OK)
    i++;
  ctrl->prog_nbr = i;
  return (ctrl);
}

t_champ         *complet_nbr(t_champ *first)
{
  int           i;
  int           nbr_champ;
  t_champ       *ctrl;

  i = 1;
  ctrl = first;
  nbr_champ = 0;
  while (ctrl)
    {
      ctrl = ctrl->next;
      if (nbr_champ++ > MAX_CHAMP)
        return (free_struct(first, TOO_CHAMP, NULL));
    }
  if (nbr_champ == 1)
    return (free_struct(first, ONE_CHAMP, NULL));
  ctrl = first;
  while (ctrl)
    {
      if (ctrl->file_name == NULL)
        return (free_struct(first, MISS_FILE, NULL));
      if (ctrl->prog_nbr == DEFAULT_VALUE)
        complet_nbr_loop(first, i, ctrl);
      ctrl = ctrl->next;
    }
  return (first);
}
