/*
** live.c for loop in /home/sylvain.lefevre/git/CPE_2016_corewar/vm/src/loop
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Sat Mar 11 17:24:12 2017 Sylvain Lefevre
** Last update Mon Mar 27 20:26:22 2017 Sylvain Lefevre
*/

#include <stdlib.h>
#include "loop.h"
#include "process.h"
#include "my.h"
#include "champ.h"
#include "vm.h"

void		*free_live(t_live *lives)
{
  t_live	*temp;

  while (lives)
    {
      temp = lives;
      lives = lives->next;
      free(temp);
    }
  return (NULL);
}

t_live		*create_live()
{
  t_live	*new;

  if (!(new = malloc(sizeof(t_live))))
    return (NULL);
  new->next = NULL;
  new->cid = -1;
  return (new);
}

int		is_champ_in_live(t_live *lives, int cid)
{
  while (lives)
    {
      if (lives->cid == cid)
	return (1);
      lives = lives->next;
    }
  return (0);
}

int		add_in_live_list(t_live *lives,
				 int cid, t_champ *champ)
{
  t_live	*new;

  if (!is_champ_in_live(lives, cid))
    {
      if (!(new = malloc(sizeof(t_live))))
	return (1);
      new->next = lives->next;
      new->cid = cid;
      lives->next = new;
    }
  if ((get_champ_name(champ, cid)))
    my_fputstr(1, LIVE_STRING, cid, get_champ_name(champ, cid));
  return (0);
}
