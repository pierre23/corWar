/*
** parsing_instruct.c for  in /home/elodie.billiot/Corewar/CPE_2016_corewar/vm/src/fonction/parsing_instruction
** 
** Made by Elodie Billiot
** Login   <elodie.billiot@epitech.net>
** 
** Started on  Tue Mar 21 15:51:40 2017 Elodie Billiot
** Last update Wed Mar 29 13:18:44 2017 Elodie Billiot
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "process.h"
#include "vm_par_fonc.h"
#include "vm_fonction.h"
#include "vm.h"
#include "op.h"
#include "my.h"

int		check_type_arg(int index, char type, int i)
{
  if (index - 1 < 0 || index - 1 > 16)
    return (-1);
  if (op_tab[index - 1].type[i] & type)
    return (0);
  return (-1);
}

int		check_valid_instruct(char *arena, int pos)
{
  char		type;
  int		mask;
  int		index;
  int		i;

  mask = MAX_MASK;
  i = 0;
  if ((index = arena[POS_ARENA(pos)]) < 1 || index > 16)
    return (EXIT_FAIL);
  if (op_tab[index -1].nbr_args == ONE_ARG)
    return (index);
  while (i != op_tab[index - 1].nbr_args)
    {
      type = 0;
      if (arena[POS_ARENA(pos + 1)] & mask)
	type += 2;
      mask = mask >> 1;
      if (arena[POS_ARENA(pos + 1)] & mask)
	type += 1;
      mask = mask >> 1;
      if (check_type_arg(index, type, i) == EXIT_FAIL)
	return (EXIT_FAIL);
      i++;
    }
  return (index);
}

/*
** mdr fallait pas remove le comment et s'en battre la race hein
** faut toujours mettre des define hein
*/

void		put_in_tabl(int (*tabl[TABL_INST_SIZE])
			    (t_process *process, char *arena))
{
  tabl[0] = NULL;
  tabl[1] = ld_fonction;
  tabl[2] = st_fonction;
  tabl[3] = add_fonction;
  tabl[4] = sub_fonction;
  tabl[5] = and_fonction;
  tabl[6] = or_fonction;
  tabl[7] = xor_fonction;
  tabl[8] = zjmp_fonction;
  tabl[9] = ldi_fonction;
  tabl[10] = sti_fonction;
  tabl[11] = fork_fonction;
  tabl[12] = lld_fonction;
  tabl[13] = lldi_fonction;
  tabl[14] = lfork_fonction;
  tabl[15] = aff_fonction;
  tabl[16] = NULL;
}

int		parsing_instruct(t_process *process, char *arena
				 , t_live *live, t_champ *champ)
{
  int		index;
  int		(*tabl[TABL_INST_SIZE * 123])(t_process *process, char *arena);

  put_in_tabl(tabl);
  index = 0;
  if (process == NULL || arena == NULL)
    return (1);
  if (arena[POS_ARENA(process->pc)] == BAD_IND_FONC)
    {
      process->pc++;
      return (0);
    }
  if ((index = check_valid_instruct(arena, process->pc)) == EXIT_FAIL)
    {
      process->pc++;
      return (0);
    }
  if (index - 1 > 0)
    if ((tabl[index - 1](process, arena)) == -1)
      return (1);
  if (index - 1 == 0)
    if ((live_fonction(process, arena, live, champ)) == -1)
      return (1);
  return (0);
}
