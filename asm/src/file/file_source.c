/*
** file_source.c for src in /home/sylvain.lefevre/git/CPE_2016_corewar/asm/src
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Thu Mar 23 15:01:51 2017 Sylvain Lefevre
** Last update Thu Mar 23 15:01:51 2017 Sylvain Lefevre
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "asm.h"
#include "errors.h"
#include "my.h"
#include "file.h"
#include "gnl.h"

int	get_fd_s_file(char *file_name)
{
  int	fd;
  char	*file_name_new;

  if (!(file_name_new = malloc(sizeof(char) * my_strlen(file_name)
			       + my_strlen(SOURCE_EXT) + 1)))
    return (0);
  file_name_new[0] = '\0';
  my_strcat(file_name_new, file_name);
  if (my_strlen(file_name_new) >= my_strlen(SOURCE_EXT))
    if (my_strcmp(&file_name_new[my_strlen(file_name_new)
		  - my_strlen(SOURCE_EXT)], SOURCE_EXT) != 0)
      my_strcat(file_name_new, SOURCE_EXT);
  fd = open(file_name_new, O_RDONLY);
  if (fd <= 0)
    my_fputstr(1, ERR_FORMAT_WL, ERR_INV_FILE, file_name_new);
  free(file_name_new);
  return (fd);
}

char		**t_file_to_char(t_file *file_list)
{
  char		**file;
  t_file	*file_temp;
  unsigned int	i;

  if (!(file = malloc(sizeof(char *) * (t_file_len(file_list) + 1))))
    return (free_file_list(file_list));
  i = 0;
  while (file_list)
    {
      file[i++] = file_list->line;
      file_temp = file_list;
      file_list = file_list->next;
      free(file_temp);
    }
  file[i] = NULL;
  return (file);
}

char		**get_all_file(char *file_name)
{
  int		fd;
  char		*line;
  t_file_info	*file_info;
  t_file	*file_temp;

  if ((fd = get_fd_s_file(file_name)) <= 0)
    return (NULL);
  if (!(file_info = malloc(sizeof(t_file_info))))
    return (NULL);
  file_info->first = NULL;
  while ((line = get_next_line(fd)))
    if (!(append_in_file(file_info, line)))
      {
	free(file_info);
	return (NULL);
      }
  close(fd);
  file_temp = file_info->first;
  free(file_info);
  return (t_file_to_char(file_temp));
}
