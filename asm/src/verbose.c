/*
** verbose.c for  in /home/elodie.billiot/Corewar/CPE_2016_corewar/asm/src/help
** 
** Made by Elodie Billiot
** Login   <elodie.billiot@epitech.net>
** 
** Started on  Thu Mar 23 12:09:13 2017 Elodie Billiot
** Last update Thu Mar 23 12:37:36 2017 Elodie Billiot
*/

#include "asm.h"
#include "my.h"

void		verbose(char **av)
{
  my_fputstr(1, USAGE);
  my_fputstr(1, "%s", av[0]);
  my_fputstr(1, FILE_NAME);
  my_fputstr(1, LANGUAGE);
  my_fputstr(1, FILE_COR);
  my_fputstr(1, V_M);
}
