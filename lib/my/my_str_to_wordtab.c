/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/sylvain.lefevre/git/CPool_Day08/task04
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Wed Oct 12 08:39:05 2016 Sylvain Lefevre
** Last update Thu Mar  2 09:40:26 2017 PierreL
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int	my_strcat(char *dest, char *src)
{
  int	i1;
  int	i2;

  if (!dest || !src)
    return (84);
  i1 = my_strlen(dest);
  i2 = 0;
  while (src[i2])
    dest[i1++] = src[i2++];
  dest[i1] = '\0';
  return (0);
}

int	get_length_tab_alpha(char *str, int position, char delimiter)
{
  int	length;

  length = position;
  while (str[length] != delimiter && str[length])
    length = length + 1;
  return (length);
}

int	affect_case_str(char *new, char *str, int *position, int length)
{
  int	i2;

  i2 = 0;
  while (*position < length && str[*position])
    {
      new[i2] = str[*position];
      i2 += 1;
      *position += 1;
    }
  new[i2] = '\0';
  return (0);
}

char	**my_str_to_wordtab(char *str, char delimiter)
{
  char	**new;
  int	position;
  int	i;
  int	length;

  i = 0;
  position = 0;
  if (!str)
    return (NULL);
  if (!(new = malloc(sizeof(char *) * (my_strlen(str) * 3))))
    return (NULL);
  while (str[position])
    {
      new[i] = NULL;
      if (str[position] == delimiter)
	position = position + 1;
      length = get_length_tab_alpha(str, position, delimiter);
      if (!(new[i] = malloc(sizeof(char) * ((length - position + 1)))))
	return (free_arr(new));
      affect_case_str(new[i], str, &position, length);
      i = i + 1;
    }
  new[i] = NULL;
  return (new);
}
