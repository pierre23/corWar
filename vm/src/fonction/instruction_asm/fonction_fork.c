/*
** fonction_fork.c for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/vm/src/fonction
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Thu Mar 23 19:49:28 2017 PierreL
** Last update Sat Apr  1 23:54:55 2017 Sylvain Lefevre
*/

#include <stdlib.h>
#include "vm_par_fonc.h"
#include "my.h"

int            fork_fonction(t_process *process, char *arena)
{
  if (append_process(process, (process->pc + (read_int_buffer_nbyte
					      (arena, POS_ARENA(process->pc + 1), IND_SIZE)
					      % IDX_MOD)), process->cid))
    {
      process->pc++;
      return (-1);
    }
  set_child_process(process);
  process->pc = ((process->pc + 1) + IND_SIZE) % MEM_SIZE;
  return (0);
}

int		lfork_fonction(t_process *process, char *arena)
{
  if (append_process(process, process->pc + read_int_buffer_nbyte
		     (arena, POS_ARENA(process->pc + 1), IND_SIZE), process->cid))
    {
      process->pc++;
      return (-1);
    }
  set_child_process(process);
  process->pc = ((process->pc + 1) + IND_SIZE) % MEM_SIZE;
  return (0);
}
