/*
** my_strstr.c for my_strstr in /home/sylvain.lefevre/git/CPool_Day06
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Mon Oct 10 08:06:31 2016 Sylvain Lefevre
** Last update Mon Feb 20 16:27:20 2017 Sylvain Lefevre
*/

#include <stdlib.h>
#include "my.h"

int	check_occurence(char *str, char *to_find,
			int positionstr, int positionfind)
{
  if (!to_find[positionfind])
    return (1);
  if (!str[positionstr])
    return (0);
  if (str[positionstr] == to_find[positionfind])
    return (check_occurence(str, to_find,
			    (positionstr + 1), (positionfind + 1)));
  return (0);
}

char	*my_strstr(char *str, char *to_find)
{
  int	i;

  i = 0;
  if (!str || !to_find)
    return (NULL);
  while (str[i] != '\0')
    {
      if (check_occurence(str, to_find, i, 0))
	return (&str[i]);
      i = i + 1;
    }
  return (NULL);
}

char	*my_strstr_args(char *str, char *to_find)
{
  if (!str || !to_find)
    return (NULL);
  if (check_occurence(str, to_find, 0, 0))
    return (str);
  return (NULL);
}
