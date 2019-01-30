/*
** get_opt.c for src in /home/sylvain.lefevre/git/CPE_2016_corewar/asm/src
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Tue Feb 28 18:10:28 2017 Sylvain Lefevre
** Last update Wed Mar 15 14:10:55 2017 Elodie Billiot
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "op.h"
#include "arg.h"

int	set_cmd(char *cmd[NBR_CMD])
{
  int	i;

  i = -1;
  while (op_tab[++i].mnemonique != NULL)
    cmd[i] = op_tab[i].mnemonique;
  cmd[COMMENT_ID] = COMMENT_CMD_STRING;
  cmd[NAME_ID] = NAME_CMD_STRING;
  cmd[i + 2] = NULL;
  return (EXIT_SUCCESS);
}

int	my_strcmp_cmd(char *line, char *cmd)
{
  int	i;

  i = 0;
  if (!line || !cmd)
    return (EXIT_SUCCESS);
  while (line[i] != '\0' && cmd[i] != '\0')
    {
      if (line[i] != cmd[i])
	return (line[i] - cmd[i]);
      i += 1;
    }
  if (line[i] == SPACE_CHAR)
    return (EXIT_SUCCESS);
  return (line[i] - cmd[i]);
}

int	remove_space_tab(char *str)
{
  int	i;
  int	padding;
  int	quotes;

  i = 0;
  padding = 0;
  quotes = 0;
  if (!str)
    return (EXIT_FAILURE);
  while (str[i + padding])
    {
      if (!quotes)
	while (str[i + padding] == SPACE_CHAR || str[i + padding] == TAB_CHAR)
	  padding += 1;
      if (str[i + padding] == STRING_SEP)
	quotes = (quotes) ? 0 : 1;
      str[i] = str[i + padding];
      if (str[i + padding])
	i += 1;
    }
  str[i] = '\0';
  return (EXIT_SUCCESS);
}

int	get_cmd_id(char *cmd[NBR_CMD], char *str)
{
  int	i;

  i = 0;
  while (my_strcmp_cmd(str, cmd[i]) != 0 && cmd[i])
    i += 1;
  return (i);
}
