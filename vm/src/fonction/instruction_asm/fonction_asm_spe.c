/*
** fonction_asm_spe.c for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/vm/src/fonction
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Mon Mar 27 14:39:28 2017 PierreL
** Last update Wed Mar 29 11:18:06 2017 Elodie Billiot
*/

#include <stdlib.h>
#include "vm_par_fonc.h"
#include "my.h"

int		live_fonction(t_process *process, char *arena,
			      t_live *live, t_champ *champ)
{
  int		value;

  ++process->pc;
  value = read_int_buffer_nbyte(arena, POS_ARENA(process->pc), DIR_SIZE);
  if (add_in_live_list(live, value, champ) == 1)
    return (-1);
  process->pc = (process->pc + 4) % MEM_SIZE;
  return (0);
}

int		aff_fonction(t_process *process, char *arena)
{
  int           first_arg;

  process->pc += 2;
  first_arg = arena[POS_ARENA(process->pc)] - 1;
  if (!(first_arg < 0 || first_arg > REG_NUMBER))
    my_fputstr(1, "%c\n", (char)process->registers[first_arg]);
  process->pc = (process->pc + 1) % MEM_SIZE;
  return (0);
}
