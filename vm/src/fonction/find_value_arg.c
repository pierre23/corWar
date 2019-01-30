/*
** find_value_arg.c for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/vm/src/fonction
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Tue Mar 21 19:25:40 2017 PierreL
** Last update Wed Mar 29 11:10:54 2017 Elodie Billiot
*/

#include <unistd.h>
#include <stdlib.h>
#include "process.h"
#include "vm.h"
#include "my.h"
#include "vm_par_fonc.h"
#include "vm_fonction.h"
#include "op.h"

int		registre_value(t_process *process, char *arena, t_arg_value *arg)
{
  int		reg_value;

  if ((int)arena[POS_ARENA(arg->pos_in_arg)] > REG_NUMBER
      || (int)arena[POS_ARENA(arg->pos_in_arg)] < REG_MIN)
    return (EXIT_KO);
  reg_value = process->registers[(int)arena[POS_ARENA(arg->pos_in_arg)] - 1];
  arg->pos_in_arg = (arg->pos_in_arg + REG_SIZE) % MEM_SIZE;
  return (reg_value);
}

int		direct_value(char *arena, t_arg_value *arg, int flag)
{
  int		mod;
  int		value;

  mod = FD_IDX_MOD(flag);
  if (flag == DEFAULT || flag == DEFAULT_IDX)
    {
      value = (read_int_buffer_nbyte(arena,
				     POS_ARENA(arg->pos_in_arg), DIR_SIZE));
      arg->pos_in_arg = (arg->pos_in_arg + DIR_SIZE) % MEM_SIZE;
    }
  else if (flag == EXCEPTION || flag == EXCEPTION_IDX)
    {
      value = ((int)(short)read_int_buffer_nbyte(arena,
						 POS_ARENA(arg->pos_in_arg), IND_SIZE) % mod);
      arg->pos_in_arg = (arg->pos_in_arg + IND_SIZE) % MEM_SIZE;
    }
  return (value);
}

int		read_int_buffer_nbyte(char *buffer, int pos, unsigned int n)
{
  unsigned int  i;
  unsigned int  nbr;

  i = 0;
  nbr = 0;
  while (i < n)
    {
      nbr = nbr + ((unsigned char)buffer[POS_ARENA((int)(i + pos))]
		   << 8 * (n - (i + 1)));
      i += 1;
    }
  return ((int)nbr);
}

int		indirect_value(char *arena, t_arg_value *arg)
{
  int		value;

  value = ((int)(short)read_int_buffer_nbyte(arena,
					     POS_ARENA(arg->pos_in_arg), IND_SIZE));
  arg->pos_in_arg = (arg->pos_in_arg + IND_SIZE) % MEM_SIZE;
  if (value < 0)
    value = (MEM_SIZE - (value % MEM_SIZE)) - 1;
  return (read_int_buffer_nbyte(arena, POS_ARENA(value), IND_SIZE));
}

int		find_type_value(t_process *process, char *arena,
				t_arg_value *arg, int flag)
{
  unsigned int	mask;
  char		type;

  type = 0;
  mask = MAX_MASK;
  mask = mask >> (2 * (arg->arg_nbr - 1));
  if (arena[POS_ARENA(arg->pos + 1)] & mask)
    type += 2;
  mask = mask >> 1;
  if (arena[POS_ARENA(arg->pos + 1)] & mask)
    type += 1;
  if (type == 1)
    return (registre_value(process, arena, arg));
  else if (type == 2)
    return (direct_value(arena, arg, flag));
  else if (type == 3)
    return (indirect_value(arena, arg));
  return (-1);
}
