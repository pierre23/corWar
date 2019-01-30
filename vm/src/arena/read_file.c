/*
** read_file.c for arena in /home/sylvain.lefevre/git/CPE_2016_corewar/vm/src/arena
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Thu Mar 09 11:54:09 2017 Sylvain Lefevre
** Last update Wed Mar 15 14:24:18 2017 Elodie Billiot
*/

#include <unistd.h>
#include "op.h"
#include "my.h"
#include "vm.h"

unsigned int	read_uns_int_fd(int fd)
{
  unsigned int	nbr;
  unsigned char	nbr_temp;
  unsigned int	i;

  i = 0;
  nbr = 0;
  nbr_temp = 0;
  while (i++ < sizeof(int))
    {
      if (read(fd, &nbr_temp, 1) <= 0)
	return (0);
      nbr = nbr + (nbr_temp << 8 * (sizeof(int) - i));
    }
  return (nbr);
}

unsigned int	read_uns_int_buffer(char *buffer)
{
  unsigned int	i;
  unsigned int	nbr;

  i = 0;
  nbr = 0;
  while (i < sizeof(int))
    {
      nbr = nbr + ((unsigned char)buffer[i] << 8 * (sizeof(int) - (i + 1)));
      i += 1;
    }
  return (nbr);
}

int		check_valid_cor(int fd)
{
  if (read_uns_int_fd(fd) != COREWAR_EXEC_MAGIC)
    return (0);
  return (1);
}
