/*
** file.c for CPE_2016_corewar in /home/sylvain.lefevre/git/CPE_2016_corewar
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Tue Feb 28 15:09:02 2017 Sylvain Lefevre
** Last update Wed Mar 15 14:11:52 2017 Elodie Billiot
*/

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "gnl.h"
#include "op.h"
#include "errors.h"

int		set_file(char *file_name)
{
  char		*cor_file;
  int		fd;

  if (my_strlen(file_name) >= my_strlen(SOURCE_EXT))
    if (my_strcmp(&file_name[my_strlen(file_name)
		  - my_strlen(SOURCE_EXT)], SOURCE_EXT))
      return (-1);
  if (!(cor_file = malloc(sizeof(char) * (my_strlen(file_name) + 1
					  + my_strlen(COR_EXT)))))
    return (-1);
  cor_file[0] = '\0';
  my_strcat(cor_file, get_file_name(file_name));
  if (my_strlen(file_name) >= my_strlen(SOURCE_EXT))
    if (my_strcmp(&file_name[my_strlen(file_name)
		  - my_strlen(SOURCE_EXT)], SOURCE_EXT) == 0)
      cor_file[my_strlen(get_file_name(file_name))
      - my_strlen(SOURCE_EXT)] = '\0';
  my_strcat(cor_file, COR_EXT);
  fd = open(cor_file, O_CREAT | O_WRONLY, 0644);
  free(cor_file);
  return (fd);
}

char	**realloc_tab(char **tab, int size)
{
  char	**new;
  int	y;

  if (!(new = malloc(sizeof(char *) * (size + 2))))
    {
      free_char_array(tab);
      return (NULL);
    }
  y = 0;
  if (tab)
    while (y < size)
      {
	new[y] = tab[y];
	y += 1;
      }
  free(tab);
  new[y] = NULL;
  new[y + 1] = NULL;
  return (new);
}

int	remove_useless(char *str)
{
  int	i;
  int	padding;

  i = 0;
  padding = 0;
  if (!str)
    return (EXIT_FAILURE);
  while (str[i + padding] == SPACE_CHAR || str[i + padding] == TAB_CHAR)
    padding += 1;
  while (str[i + padding])
    {
      if (str[i + padding] == COMMENT_CHAR || str[i + padding] == S_COM_CHAR)
	str[i + padding] = '\0';
      str[i] = str[i + padding];
      if (str[i] == TAB_CHAR)
	str[i] = SPACE_CHAR;
      if (str[i + padding])
	i += 1;
    }
  str[i] = '\0';
  return (EXIT_SUCCESS);
}

char	**free_file(char **file, char *file_name, int fd, int err)
{
  if (err)
    my_fputstr(2, ERR_FORMAT_WL, ERR_INV_FILE, file_name);
  if (fd > 0)
    close(fd);
  free(file_name);
  free(file);
  return (NULL);
}
