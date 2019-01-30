/*
** remove_space.c for  in /home/elodie.billiot/Corewar/CPE_2016_corewar/asm/src/fonctions
** 
** Made by Elodie Billiot
** Login   <elodie.billiot@epitech.net>
** 
** Started on  Thu Mar  2 14:15:21 2017 Elodie Billiot
** Last update Thu Mar 23 13:25:08 2017 ugo lafaille
*/

#include "my.h"
#include "asm.h"
#include "errors.h"

char	*change_carac(char *str, int n)
{
  while (str[n] != '\0')
    {
      str[n] = str[n + 1];
      n++;
    }
  return (str);
}

int    remove_space(char *str)
{
  int   i;

  i = 0;
  while (str[0] == SPACE_CHAR)
    str = change_carac(str, 0);
  while (str[i] != '\0')
    i++;
  while (str[i - 1] == SPACE_CHAR)
    {
      str = change_carac(str, (i - 1));
      i--;
    }
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == SPACE_CHAR)
	return (-1);
      i++;
    }
  return (0);
}
