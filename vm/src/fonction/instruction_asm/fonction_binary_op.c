/*
** fonction_binary_op.c for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/vm/src/fonction/instruction_asm
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Mon Mar 27 14:27:15 2017 PierreL
** Last update Wed Mar 29 11:19:40 2017 Elodie Billiot
*/

#include <stdlib.h>
#include "vm_par_fonc.h"
#include "my.h"

int		and_fonction(t_process *process, char *arena)
{
  int		first_arg;
  int		second_arg;
  int		third_arg;
  t_arg_value	*arg;

  if ((arg = malloc(sizeof(t_arg_value))) == NULL)
    return (set_the_carry(0, NULL, -1, process));
  arg->pos = process->pc;
  arg->pos_in_arg = (process->pc + 2) % MEM_SIZE;
  arg->arg_nbr = 1;
  first_arg = find_type_value(process, arena, arg, 0);
  arg->arg_nbr = 2;
  second_arg = find_type_value(process, arena, arg, DEFAULT);
  arg->arg_nbr = 3;
  third_arg = (int)arena[POS_ARENA(arg->pos_in_arg)] - 1;
  if ((third_arg >= 0 && third_arg < REG_NUMBER))
    process->registers[third_arg] = first_arg & second_arg;
  process->pc = ++arg->pos_in_arg % MEM_SIZE;
  if (third_arg < 0 || third_arg > REG_NUMBER)
    return (set_the_carry(0, arg, 0, process));
  return (set_the_carry(1, arg, 0, process));
}

int		or_fonction(t_process *process, char *arena)
{
  int           first_arg;
  int           second_arg;
  int           third_arg;
  t_arg_value   *arg;

  if ((arg = malloc(sizeof(t_arg_value))) == NULL)
    return (set_the_carry(0, NULL, -1, process));
  arg->pos = process->pc;
  arg->pos_in_arg = (process->pc + 2) % MEM_SIZE;
  arg->arg_nbr = 1;
  first_arg = find_type_value(process, arena, arg, 0);
  arg->arg_nbr = 2;
  second_arg = find_type_value(process, arena, arg, DEFAULT);
  arg->arg_nbr = 3;
  third_arg = (int)arena[POS_ARENA(arg->pos_in_arg)] - 1;
  if (third_arg >= 0 && third_arg < REG_NUMBER)
    process->registers[third_arg] = first_arg | second_arg;
  process->pc = ++arg->pos_in_arg % MEM_SIZE;
  if (third_arg < 0 || third_arg > REG_NUMBER)
    return (set_the_carry(0, arg, 0, process));
  return (set_the_carry(1, arg, 0, process));
}

int		xor_fonction(t_process *process, char *arena)
{
  int           first_arg;
  int           second_arg;
  int           third_arg;
  t_arg_value   *arg;

  if ((arg = malloc(sizeof(t_arg_value))) == NULL)
    return (set_the_carry(0, NULL, -1, process));
  arg->pos = process->pc;
  arg->pos_in_arg = (process->pc + 2) % MEM_SIZE;
  arg->arg_nbr = 1;
  first_arg = find_type_value(process, arena, arg, 0);
  arg->arg_nbr = 2;
  second_arg = find_type_value(process, arena, arg, DEFAULT);
  arg->arg_nbr = 3;
  third_arg = (int)arena[POS_ARENA(arg->pos_in_arg)] - 1;
  if ((third_arg >= 0 && third_arg < REG_NUMBER))
    process->registers[third_arg] = first_arg ^ second_arg;
  process->pc = ++arg->pos_in_arg % MEM_SIZE;
  if (third_arg < 0 || third_arg > REG_NUMBER)
    return (set_the_carry(0, arg, 0, process));
  return (set_the_carry(1, arg, 0, process));
}

int		zjmp_fonction(t_process *process, char *arena)
{
  t_arg_value	*arg;

  if ((arg = malloc(sizeof(t_arg_value))) == NULL)
    return (-1);
  arg->pos = process->pc;
  arg->pos_in_arg = (process->pc + 1) % MEM_SIZE;
  arg->arg_nbr = 1;
  if (process->carry == 0)
    process->pc = (process->pc + (int)(short)read_int_buffer_nbyte
		   (arena, arg->pos_in_arg, IND_SIZE));
  else
    process->pc = (process->pc + IND_SIZE + 1) % MEM_SIZE;
  free(arg);
  return (0);
}
