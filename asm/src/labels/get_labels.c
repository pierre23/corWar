/*
** get_labels.c for src in /home/sylvain.lefevre/git/CPE_2016_corewar/asm/src
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Tue Feb 28 17:07:30 2017 Sylvain Lefevre
** Last update Wed Mar 15 14:12:38 2017 Elodie Billiot
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"
#include "op.h"
#include "errors.h"

int	check_label(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str[i] != LABEL_CHAR)
    {
      if (!is_in_string(LABEL_CHARS, str[i]))
	return (EXIT_FAILURE);
      i += 1;
    }
  if (str[i] == LABEL_CHAR && i > 0)
    return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

t_labels	*set_labels_line(char **file, t_labels *label,
				 int address, int *y)
{
  t_labels	*temp;

  if (check_label(file[*y]) == EXIT_SUCCESS)
    {
      temp = label;
      if (!(label = put_in_labels(label, file[*y], address, *y)))
	{
	  *y = -1;
	  return (free_labels(temp));
	}
      file[*y] = &file[*y][my_strlen(label->name) + 1];
      remove_useless(file[*y]);
    }
  return (label);
}

int	call_labels(int cmd_id, char *str, t_header *header, int line)
{
  if (my_strlen(str) == 0)
    return (0);
  if (cmd_id < NBR_CMD && cmd_id != COMMENT_ID && cmd_id != NAME_ID)
    return (calc_address(cmd_id, str, line));
  else if (cmd_id == COMMENT_ID)
    return (set_comment(str, header, line));
  else if (cmd_id == NAME_ID)
    return (set_name(str, header, line));
  else
    return (-1 + my_fputstr(2, ERR_FORMAT_WL, ERR_INV_INST, str));
  return (0);
}

t_labels	*free_set_labels(char **cmd, t_labels *labels, int *err)
{
  free(cmd);
  free_labels(labels);
  *err = 1;
  return (NULL);
}

t_labels	*set_labels(char **file, t_header *header, int *err)
{
  t_labels	*label;
  int		y;
  unsigned int	address;
  int		cmd_id;
  char		**cmd;

  label = NULL;
  y = -1;
  if (!(cmd = malloc(sizeof(char *) * (NBR_CMD + 1))) || (address = 0))
    return (free_set_labels(NULL, NULL, err));
  set_cmd(cmd);
  while (file[++y])
    {
      label = set_labels_line(file, label, address, &y);
      if (y < 0)
	return (free_set_labels(cmd, NULL, err));
      cmd_id = get_cmd_id(cmd, file[y]);
      if ((cmd_id = call_labels(cmd_id, &file[y][my_strlen(cmd[cmd_id])],
				header, y + 1)) < 0)
	return (free_set_labels(cmd, label, err));
      address += cmd_id;
    }
  header->address = address;
  free(cmd);
  return (label);
}
