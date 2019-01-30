/*
** free_process.c for loop in /home/sylvain.lefevre/git/CPE_2016_corewar/vm/src/loop
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Sun Mar 12 11:31:19 2017 Sylvain Lefevre
** Last update Fri Mar 24 09:56:28 2017 PierreL
*/

#include <unistd.h>
#include <stdlib.h>
#include "process.h"
#include "loop.h"
#include "my.h"

void		*free_next_process(t_process *prev)
{
  t_process	*temp;

  if (!prev)
    return (NULL);
  temp = prev->next;
  if (!temp)
    return (NULL);
  prev->next = temp->next;
  free(temp);
  return (NULL);
}

void		*free_process_list(t_process *proc)
{
  t_process	*temp;

  while (proc)
    {
      temp = proc->next;
      free(proc);
      proc = temp;
    }
  return (NULL);
}

int		kill_process_next(t_process *proc, unsigned int cid)
{
  t_process	*temp;
  t_process	*temp_prev;

  temp = proc->next;
  temp_prev = proc;
  while (temp)
    {
      if (temp->cid == cid)
	{
	  free_next_process(temp_prev);
	  temp = temp_prev;
	}
      temp_prev = temp;
      temp = temp->next;
    }
  return (0);
}

t_process	*kill_process(t_process *proc, unsigned int cid)
{
  t_process	*temp;

  if (!proc)
    return (NULL);
  while (proc)
    {
      if (proc->cid == cid)
	{
	  temp = proc;
	  proc = proc->next;
	  free(temp);
	}
      else
	{
	  kill_process_next(proc, cid);
	  return (proc);
	}
    }
  return (NULL);
}
