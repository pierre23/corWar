/*
** label_list.c for src in /home/sylvain.lefevre/git/CPE_2016_corewar/asm/src
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Wed Mar 01 19:24:33 2017 Sylvain Lefevre
** Last update Wed Mar 15 14:16:12 2017 Elodie Billiot
*/

#include <stdlib.h>
#include "op.h"
#include "asm.h"
#include "my.h"
#include "errors.h"

int		print_labels(t_labels *start)
{
  t_labels	*label;

  label = start;
  my_fputstr(1, "\n\n=================LABELS=================\n\n");
  while (label)
    {
      my_fputstr(1, "label: name: %s, address: %d\n",
		 label->name, label->address);
      label = label->next;
    }
  return (EXIT_SUCCESS);
}

char		*get_label_name(char *str)
{
  char		*new;
  int		i;

  if (!str)
    return (EXIT_MALLOC);
  if (!(new = malloc(sizeof(char) * my_strlen(str))))
    return (EXIT_MALLOC);
  i = 0;
  while (str[i] != LABEL_CHAR)
    {
      new[i] = str[i];
      i += 1;
    }
  new[i] = '\0';
  return (new);
}

int	is_in_labels(t_labels *labels, char *name, int line)
{
  while (labels)
    {
      if (my_strcmp(labels->name, name) == 0)
	return (1 + my_fputstr(2, ERR_FORMAT, line, ERR_MUL_DLAB, name));
      labels = labels->next;
    }
  return (0);
}

t_labels	*put_in_labels(t_labels *old, char *str,
			       int address, int line)
{
  t_labels	*new;
  char		*name;

  if (!(name = get_label_name(str)))
    return (NULL);
  if (is_in_labels(old, name, line))
    {
      free(name);
      return (NULL);
    }
  if (!(new = malloc(sizeof(t_labels))))
    {
      free(name);
      return (NULL);
    }
  new->next = old;
  new->address = address;
  new->name = name;
  return (new);
}

t_labels	*free_labels(t_labels *label)
{
  t_labels	*temp;

  while (label)
    {
      temp = label->next;
      free(label->name);
      free(label);
      label = temp;
    }
  return (EXIT_MALLOC);
}
