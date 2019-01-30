/*
** calc_bytes.c for  in /home/ugolaf/delivery/CPE_2016_corewar/asm/src/fonctions
** 
** Made by ugo lafaille
** Login   <ugolaf@epitech.net>
** 
** Started on  Mon Mar  6 10:59:22 2017 ugo lafaille
** Last update Thu Mar 23 14:25:25 2017 ugo lafaille
*/

#include <stdlib.h>
#include "fonctions.h"
#include "op.h"
#include "asm.h"
#include "fonctions.h"
#include "my.h"
#include "errors.h"

int	verif_nb_args(char **tab, int nbr)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (my_strcmp(tab[i], "") == 0)
	return (-1);
      i += 1;
    }
  if (i != nbr)
    return (-1);
  return (0);
}

int	compare_args(char *args, char **fonc, int id, int line)
{
  int	i;
  int	ret;
  int	tmp;

  i = 0;
  ret = 0;
  while (fonc[i] != NULL && args[i] != '\0')
    {
      tmp = 0;
      tmp = verif_args(args[i], fonc[i], line);
      if (tmp == -1)
	  return (free_tab(fonc));
      else if (op_tab[id].nbr_cycles >= 20 && tmp == 4)
	ret = ret + IND_SIZE;
      else
	ret = ret + tmp;
      i += 1;
    }
  free_tab(fonc);
  return (ret);
}

int	calc_bytes(int id, char *str, int line)
{
  char	**fonc;
  int	nb_fonc;

  nb_fonc = check_virgule(str) + 1;
  if ((fonc = my_str_to_wordtab(str, ',')) == NULL)
    return (-1);
  if (verif_nb_args(fonc, nb_fonc) == -1)
    {
      free_tab(fonc);
      my_fputstr(2, ERR_FORMAT, line, ERR_NBARG, "");
      return (-1);
    }
  if (op_tab[id].nbr_args != nb_fonc)
    {
      free_tab(fonc);
      my_fputstr(2, ERR_FORMAT, line, ERR_NBARG, "");
      return (-1);
    }
  return (compare_args(op_tab[id].type, fonc, id, line));
}
