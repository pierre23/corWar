/*
** put_champ.c for  in /home/ugolaf/delivery/CPE_2016_corewar/vm/src/arena
** 
** Made by ugo lafaille
** Login   <ugolaf@epitech.net>
** 
** Started on  Fri Mar 10 11:53:02 2017 ugo lafaille
** Last update Thu Mar 30 15:45:00 2017 ugo lafaille
*/

#include <stdio.h>
#include <unistd.h>
#include "my.h"
#include "champ.h"
#include "vm.h"
#include "errors.h"

int		calc_space_between_champ(t_champ *champ)
{
  unsigned int	total_size;
  int		nb_champs;

  total_size = 0;
  nb_champs = 0;
  while (champ != NULL)
    {
      total_size = total_size + champ->size;
      nb_champs += 1;
      champ = champ->next;
    }
  if (total_size > MEM_SIZE)
    {
      my_fputstr(2, ERR_FORMAT, TOO_BIG, "");
      return (-1);
    }
  if (nb_champs == 1)
    return (0);
  if (nb_champs == 2)
    return (((MEM_SIZE - total_size) / (nb_champs - 1)) / 2);
  return ((MEM_SIZE - total_size) / (nb_champs));
}

int	put_in_arena(char *buffer, char *arena, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      arena[i % MEM_SIZE] = buffer[i];
      i += 1;
    }
  return (0);
}

int	put_champ_address(t_champ *champ, char *arena)
{
  int	space;
  int	i;
  int	placed;

  placed = 0;
  if ((space = calc_space_between_champ(champ)) == -1)
    return (-1);
  i = 0;
  while (champ)
    {
      champ->load_adress = space * i + placed;
      put_in_arena(champ->content, &arena[space * i + placed], champ->size);
      placed += champ->size;
      champ = champ->next;
      i += 1;
    }
  return (0);
}
