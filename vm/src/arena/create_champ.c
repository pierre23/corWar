/*
** create_process.c for arena in /home/sylvain.lefevre/git/CPE_2016_corewar/vm/src/arena
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Thu Mar 09 11:43:24 2017 Sylvain Lefevre
** Last update Mon Mar 27 20:19:43 2017 Sylvain Lefevre
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_vm_ar.h"
#include "vm.h"
#include "champ.h"
#include "errors.h"
#include "my.h"

int	copy_buffer(char *src, char *dest, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      dest[i] = src[i];
      i += 1;
    }
  dest[i] = '\0';
  return (0);
}

int		affect_champ(t_champ *champ, char *buffer)
{
  champ->size = read_uns_int_buffer(&buffer[POS_SIZE]);
  copy_buffer(&buffer[POS_NAME], champ->name, PROG_NAME_LENGTH);
  copy_buffer(&buffer[POS_COMMENT], champ->comment, COMMENT_LENGTH);
  return (0);
}

int		create_champ_from_list(t_champ *champ)
{
  int		fd;
  char		buffer[SIZE_OF_HEADER + 1];

  if (!champ)
    return (0);
  champ->size = -1;
  if ((fd = open(champ->file_name, O_RDONLY)) <= 0)
    return (1 + my_fputstr(2, ERR_FORMAT, ERR_INV_FILE, champ->file_name));
  if (!check_valid_cor(fd))
    return (1 + my_fputstr(2, ERR_FORMAT, ERR_INV_COR, champ->file_name));
  if (read(fd, buffer, SIZE_OF_HEADER) < SIZE_OF_HEADER)
    return (1 + my_fputstr(2, ERR_FORMAT, ERR_INV_HEAD, champ->file_name));
  affect_champ(champ, buffer);
  if (!(champ->content = malloc(sizeof(char) * (champ->size + 1))))
    return (1);
  if (champ->size > MAX_SIZE_CHAMP)
    return (1 + my_fputstr(2, ERR_FORMAT, ERR_BIG_SIZE, champ->file_name));
  if (read(fd, champ->content, champ->size) < champ->size)
    return (1 + my_fputstr(2, ERR_FORMAT, ERR_INV_SIZE, champ->file_name));
  close(fd);
  champ->defeat_pos = 0;
  return (create_champ_from_list(champ->next));
}
