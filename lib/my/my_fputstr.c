/*
** my_putstr.c for my_putstr in /home/sylvain.lefevre/git/CPool_Day04
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Thu Oct  6 08:04:58 2016 Sylvain Lefevre
** Last update Sun Feb 12 14:27:58 2017 Sylvain Lefevre
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int	my_strlen(const char *str)
{
  int	i;

  if (!str)
    return (0);
  i = 0;
  while (str[i])
    i += 1;
  return (i);
}

int	my_pow(int nbr, int n)
{
  if (n <= 0)
    return (1);
  return (nbr * (my_pow(nbr, n - 1)));
}

char	*int_to_str(int nbr)
{
  char	*str;
  int	pos;
  int	i;
  int	temp;

  i = 1;
  if (!(str = malloc(sizeof(char) * (15))) || (pos = 0))
    return (NULL);
  if (nbr < 0)
    {
      str[pos++] = '-';
      nbr = -nbr;
    }
  while (my_pow(10, i) <= nbr && i < 11)
    i += 1;
  i -= 1;
  while (i >= 0)
    {
      temp = nbr / my_pow(10, i);
      str[pos] = (temp % 10) + '0';
      pos += 1;
      i -= 1;
    }
  str[pos] = '\0';
  return (str);
}

int	modulo_err(int fd, char *str, va_list args_list)
{
  int	c;
  char	*temp;

  if (str[0] == 's')
    {
      if ((temp = va_arg(args_list, char *)))
	write(fd, temp, my_strlen(temp));
      else
	write(fd, "(null)", 6);
      return (1);
    }
  if (str[0] == 'd')
    {
      temp = int_to_str(va_arg(args_list, int));
      my_fputstr(fd, temp);
      if (temp)
	free(temp);
      return (1);
    }
  if (str[0] == 'c')
    {
      c = va_arg(args_list, int);
      return (write(fd, &c, 1) == 1 ? 1 : 1);
    }
  return (0);
}

int		my_fputstr(int fd, char *str, ...)
{
  int		i;
  int		i2;
  va_list	args_list;

  i = 0;
  va_start(args_list, str);
  if (str)
    while (str[i])
      {
	i2 = 0;
	while (str[i + i2] != '%' && str[i + i2])
	  i2 += 1;
	if (i + i2 > i)
	  write(fd, &str[i], i2);
	if (str[i + i2])
	  i2 += 1 + modulo_err(fd, &str[i + i2 + 1], args_list);
	i += i2;
      }
  else
    write(fd, "(null)", 6);
  va_end(args_list);
  return (0);
}
