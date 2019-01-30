/*
** file_name.c for src in /home/sylvain.lefevre/git/CPE_2016_corewar/asm/src
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Sun Mar 12 19:12:52 2017 Sylvain Lefevre
** Last update Wed Mar 15 14:12:16 2017 Elodie Billiot
*/

#include "asm.h"
#include "my.h"

char		*get_file_name(char *path)
{
  int		i;

  i = 0;
  while (is_in_string(&path[i], PATH_CHAR))
    i += 1;
  return (&path[i]);
}
