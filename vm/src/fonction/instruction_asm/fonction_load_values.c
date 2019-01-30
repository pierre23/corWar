/*
** fonction_asm2.c for  in /home/elodie.billiot/Corewar/CPE_2016_corewar/vm/src/fonction/pierre
** 
** Made by Elodie Billiot
** Login   <elodie.billiot@epitech.net>
** 
** Started on  Mon Mar 13 11:03:37 2017 Elodie Billiot
** Last update Sat Apr  1 23:54:38 2017 Sylvain Lefevre
*/

#include <stdlib.h>
#include "vm_par_fonc.h"
#include "my.h"

int		ld_fonction(t_process *process, char *arena)
{
  int           first_arg;
  int           second_arg;
  t_arg_value   *arg;

  if ((arg = malloc(sizeof(t_arg_value))) == NULL)
    return (set_the_carry(1, NULL, -1, process));
  arg->pos = process->pc;
  arg->pos_in_arg = process->pc + 2 % MEM_SIZE;
  arg->arg_nbr = 1;
  first_arg = find_type_value(process, arena, arg, DEFAULT_IDX);
  arg->arg_nbr = 2;
  second_arg = arena[POS_ARENA(arg->pos_in_arg)] - 1;
  if (second_arg < 0 || second_arg >= REG_NUMBER)
    {
      process->pc = ++arg->pos_in_arg % MEM_SIZE;
      return (set_the_carry(0, arg, 1, process));
    }
  process->registers[second_arg] = first_arg;
  process->pc = ++arg->pos_in_arg % MEM_SIZE;
  return (set_the_carry(1, arg, 0, process));
}

int		ldi_fonction(t_process *process, char *arena)
{
  int           first_arg;
  int           second_arg;
  int           third_arg;
  t_arg_value   *arg;

  if ((arg = malloc(sizeof(t_arg_value))) == NULL)
    return (set_the_carry(1, NULL, -1, process));
  arg->pos = process->pc;
  arg->pos_in_arg = process->pc + 2 % MEM_SIZE;
  arg->arg_nbr = 1;
  first_arg = find_type_value(process, arena, arg, EXCEPTION_IDX);
  arg->arg_nbr = 2;
  second_arg = find_type_value(process, arena, arg, EXCEPTION_IDX);
  arg->arg_nbr = 3;
  if ((third_arg = read_int_buffer_nbyte(arena, POS_ARENA(arg->pos_in_arg),
					 REG_SIZE)) < 1 || third_arg  > 16)
    {
      process->pc = ++arg->pos_in_arg % MEM_SIZE;
      return (set_the_carry(1, arg, 1, process));
    }
  process->registers[third_arg - 1] = read_int_buffer_nbyte
    (arena, POS_ARENA(process->pc + ((first_arg + second_arg)
				     % IDX_MOD)), REG_SIZE);
  process->pc = ++arg->pos_in_arg % MEM_SIZE;
  return (set_the_carry(0, arg, 0, process));
}

int            lld_fonction(t_process *process, char *arena)
{
  int           first_arg;
  int           second_arg;
  t_arg_value   *arg;

  if ((arg = malloc(sizeof(t_arg_value))) == NULL)
    return (set_the_carry(1, NULL, -1, process));
  arg->pos = process->pc;
  arg->pos_in_arg = process->pc + 2 % MEM_SIZE;
  arg->arg_nbr = 1;
  first_arg = find_type_value(process, arena, arg, DEFAULT);
  arg->arg_nbr = 2;
  second_arg = arena[POS_ARENA(arg->pos_in_arg)] - 1;
  if (second_arg < 1 || second_arg > REG_NUMBER)
    {
      process->pc = ++arg->pos_in_arg % MEM_SIZE;
      return (set_the_carry(1, arg, 1, process));
    }
  process->registers[second_arg] = first_arg;
  process->pc = ++arg->pos_in_arg % MEM_SIZE;
  return (set_the_carry(0, arg, 0, process));
}

int            lldi_fonction(t_process *process, char *arena)
{
  int           first_arg;
  int           second_arg;
  int           third_arg;
  t_arg_value   *arg;

  if ((arg = malloc(sizeof(t_arg_value))) == NULL)
    return (set_the_carry(1, NULL, -1, process));
  arg->pos = process->pc;
  arg->pos_in_arg = process->pc + 2 % MEM_SIZE;
  arg->arg_nbr = 1;
  first_arg = find_type_value(process, arena, arg, EXCEPTION_IDX);
  arg->arg_nbr = 2;
  second_arg = find_type_value(process, arena, arg, EXCEPTION_IDX);
  arg->arg_nbr = 3;
  if ((third_arg = read_int_buffer_nbyte(arena, POS_ARENA(arg->pos_in_arg),
					 REG_SIZE)) < 1 || third_arg  > 16)
    {
      process->pc = ++arg->pos_in_arg % MEM_SIZE;
      return (set_the_carry(1, arg, 1, process));
    }
  process->registers[third_arg] = (first_arg + second_arg) % IDX_MOD;
  process->pc = ++arg->pos_in_arg % MEM_SIZE;
  return (set_the_carry(0, arg, 0, process));
}
