/*
** action.c for  in /home/ugolaf/delivery/CPE_2016_corewar/vm/src/arena
** 
** Made by ugo lafaille
** Login   <ugolaf@epitech.net>
** 
** Started on  Tue Mar 21 10:51:55 2017 ugo lafaille
** Last update Thu Mar 30 15:45:27 2017 ugo lafaille
*/

#include <unistd.h>
#include "my.h"
#include "champ.h"
#include "vm.h"
#include "errors.h"

int     put_in_arena_dash_a(char *buffer, char *arena,
			    int size, t_champ *champ)
{
  int   i;

  i = 0;
  while (i < size)
    {
      if (arena[(champ->load_adress + i) % MEM_SIZE] != 0)
	{
	  my_fputstr(2, ERR_FORMAT, SAME_POS, "");
	  return (-1);
	}
      arena[(champ->load_adress + i) % MEM_SIZE] = buffer[i];
      i += 1;
    }
  return (0);
}

int     place_each_dash_a(t_champ *champ, char *arena)
{
  if (calc_space_between_champ(champ) == ERR)
    return (ERR);
  while (champ)
    {
      if (champ->load_adress != -1)
	{
	  if (put_in_arena_dash_a(champ->content,
				  arena, champ->size, champ) == -1)
	    return (ERR);
	}
      champ = champ->next;
    }
  return (0);
}

int     find_pos(char *arena, int size, int pos)
{
  int   i;

  while (pos < MEM_SIZE)
    {
      i = 0;
      while (i <= size)
	{
	  if (i == size)
	    return (pos);
	  if (arena[pos + i % MEM_SIZE] != 0)
	    i = size + 1;
	  i += 1;
	}
      pos += 1;
    }
  return (ERR);
}
