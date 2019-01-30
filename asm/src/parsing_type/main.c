/*
** main.c for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/asm/parsing_type
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Tue Feb 28 15:22:55 2017 PierreL
** Last update Tue Mar  7 20:52:59 2017 PierreL
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "arg.h"
#include "asm.h"

int	main()
{
  t_arg	*ctrl;
  char	*arg;
  t_labels *lab;

  lab = NULL;
  arg = my_strdup("%1,%:1,r1");
  if ((ctrl = pars_arg(lab, arg, 1)) == NULL)
    return (84);
  find_nbr_arg(ctrl);
  free(arg);
  free(ctrl);
  return (0);
}
