/*
** dump.c for loop in /home/sylvain.lefevre/git/CPE_2016_corewar/vm/src/loop
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Sun Mar 12 17:12:30 2017 Sylvain Lefevre
** Last update Wed Mar 15 14:32:43 2017 Elodie Billiot
*/

#include "vm.h"
#include "my.h"
#include "op.h"

int	put_char_hex(unsigned char c)
{
  if (c / 16 < 10)
    my_fputstr(1, "%c", c / 16 + '0');
  else
    my_fputstr(1, "%c", c / 16 + 'A' - 10);
  if (c % 16 < 10)
    my_fputstr(1, "%c", c % 16 + '0');
  else
    my_fputstr(1, "%c", c % 16 + 'A' - 10);
  return (0);
}

void	put_addr_label(int nbr)
{
  int	i;

  i = 4;
  while (i >= 0)
    {
      if (nbr / my_pow(16, i) % 16 < 10)
	my_fputstr(1, "%c", (nbr / my_pow(16, i)) % 16 + '0');
      else
	my_fputstr(1, "%c", (nbr / my_pow(16, i)) % 16 - 10 + 'A');
      i -= 1;
    }
  my_fputstr(1, ": ");
}

int	dump_mem(char *arena)
{
  int	i;

  i = 0;
  while (i < MEM_SIZE)
    {
      if (!(i % 32))
	{
	  my_fputstr(1, "\n\033[32m");
	  put_addr_label(i);
	  my_fputstr(1, "\033[m");
	}
      put_char_hex((unsigned char)arena[i]);
      my_fputstr(1, " ");
      i += 1;
    }
  my_fputstr(1, "\n");
  return (0);
}
