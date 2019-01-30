/*
** main.c for  in /home/elodie.billiot/Corewar/CPE_2016_corewar/vm/src
** 
** Made by Elodie Billiot
** Login   <elodie.billiot@epitech.net>
** 
** Started on  Mon Mar 27 12:45:46 2017 Elodie Billiot
** Last update Fri Mar 31 12:32:03 2017 Elodie Billiot
*/

#include "errors.h"
#include "my.h"
#include "vm.h"

void		verbose(char **av)
{
  my_fputstr(1, USAGE, av[0]);
  my_fputstr(1, ARG_HELP);
  my_fputstr(1, DESC);
  my_fputstr(1, EXEC);
  my_fputstr(1, FORM_DUMP);
  my_fputstr(1, HEXA);
  my_fputstr(1, PROG_NB);
  my_fputstr(1, DEFAULT_NB);
  my_fputstr(1, PARAMS);
  my_fputstr(1, A_LOAD);
  my_fputstr(1, ADDRESS);
  my_fputstr(1, OPTI);
  my_fputstr(1, PROCESS);
  my_fputstr(1, POSSIBLE);
  my_fputstr(1, MEM_ADDR);
}

int		main(int ac, char **av)
{
  if (ac == 2)
    if (my_strcmp(av[1], HELP) == 0)
      {
	verbose(av);
	return (0);
      }
  if (ac > 1)
    return (vm(av));
  verbose(av);
  return (84);
}
