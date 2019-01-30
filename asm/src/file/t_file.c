/*
** t_file.c for src in /home/sylvain.lefevre/git/CPE_2016_corewar/asm/src
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Thu Mar 23 14:47:33 2017 Sylvain Lefevre
** Last update Thu Mar 23 14:47:33 2017 Sylvain Lefevre
*/

#include <stdlib.h>
#include "file.h"
#include "asm.h"
#include "my.h"

void		print_file(t_file *file)
{
  while (file)
    {
      my_fputstr(1, "file: %s\n", file->line);
      file = file->next;
    }
}

void		*free_file_list(t_file *file)
{
  t_file	*temp;

  while (file)
    {
      temp = file;
      file = file->next;
      free(temp);
    }
  return (NULL);
}

unsigned int	t_file_len(t_file *file)
{
  unsigned int	i;

  i = 0;
  while (file)
    {
      i += 1;
      file = file->next;
    }
  return (i);
}

t_file		*append_in_file(t_file_info *file, char *line)
{
  t_file	*new;

  if (!(new = malloc(sizeof(t_file))))
    return (free_file_list(file->first));
  remove_useless(line);
  new->line = line;
  new->next = NULL;
  if (file->first == NULL)
    {
      file->first = new;
      file->last = new;
    }
  else
    {
      file->last->next = new;
      file->last = new;
    }
  return (new);
}
