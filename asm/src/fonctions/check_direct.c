/*
** zjmp.c for  in /home/ugolaf/delivery/CPE_2016_corewar
** 
** Made by ugo lafaille
** Login   <ugolaf@epitech.net>
** 
** Started on  Tue Feb 28 20:20:30 2017 ugo lafaille
** Last update Thu Mar 23 13:01:14 2017 ugo lafaille
*/

#include <stdlib.h>
#include "my.h"
#include "fonctions.h"
#include "asm.h"
#include "op.h"
#include "errors.h"

int	change_nbr(char *str, int i, int nbr)
{
  if (nbr == 0)
    nbr = str[i] - 48;
  else
    {
      if ((str[i] - 48) + (10 * nbr) >= 0)
	nbr = (str[i] - 48) + (10 * nbr);
    }
  return (nbr);
}

int	check_arg_direct(char *str, int line)
{
  int   i;
  int   val;
  int	nbr;

  i = 0;
  val = 0;
  nbr = 0;
  while (str[i] != '\0')
    {
      if (str[i] == DIRECT_CHAR && val == 0)
	  val += 1;
      else if (str[i] == LABEL_CHAR && val == 1)
	  val += 1;
      else if (str[i] >= '0' && str[i] <= '9'  && val == 1 && nbr >= 0)
	nbr = change_nbr(str, i, nbr);
      else if (val >= 2 && is_in_string(LABEL_CHARS, str[i]) == 1)
	val += 1;
      else if (!(val == 1 && i == 1 && str[i] == '-'))
	return (-1 + my_fputstr(2, ERR_FORMAT, line, ERR_DIR, str));
      i += 1;
    }
  if (val == 0)
    return (-1);
  return (0);
}

int	check_direct(char *src, int line)
{
  char  *str;

  if ((str = my_strdup(src)) == NULL)
    return (-1);
  if (remove_space(str) == -1
      || my_strlen(str) <= 1)
    return (-1 + my_fputstr(2, ERR_FORMAT, line, ERR_DIR, str));
  if (check_arg_direct(str, line) == -1)
    return (-1);
  free(str);
  return (DIR_SIZE);
}
