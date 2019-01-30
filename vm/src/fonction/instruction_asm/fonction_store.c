/*
** fonction_store.c for  in /home/elodie.billiot/Corewar/CPE_2016_corewar/vm/src/fonction/instruction_asm
** 
** Made by Elodie Billiot
** Login   <elodie.billiot@epitech.net>
** 
** Started on  Mon Mar 27 12:48:40 2017 Elodie Billiot
** Last update Sat Apr  1 23:32:20 2017 Sylvain Lefevre
*/

#include <stdlib.h>
#include "vm_par_fonc.h"
#include "my.h"

void		st_fonction_reg(char *arena, t_process *process,
				t_arg_value *arg, int first_arg)
{
  if (arena[POS_ARENA(arg->pos_in_arg)] < REG_NUMBER
      && arena[POS_ARENA(arg->pos_in_arg)] > 0)
    process->registers[(int)arena[POS_ARENA(arg->pos_in_arg)] - 1] = first_arg;
  arg->pos_in_arg++;
}

int		st_fonction(t_process *process, char *arena)
{
  int		first_arg;
  t_arg_value	*arg;

  if ((arg = malloc(sizeof(t_arg_value))) == NULL)
    return (-1);
  arg->pos = process->pc;
  arg->pos_in_arg = (process->pc + 2) % MEM_SIZE;
  arg->arg_nbr = 1;
  first_arg = find_type_value(process, arena, arg, DEFAULT);
  if ((arena[POS_ARENA(process->pc + 1)] & (1 << 5))
      && (arena[POS_ARENA(process->pc + 1)] & (1 << 4)))
    {
      print_value_in_arena
	(arena, POS_ARENA(process->pc + (int)(short)read_int_buffer_nbyte
			  (arena, POS_ARENA(arg->pos_in_arg), IND_SIZE)),
	 first_arg, DIR_SIZE);
      arg->pos_in_arg += 2;
    }
  else if (!(arena[POS_ARENA(process->pc + 1)] & (1 << 5))
	   && (arena[POS_ARENA(process->pc + 1)] & (1 << 4)))
    st_fonction_reg(arena, process, arg, first_arg);
  process->pc = arg->pos_in_arg % MEM_SIZE;
  free(arg);
  return (0);
}

int		sti_fonction(t_process *process, char *arena)
{
  int		first_arg;
  int		second_arg;
  int		third_arg;
  t_arg_value	*arg;

  if ((arg = malloc(sizeof(t_arg_value))) == NULL)
    return (-1);
  arg->pos = process->pc;
  arg->pos_in_arg = (process->pc + 2) % MEM_SIZE;
  arg->arg_nbr = 1;
  first_arg = arena[POS_ARENA(arg->pos_in_arg)] - 1;
  arg->pos_in_arg++;
  arg->arg_nbr = 2;
  second_arg = find_type_value(process, arena, arg, EXCEPTION_IDX);
  arg->arg_nbr = 3;
  third_arg = find_type_value(process, arena, arg, EXCEPTION_IDX);
  if (first_arg > REG_NUMBER || first_arg < 0)
    return (0);
  print_value_in_arena(arena, POS_ARENA(process->pc + second_arg + third_arg),
		       process->registers[first_arg], DIR_SIZE);
  process->pc = POS_ARENA(arg->pos_in_arg);
  free(arg);
  return (0);
}
