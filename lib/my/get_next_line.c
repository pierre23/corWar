/*
** get_next_line.c for get_next_line in /home/sylvain.lefevre/git/CPE_2017_getnextline
** 
** Made by Sylvain Lefevre
** Login   <sylvain-lefevre@epitech.net>
** 
** Started on  Mon Jan  2 11:22:42 2017 Sylvain Lefevre
** Last update Mon Feb 27 20:21:34 2017 Sylvain Lefevre
*/

#include <unistd.h>
#include <stdlib.h>
#include "gnl.h"
#include "my.h"

int	get_line_length(char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0' && str[i] != '\n')
    {
      i += 1;
      if (i < 0)
	return (0);
    }
  return (i);
}

int	my_strncpy(char *src, char *dest, int i)
{
  int	pos_str;

  pos_str = 0;
  if (src == NULL || dest == NULL)
    return (1);
  while (src[pos_str] && pos_str < i)
    {
      dest[pos_str] = src[pos_str];
      pos_str += 1;
    }
  dest[pos_str] = '\0';
  return (0);
}

char	*my_strcatgnl(char *str, char *str2)
{
  char	*new;
  int	pos;
  int	pos2;

  if ((str2 == NULL && str[0] == '\0')
      || !(new = malloc(sizeof(char)
			* (get_line_length(str) + get_line_length(str2) + 1))))
    return (free_str(new));
  pos = -1;
  while (str[++pos])
    new[pos] = str[pos];
  pos2 = 0;
  if (str2 != NULL)
    while (str2[pos2])
      {
	new[pos + pos2] = str2[pos2];
	pos2 += 1;
      }
  free(str);
  if (str2 != NULL)
    free(str2);
  new[pos + pos2] = '\0';
  return (new);
}

char	*get_line(char *buf, int *pos, int *end)
{
  char	*str;
  int	temp;
  int	size;

  size = get_line_length(&buf[*pos]);
  str = malloc(sizeof(char) * (size + 1));
  if (my_strncpy(&buf[*pos], str, size))
      return (NULL);
  *pos += size;
  if (buf[*pos] == '\0')
    {
      temp = *pos;
      *pos = 0;
      if (buf[temp] != '\n')
	*end = 0;
    }
  else
    *pos += 1;
  return (str);
}

char		*get_next_line(const int fd)
{
  int		end;
  char		*str;
  static char	buf[MAX_FD][READ_SIZE + 1];
  static int	pos[MAX_FD] = {0};

  str = NULL;
  end = 0;
  while (!end++ && !(fd >= MAX_FD || READ_SIZE <= 0 || fd < 0))
    {
      if (pos[fd] == 0)
	{
	  if ((end = read(fd, buf[fd], READ_SIZE)) < 0)
	    return (NULL);
	  if ((end == 0 && get_line_length(str) > 0) || (buf[fd][end] = '\0'))
	    return (str);
	  else if (end == 0)
	    return (free_str(str));
	}
      if (!(str = (!str) ? get_line(buf[fd], &pos[fd], &end) :
	    my_strcatgnl(str, get_line(buf[fd], &pos[fd], &end))))
	return (NULL);
    }
  return (str);
}
