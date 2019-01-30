/*
** fonction_operat.c for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/vm/src/loop
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Thu Mar 23 19:54:38 2017 PierreL
** Last update Wed Mar 29 11:21:08 2017 Elodie Billiot
*/

#include <stdlib.h>
#include "vm_par_fonc.h"
#include "my.h"

int		sub_fonction(t_process *process, char *arena)
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
  first_arg = find_type_value(process, arena, arg, DEFAULT);
  arg->arg_nbr = 2;
  second_arg = find_type_value(process, arena, arg, DEFAULT);
  arg->arg_nbr = 3;
  third_arg = arena[POS_ARENA(arg->pos_in_arg)] - 1;
  if (third_arg < 1 || third_arg > 16)
    return (process->pc = ++arg->pos_in_arg % MEM_SIZE,
	    set_the_carry(1, arg, 1, process));
  process->registers[third_arg] = first_arg - second_arg;
  process->pc = ++arg->pos_in_arg % MEM_SIZE;
  return (set_the_carry(0, arg, 0, process));
}

int            add_fonction(t_process *process, char *arena)
{
  int           first_arg;
  int           second_arg;
  int           third_arg;
  t_arg_value   *arg;

  if ((arg = malloc(sizeof(t_arg_value))) == NULL)
    return (set_the_carry(0, NULL, -1, process));
  arg->pos = process->pc;
  arg->pos_in_arg = process->pc + 2 % MEM_SIZE;
  arg->arg_nbr = 1;
  first_arg = find_type_value(process, arena, arg, DEFAULT);
  arg->arg_nbr = 2;
  second_arg = find_type_value(process, arena, arg, DEFAULT);
  arg->arg_nbr = 3;
  third_arg = arena[POS_ARENA(arg->pos_in_arg)] - 1;
  if (third_arg < 1 || third_arg > 16)
    return (process->pc = ++arg->pos_in_arg % MEM_SIZE,
	    set_the_carry(1, arg, 1, process));
  process->registers[third_arg] = first_arg + second_arg;
  process->pc = ++arg->pos_in_arg % MEM_SIZE;
  return (set_the_carry(0, arg, 0, process));
}
