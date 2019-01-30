/*
** my_strdup.c for tetris in /home/sylvain.lefevre/git/PSU_2016_tetris/input
** 
** Made by Sylvain Lefevre
** Login   <sylvain-lefevre@epitech.net>
** 
** Started on  Mon Feb 20 12:12:22 2017 Sylvain Lefevre
** Last update Tue Feb 28 15:22:28 2017 PierreL
*/

#include <stdlib.h>
#include "my.h"

char	**free_arr(char **arr)
{
  int	i;

  i = 0;
  while (arr[i])
    free(arr[i++]);
  free(arr);
  return (NULL);
}

char	**my_arrdup(char **src)
{
  int	i;
  char	**new;

  i = 0;
  if (!(new = malloc(sizeof(char *) * (my_arr_len(src)))))
    return (NULL);
  while (src[i])
    {
      if (!(new[i] = my_strdup(src[i])))
	return (free_arr(new));
      i += 1;
    }
  new[i] = NULL;
  return (new);
}

char	*my_strdup(char *src)
{
  char	*dest;
  int	i;

  if (!(src) || (long int)src == -1)
    return (NULL);
  if (!(dest = malloc(sizeof(char) * (my_strlen(src) + 1))))
      return (NULL);
  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = '\0';
  return (dest);
}
