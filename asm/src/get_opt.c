/*
** get_opt.c for src in /home/sylvain.lefevre/git/CPE_2016_corewar/asm/src
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Tue Feb 28 18:10:28 2017 Sylvain Lefevre
** Last update Fri Mar 31 15:49:11 2017 PierreL
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "op.h"
#include "arg.h"
#include "errors.h"

int		free_opt(char **cmd, char *buffer, int error)
{
  free(cmd);
  free(buffer);
  if (error != -1)
    my_fputstr(2, ERR_FORMAT, error, ERR_LABEL, "");
  return (84);
}

int		output_to_file_loop(char **cmd, char *file,
				 int *address, t_labels *labels)
{
  t_arg		*args;
  int		y;

  y = get_cmd_id(cmd, file);
  remove_space_tab(file);
  if (y < NBR_CMD && y != COMMENT_ID && y != NAME_ID)
    {
      if (!(args = pars_arg(labels, &file[my_strlen(cmd[y])],
			    *address)))
	return (84);
      put_hex((y + 1), 1);
      *address += calc_address(y, &file[my_strlen(cmd[y])], 0);
      print_arg(args, y);
      free_struct(args, NULL);
    }
  return (0);
}

int		output_to_file(char **file, t_labels *labels, t_header *header)
{
  int		i;
  char		**cmd;
  int		address;
  char		*buffer;

  i = 0;
  address = 0;
  if (!(buffer = malloc(sizeof(char *) * (header->address + 1))))
    return (84);
  if (!(cmd = malloc(sizeof(char *) * (NBR_CMD + 1))))
    return (free_opt(NULL, buffer, -1));
  set_cmd(cmd);
  while (file[i])
    {
      if (output_to_file_loop(cmd, file[i], &address, labels))
	return (free_opt(cmd, buffer, (i + 1)));
      i += 1;
    }
  free_opt(cmd, buffer, -1);
  return (EXIT_SUCCESS);
}
