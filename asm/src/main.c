/*
** main.c for src in /home/sylvain.lefevre/git/CPE_2016_corewar/asm/src
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Tue Feb 28 13:37:16 2017 Sylvain Lefevre
** Last update Thu Mar 23 12:36:05 2017 Elodie Billiot
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "errors.h"
#include "gnl.h"
#include "asm.h"

int	main(int argc, char **argv)
{
  if (argc == 2 && my_strcmp(argv[1], HELP) == 0)
    {
      verbose(argv);
      return (0);
    }
  else if (argc == 2)
    return (asm(argv[1]));
  verbose(argv);
  return (84);
}
