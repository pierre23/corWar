/*
** print.c for src in /home/sylvain.lefevre/git/CPE_2016_corewar/asm/src
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Mon Mar 06 18:53:41 2017 Sylvain Lefevre
** Last update Wed Mar 15 14:16:26 2017 Elodie Billiot
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "asm.h"
#include "my.h"

int		put_hex(int nbr, unsigned int size)
{
  unsigned int	i;

  i = (size <= 0) ? sizeof(int) : size;
  while (i > sizeof(int))
    {
      if (nbr >= 0)
	print_fd(0x00, 0);
      else
	print_fd(-1, 0);
      i -= 1;
    }
  while (i > 0)
    print_fd((nbr >> --i * BIT_IN_BYTE) & 0xFF, 0);
  return (EXIT_SUCCESS);
}

char	*set_fd_buffer(int *size, va_list args_list)
{
  char	*temp;

  *size = (va_arg(args_list, int) + PROG_NAME_LENGTH + COMMENT_LENGTH + 20);
  if (!(temp = malloc(sizeof(char) * (*size + 2))))
    return (NULL);
  return (temp);
}

int			print_fd(char c, char print, ...)
{
  static char		*buf = NULL;
  static int		pos = 0;
  static int		size = 0;
  va_list		args_list;

  if (buf == NULL && size == 0)
    {
      va_start(args_list, print);
      buf = set_fd_buffer(&size, args_list);
      va_end(args_list);
      if (!buf)
	return (84);
      return (0);
    }
  if (pos < size && buf && !print)
    buf[pos++] = c;
  if (print && buf)
    {
      buf[pos] = '\0';
      write(c, buf, pos);
      free(buf);
      buf = NULL;
    }
  return (0);
}

int	print_str_fd(char *str, int size)
{
  int	i;

  i = 0;
  while (i < size)
    print_fd(str[i++], 0);
  return (0);
}
