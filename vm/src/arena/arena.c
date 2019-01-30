/*
** arena.c for arena in /home/sylvain.lefevre/git/CPE_2016_corewar/vm/src/arena
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Thu Mar 09 11:37:44 2017 Sylvain Lefevre
** Last update Wed Mar 15 14:22:46 2017 Elodie Billiot
*/

#include <stdlib.h>
#include <unistd.h>
#include "op.h"
#include "vm.h"

char		*create_arena()
{
  int		i;
  char		*arena;

  if (!(arena = malloc(sizeof(char) * (MEM_SIZE + 1))))
    return (NULL);
  i = 0;
  while (i < MEM_SIZE)
    arena[i++] = 0;
  return (arena);
}
