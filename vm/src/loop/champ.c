/*
** champ.c for loop in /home/sylvain.lefevre/git/CPE_2016_corewar/vm/src/loop
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Sat Mar 11 17:36:00 2017 Sylvain Lefevre
** Last update Mon Mar 27 20:25:32 2017 Sylvain Lefevre
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_vm_ar.h"
#include "process.h"
#include "vm.h"

int		free_champ(t_champ *champ)
{
  t_champ	*temp;

  while (champ != NULL)
    {
      temp = champ;
      champ = champ->next;
      free(temp->content);
      free(temp);
    }
  return (0);
}

int	free_arena(char *arena, t_champ *champ, t_process *proc)
{
  free(arena);
  free_champ(champ);
  free_process_list(proc);
  return (0);
}

unsigned int	get_position_champ(t_champ *champ)
{
  unsigned int	position;

  position = 0;
  while (champ)
    {
      if ((position == 0 || champ->defeat_pos < position)
	  && champ->defeat_pos != 0)
	position = champ->defeat_pos;
      champ = champ->next;
    }
  return (position);
}

int	count_champ(t_champ *champ)
{
  int	i;

  i = 0;
  while (champ)
    {
      i += 1;
      champ = champ->next;
    }
  return (i);
}

char	*get_champ_name(t_champ *champ, int id)
{
  while (champ != NULL)
    {
      if (champ->prog_nbr == id && (champ->defeat_pos == 0))
	return (champ->name);
      champ = champ->next;
    }
  return (NULL);
}
