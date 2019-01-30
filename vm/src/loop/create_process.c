/*
** create_process.c for loop in /home/sylvain.lefevre/git/CPE_2016_corewar/vm/src/loop
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Fri Mar 10 18:03:28 2017 Sylvain Lefevre
** Last update Fri Mar 10 18:03:28 2017 Sylvain Lefevre
*/

#include <stdlib.h>
#include "process.h"
#include "my_vm_ar.h"
#include "my.h"

t_process	*create_process(t_process *proc, int pc, int cid)
{
  t_process	*new;
  int		i;

  if (!(new = malloc(sizeof(t_process))))
    return (NULL);
  if (!proc)
    new->next = NULL;
  else
    {
      new->next = proc->next;
      proc->next = new;
    }
  i = POS_REG_CID + 1;
  new->pc = pc;
  new->cid = cid;
  new->pid = FIRST_PID;
  new->carry = 0;
  new->cycles = 0;
  new->registers[POS_REG_CID] = cid;
  while (i < REG_NUMBER)
    new->registers[i++] = 0;
  if (!proc)
    return (new);
  return (proc);
}

int		append_process(t_process *proc, int pc, int cid)
{
  t_process	*new;
  int		i;
  static int	pid = FIRST_PID + 1;

  if (!proc)
    return (84);
  if (!(new = malloc(sizeof(t_process))))
    return (84);
  new->next = NULL;
  while (proc->next != NULL)
    proc = proc->next;
  proc->next = new;
  i = 1;
  new->pid = pid++;
  new->cid = cid;
  new->pc = pc;
  new->carry = 0;
  new->cycles = -1;
  new->registers[POS_REG_CID] = cid;
  while (i < REG_NUMBER)
    new->registers[i++] = 0;
  return (0);
}

t_process	*create_process_list(t_champ *champ)
{
  t_process	*proc;

  proc = NULL;
  while (champ != NULL)
    {
      if (!proc)
	{
	  if (!(proc = create_process(proc, champ->load_adress,
				      champ->prog_nbr)))
	    return (NULL);
	}
      else
	if (append_process(proc, champ->load_adress, champ->prog_nbr))
	  return (NULL);
      champ = champ->next;
    }
  return (proc);
}
