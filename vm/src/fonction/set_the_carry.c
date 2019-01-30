/*
** set_the_carry.c for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/vm/src/fonction
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Thu Mar 23 20:31:44 2017 PierreL
** Last update Tue Mar 28 09:59:23 2017 PierreL
*/

#include <stdlib.h>
#include "vm_par_fonc.h"
#include "process.h"

int	set_the_carry(int carry, t_arg_value *arg,
		      int return_value, t_process *proc)
{
  proc->carry = carry;
  if (arg)
    free(arg);
  return (return_value);
}
