/*
** address.c for src in /home/sylvain.lefevre/git/CPE_2016_corewar/asm/src
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Sun Mar 05 19:33:37 2017 Sylvain Lefevre
** Last update Wed Mar 15 14:09:48 2017 Elodie Billiot
*/

#include "fonctions.h"
#include "asm.h"
#include "my.h"

int	calc_address(int cmd_id, char *str, int line)
{
  int	nbr;

  if ((nbr = calc_bytes(cmd_id, str, line)) < 0)
    return (-1);
  nbr += SIZE_OF_ARGS(op_tab[cmd_id].nbr_args);
  if (cmd_id == AFF_ID)
    nbr += 1;
  return (nbr);
}
