/*
** vm.c for loop in /home/sylvain.lefevre/git/CPE_2016_corewar/vm/src/loop
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Fri Mar 10 23:06:37 2017 Sylvain Lefevre
** Last update Mon Mar 27 12:09:49 2017 ugo lafaille
*/

#include <stdlib.h>
#include "vm.h"
#include "process.h"
#include "champ.h"
#include "loop.h"
#include "my.h"

int	process_loop(char *arena, t_process *proc,
		     t_champ *champ, t_live *lives)
{
  while (proc != NULL)
    {
      if (do_process(proc, arena, champ, lives))
	return (1);
      proc = proc->next;
    }
  return (0);
}

t_live			*cycles_loop(char *arena, t_process *proc,
				     t_champ *champ, int dump_cycles)
{
  unsigned short	cycles;
  static unsigned short	cycles_to_die = CYCLE_TO_DIE;
  t_live		*lives;
  static unsigned int	prev_cycles = 0;

  cycles = 0;
  if (!(lives = create_live()))
    return (NULL);
  while (cycles < cycles_to_die)
    {
      if (process_loop(arena, proc, champ, lives))
	return (free_live(lives));
      cycles += 1;
      if (!((cycles + prev_cycles) % NBR_LIVE)
	  && cycles_to_die - CYCLE_DELTA >= 0)
	cycles_to_die -= CYCLE_DELTA;
      else if (!((cycles + prev_cycles) % NBR_LIVE))
	cycles_to_die = 0;
      if (dump_cycles != 0)
	if (!((cycles + prev_cycles) % dump_cycles))
	  dump_mem(arena);
    }
  prev_cycles += cycles;
  return (lives);
}

int		vm(char **av)
{
  t_champ	*champ;
  int		dump;
  char		*arena;
  t_process	*proc;

  dump = 0;
  if (!(arena = create_arena()))
    return (84);
  if (!(champ = put_arg_in_link(av, &dump)))
    return (84 + free_arena(arena, NULL, NULL));
  if ((create_champ_from_list(champ)))
    return (84 + free_arena(arena, champ, NULL));
  if ((place_champs(champ, arena)))
    return (84 + free_arena(arena, champ, NULL));
  if (!(proc = create_process_list(champ)))
    return (84 + free_arena(arena, champ, NULL));
  dump = vm_loop(arena, proc, champ, dump);
  return (free_arena(arena, champ, NULL) + dump);
}

int		vm_loop(char *arena, t_process *proc,
			t_champ *champ, int dump_cycles)
{
  t_live	*lives;

  lives = NULL;
  while (proc != NULL)
    {
      if (!(lives = cycles_loop(arena, proc, champ, dump_cycles)))
	return (84);
      proc = set_defeat_champ(champ, lives, proc);
      lives = free_live(lives);
    }
  print_winner(champ);
  return (0);
}
