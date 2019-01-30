/*
** asm.c for src in /home/sylvain.lefevre/git/CPE_2016_corewar/asm/src
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Mon Mar 06 19:48:07 2017 Sylvain Lefevre
** Last update Mon Mar 06 19:48:07 2017 Sylvain Lefevre
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "asm.h"

int	file_len(char **file)
{
  int	i;

  i = 0;
  if (!file)
    return (0);
  while (file[i])
    i += 1;
  return (i);
}

char	**back_file(char **file)
{
  int	i;
  char	**back;

  i = 0;
  if (!file)
    return (NULL);
  if (!(back = malloc(sizeof(char *) * (file_len(file) + 1))))
    return (NULL);
  while (file[i])
    {
      back[i] = file[i];
      i += 1;
    }
  back[i] = NULL;
  return (back);
}

int	free_asm(int fd, char **file, char **back, t_labels *labels)
{
  free_char_array(back);
  free_labels(labels);
  free(file);
  if (fd > 0)
    close(fd);
  return (84);
}

int		asm(char *file_name)
{
  int		fd;
  t_labels	*labels;
  t_header	header;
  char		**file;
  char		**back;
  int		err;

  file = get_all_file(file_name);
  back = back_file(file);
  header.action = 0;
  if (!file || !back || (err = 0))
    return (free_asm(0, file, back, NULL));
  labels = set_labels(file, &header, &err);
  if (err)
    return (free_asm(0, file, back, NULL));
  if (print_fd(0, 0, header.address) == 84)
    return (free_asm(0, file, back, labels));
  if (print_header(&header))
    return (free_asm(0, file, back, labels));
  if (output_to_file(file, labels, &header))
    return (free_asm(0, file, back, labels));
  if ((fd = set_file(file_name)) <= 0)
    return (free_asm(fd, file, back, labels));
  print_fd(fd, 1);
  return (free_asm(fd, file, back, labels) - 84);
}
