/*
** t_header.c for src in /home/sylvain.lefevre/git/CPE_2016_corewar/asm/src
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Wed Mar 01 19:58:44 2017 Sylvain Lefevre
** Last update Wed Mar 15 14:17:22 2017 Elodie Billiot
*/

#include "op.h"
#include "errors.h"
#include "asm.h"
#include "my.h"

int	print_str_size(char *str, int size)
{
  int	i;

  i = 0;
  while (i < size)
    print_fd(str[i++], 0);
  return (EXIT_SUCCESS);
}

int	print_header(t_header *header)
{
  if (header->action != 3)
    {
      if (header->action == 0)
	my_fputstr(2, ERR_FORMAT_WL, ERR_NO_HEAD, "");
      else if (header->action == 1)
	my_fputstr(2, ERR_FORMAT_WL, ERR_NO_COMM, "");
      else
	my_fputstr(2, ERR_FORMAT_WL, ERR_NO_NAME, "");
      return (84);
    }
  put_hex(COREWAR_EXEC_MAGIC, 4);
  print_str_size(header->name, PROG_NAME_LENGTH);
  put_hex(header->address, 8);
  print_str_size(header->comment, COMMENT_LENGTH);
  put_hex(0, 4);
  return (EXIT_SUCCESS);
}

int	set_comment(char *str, t_header *header, int line)
{
  int	i;

  i = 0;
  if (header->action & 0x02)
    return (-1) + my_fputstr(2, ERR_FORMAT, line, ERR_RE_COMM, "");
  header->action += 2;
  remove_space_tab(str);
  if (my_strlen(str) < MIN_SIZE_COMMENT + 2 || my_strlen(str) > COMMENT_LENGTH)
    return (-1 + my_fputstr(2, ERR_FORMAT, line, ERR_COMM, ""));
  if (str[0] != STRING_SEP || str[my_strlen(str) - 1] != STRING_SEP)
    return (-1 + my_fputstr(2, ERR_FORMAT, line, ERR_COMM, ""));
  while (i < COMMENT_LENGTH)
    {
      if (i + 1 < my_strlen(str) - 1)
	{
	  if (str[i + 1] == STRING_SEP)
	    return (-1 + my_fputstr(2, ERR_FORMAT, line, ERR_COMM, ""));
	  header->comment[i] = str[i + 1];
	}
      else
	header->comment[i] = 0x00;
      i += 1;
    }
  header->comment[COMMENT_LENGTH] = 0x00;
  return (0);
}

int	set_name(char *str, t_header *header, int line)
{
  int	i;

  i = 0;
  if (header->action & 0x01)
    return (-1 + my_fputstr(2, ERR_FORMAT, line, ERR_RE_NAME, ""));
  header->action += 1;
  remove_space_tab(str);
  if (my_strlen(str) < MIN_SIZE_NAME + 2 || my_strlen(str) > PROG_NAME_LENGTH)
    return (-1 + my_fputstr(2, ERR_FORMAT, line, ERR_NAME, ""));
  if (str[0] != STRING_SEP || str[my_strlen(str) - 1] != STRING_SEP)
    return (-1 + my_fputstr(2, ERR_FORMAT, line, ERR_NAME, ""));
  while (i < PROG_NAME_LENGTH)
    {
      if (i + 1 < my_strlen(str) - 1)
	{
	  if (str[i + 1] == STRING_SEP)
	    return (-1  + my_fputstr(2, ERR_FORMAT, line, ERR_NAME, ""));
	  header->name[i] = str[i + 1];
	}
      else
	header->name[i] = 0x00;
      i += 1;
    }
  header->name[PROG_NAME_LENGTH] = 0x00;
  return (EXIT_SUCCESS);
}
