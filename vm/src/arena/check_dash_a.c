/*
** check_dash_a.c for  in /home/ugolaf/delivery/CPE_2016_corewar/vm/src/arena
** 
** Made by ugo lafaille
** Login   <ugolaf@epitech.net>
** 
** Started on  Sun Mar 19 17:39:52 2017 ugo lafaille
** Last update Mon Mar 27 17:44:59 2017 ugo lafaille
*/

#include <stdio.h>
#include <unistd.h>
#include "champ.h"
#include "vm.h"
#include "my.h"

int	first_check_dash_a(t_champ *champ)
{
  while (champ != NULL)
    {
      if (champ->load_adress != -1)
	return (1);
      champ = champ->next;
    }
  return (0);
}

int	place_no_dash_a(t_champ *champ, char *arena)
{
  int	placed;
  int	pos;

  placed = 0;
  pos = 0;
  while (champ)
    {
      if (champ->load_adress == -1)
	{
	  if ((pos = find_pos(arena, champ->size, placed)) == ERR)
	    return (ERR);
	  put_in_arena(champ->content, &arena[pos], champ->size);
	  champ->load_adress = pos;
	}
      placed += champ->size;
      champ = champ->next;
    }
  return (0);
}

int	place_champs(t_champ *champ, char *arena)
{
  if (first_check_dash_a(champ) == 0)
    {
      if (put_champ_address(champ, arena) == ERR)
	return (ERR);
    }
  else
    {
      if (place_each_dash_a(champ, arena) == ERR)
	return (ERR);
      if (place_no_dash_a(champ, arena) == ERR)
	return (ERR);
    }
  return (0);
}
