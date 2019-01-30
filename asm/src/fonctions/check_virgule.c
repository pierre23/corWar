/*
** check_virgule.c for  in /home/elodie.billiot/Corewar/CPE_2016_corewar/asm/src/fonctions
** 
** Made by Elodie Billiot
** Login   <elodie.billiot@epitech.net>
** 
** Started on  Thu Mar  2 14:49:53 2017 Elodie Billiot
** Last update Tue Mar  7 11:21:09 2017 ugo lafaille
*/

#include <stdlib.h>

int    free_tab(char **arg)
{
  int   i;

  i = -1;
  while (arg[++i])
    free(arg[i]);
  free(arg);
  return (-1);
}

int	check_virgule(char *str)
{
  int	i;
  int	compt;

  i = 0;
  compt = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ',')
	compt++;
      i++;
    }
  return (compt);
}
