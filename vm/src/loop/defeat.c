/*
** defeat.c for loop in /home/sylvain.lefevre/git/CPE_2016_corewar/vm/src/loop
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Sun Mar 12 15:19:41 2017 Sylvain Lefevre
** Last update Sun Mar 12 15:19:41 2017 Sylvain Lefevre
*/

#include "vm.h"
#include "my_vm_ar.h"
#include "loop.h"
#include "champ.h"
#include "my.h"

t_process	*set_defeat_champ(t_champ *champ, t_live *lives,
				  t_process *proc)
{
  unsigned int	position;
  t_champ	*temp;

  if ((position = get_position_champ(champ)) == 0)
    position = count_champ(champ) + 1;
  temp = champ;
  while (temp)
    {
      if (!is_champ_in_live(lives, temp->prog_nbr) && temp->defeat_pos == 0)
	position -= 1;
      temp = temp->next;
    }
  while (champ)
    {
      if (!is_champ_in_live(lives, champ->prog_nbr) && champ->defeat_pos == 0)
	{
	  champ->defeat_pos = position;
	  proc = kill_process(proc, champ->prog_nbr);
	}
      champ = champ->next;
    }
  return (proc);
}

int		print_winner(t_champ *champ)
{
  while (champ)
    {
      if (champ->defeat_pos == 1)
	my_fputstr(1, WIN_STRING, champ->prog_nbr,
		   champ->name);
      champ = champ->next;
    }
  return (0);
}
