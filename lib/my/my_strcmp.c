/*
** my_strcmp.c for my_strcmp in /home/sylvain.lefevre/git/CPool_Day06
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Mon Oct 10 12:50:18 2016 Sylvain Lefevre
** Last update Tue Feb 28 15:19:24 2017 PierreL
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  if (str)
    while (str[i])
      {
	if (str[i] >= 'a' && str[i] <= 'z')
	  str[i] = str[i] - 'a' + 'A';
	i += 1;
      }
  return (0);
}

int	is_in_string(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i])
    if (str[i++] == c)
      return (1);
  return (0);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (0);
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i = i + 1;
    }
  return (0);
}

int	my_arr_len(char **arr)
{
  int	i;

  i = 0;
  while (arr[i])
    i += 1;
  return (i);
}
