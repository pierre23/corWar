/*
** live.c for  in /home/ugolaf/delivery/CPE_2016_corewar
** 
** Made by ugo lafaille
** Login   <ugolaf@epitech.net>
** 
** Started on  Tue Feb 28 15:08:05 2017 ugo lafaille
** Last update Thu Mar 23 19:31:04 2017 PierreL
*/

#include <stdlib.h>
#include "fonctions.h"
#include "my.h"
#include "asm.h"
#include "op.h"
#include "errors.h"

int     check_arg_indirect(char *str, int line)
{
  int   i;
  int   lab;
  int	 nbr;

  i = 0;
  lab = 0;
  nbr = 0;
  while (str[i] != '\0')
    {
      if (str[i] == LABEL_CHAR && lab == 0)
	lab += 1;
      else if (str[i] >= '0' && str[i] <= '9'  && lab == 0 && nbr >= 0)
	nbr = change_nbr(str, i, nbr);
      else if (!((lab == 1 && is_in_string(LABEL_CHARS, str[i]) == 1)
		 || (lab == 0 && i == 0 && str[i] == '-')))
	return (-1 + my_fputstr(2, ERR_FORMAT, line, ERR_IND, str));
      i += 1;
    }
  if (lab > 1)
    return (-1 + my_fputstr(2, ERR_FORMAT, line, ERR_IND, str));
  return (0);
}

int	check_indirect(char *src, int line)
{
  char  *str;

  if ((str = my_strdup(src)) == NULL)
    return (-1);
  if (remove_space(str) == -1
      || my_strlen(str) == 0)
    {
      free(str);
      return (-1 + my_fputstr(2, ERR_FORMAT, line, ERR_IND, str));
    }
  if (check_arg_indirect(str, line) == -1)
    {
      free(str);
      return (-1);
    }
  free(str);
  return (IND_SIZE);
}
