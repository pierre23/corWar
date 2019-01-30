/*
** my_free.c for navy in /home/sylvain.lefevre/git/PSU_2016_navy
** 
** Made by Sylvain Lefevre
** Login   <sylvain-lefevre@epitech.net>
** 
** Started on  Mon Jan 30 13:26:04 2017 Sylvain Lefevre
** Last update Fri Feb 24 15:31:38 2017 Sylvain Lefevre
*/

#include <stdlib.h>

char	*free_str(char *str)
{
  free(str);
  return (NULL);
}

char	**free_char_array(char **map)
{
  int	i;

  i = 0;
  if (!map)
    return (NULL);
  while (map[i])
    free(map[i++]);
  free(map);
  return (NULL);
}

char    **free_int_tabl(int **map)
{
  int   i;

  i = 0;
  if (!map)
    return (NULL);
  while (map[i] != NULL)
    free(map[i++]);
  free(map);
  return (NULL);
}
