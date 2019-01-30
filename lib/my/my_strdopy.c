/*
** my_strdopy.c for  in /home/pierrel/delivery/semestre_2/tetris/PSU_2016_tetris/lib/my
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Fri Feb 24 12:17:28 2017 PierreL
** Last update Sun Feb 26 21:36:30 2017 PierreL
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char	*my_strcopy(char *src, char *dest)
{
  char	*res;
  int	j;
  int	i;

  i = 0;
  j = 0;
  if ((res = malloc(sizeof(char) *my_strlen(src)
		    + my_strlen(dest) + 1)) == NULL)
    return (NULL);
  while (src[i] != 0)
    {
      res[i] = src[i];
      i++;
    }
  while (dest[j] != 0)
    res[i++] = dest[j++];
  res[i] = 0;
  return (res);
}
