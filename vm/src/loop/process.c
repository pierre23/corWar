/*
** process.c for loop in /home/sylvain.lefevre/git/CPE_2016_corewar/vm/src/loop
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Sat Mar 11 17:48:31 2017 Sylvain Lefevre
** Last update Fri Mar 24 15:14:21 2017 PierreL
*/

#include "op.h"
#include "process.h"
#include "vm.h"
#include "loop.h"
#include "champ.h"
#include "vm_par_fonc.h"
#include "my.h"

int	set_cycles(t_process *proc, char *arena)
{
  if (arena[POS_ARENA(proc->pc)] >= 0 && arena[POS_ARENA(proc->pc)] < 16)
    proc->cycles = op_tab[(int)arena[POS_ARENA(proc->pc)]].nbr_cycles;
  else
    proc->cycles = 0;
  return (0);
}

int		set_child_process(t_process *proc)
{
  int		i;
  t_process	*child;

  i = 0;
  if (!proc)
    return (0);
  child = proc;
  while (child->next)
    child = child->next;
  child->cycles = -1;
  while (i < REG_NUMBER)
    {
      child->registers[i] = proc->registers[i];
      i += 1;
    }
  return (0);
}

int		do_action_process(t_process *proc, char *arena,
				  t_live *lives, t_champ *champ)
{
  unsigned int	temp;

  if (arena[POS_ARENA(proc->pc)] == 1)
    {
      if (proc->pc + 5 < MEM_SIZE)
	temp = read_uns_int_buffer(&arena[POS_ARENA(proc->pc + 1)]);
      else
	temp = 0;
      if (add_in_live_list(lives, (int)temp, champ))
	return (1);
      proc->pc = (proc->pc + 5) % MEM_SIZE;
    }
  else if (arena[POS_ARENA(proc->pc)] > 0 && arena[POS_ARENA(proc->pc)] <= 16)
    {
      parsing_instruct(proc, arena, lives, champ);
      return (0);
    }
  else
    proc->pc = (proc->pc + 1) % MEM_SIZE;
  proc->carry = 0;
  set_cycles(proc, arena);
  return (0);
}

int		do_process(t_process *proc, char *arena,
		   t_champ *champ, t_live *lives)
{
  if (proc->cycles <= 0)
    {
      if (arena[POS_ARENA(proc->pc)] > 0 && arena[POS_ARENA(proc->pc)] < 17)
	proc->cycles = op_tab[arena[POS_ARENA(proc->pc)] - 1].nbr_cycles - 1;
      else
	proc->cycles = 1;
    }
  else
    proc->cycles -= 1;
  if (proc->cycles == 0)
    {
      if (parsing_instruct(proc, arena, lives, champ) == 1)
	return (1);
      proc->pc = POS_ARENA(proc->pc);
    }
  return (0);
}
