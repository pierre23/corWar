/*
** check_register.c for  in /home/elodie.billiot/Corewar/CPE_2016_corewar/asm/src/fonctions
** 
** Made by Elodie Billiot
** Login   <elodie.billiot@epitech.net>
** 
** Started on  Mon Mar  6 05:52:43 2017 Elodie Billiot
** Last update Thu Mar 23 16:37:07 2017 ugo lafaille
*/

#include <unistd.h>
#include <stdlib.h>
#include "fonctions.h"
#include "asm.h"
#include "my.h"
#include "errors.h"

char	*my_charcat(char c, char v)
{
  char	*str;

  if ((str = malloc(sizeof(char) * 3)) == NULL)
    return (NULL);
  str[0] = c;
  str[1] = v;
  str[2] = '\0';
  return (str);
}

int	check_register(char *str, int line)
{
  if (remove_space(str) == 84)
    return (-1);
  if (my_strlen(str) <= 3 && my_strlen(str) > 1)
    {
      if (str_isnum(&str[1]) && str[0] == 'r')
	{
	  if (my_getnbr(&str[1]) <= REG_NUMBER
	      && my_getnbr(&str[1]) > 0)
	    return (REG_SIZE);
	}
      return (-1 + my_fputstr(2, ERR_FORMAT, line, ERR_REG, str));
    }
  return (-1 + my_fputstr(2, ERR_FORMAT, line, ERR_REG, str));
}
