/*
** print_value.c for  in /home/elodie.billiot/Corewar/CPE_2016_corewar/vm/src/fonction/parsing_instruction
** 
** Made by Elodie Billiot
** Login   <elodie.billiot@epitech.net>
** 
** Started on  Thu Mar 23 14:41:47 2017 Elodie Billiot
** Last update Wed Mar 29 08:19:19 2017 Elodie Billiot
*/

#include "vm.h"

int		print_value_in_arena(char *arena, int pos,
				     int nbr, unsigned int size)
{
  unsigned int  j;
  unsigned int	i;

  j = pos;
  i = (size <= 0) ? sizeof(int) : size;
  while (i > sizeof(int))
    {
      if (nbr >= 0)
	arena[POS_ARENA((int)j)] = 0x00;
      else
	arena[POS_ARENA((int)j)] = -1;
      i -= 1;
      j++;
    }
  while (i > 0)
    {
      arena[POS_ARENA((int)j)] = (nbr >> --i * 8) & 0xFF;
      j++;
    }
  return (i);
}
