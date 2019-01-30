/*
** verif_args.c for  in /home/elodie.billiot/Corewar/CPE_2016_corewar/asm/src/fonctions
** 
** Made by Elodie Billiot
** Login   <elodie.billiot@epitech.net>
** 
** Started on  Mon Mar  6 07:29:15 2017 Elodie Billiot
** Last update Thu Mar 23 15:21:12 2017 ugo lafaille
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "fonctions.h"
#include "asm.h"
#include "my.h"
#include "errors.h"

int	verif_args(char str, char *src, int line)
{
  remove_space(src);
  if (str & T_REG && src[0] == 'r')
    return (check_register(src, line));
  else if (str & T_DIR && src[0] == DIRECT_CHAR)
    return (check_direct(src, line));
  else if (str & T_IND)
    return (check_indirect(src, line));
  return (-1 + my_fputstr(2, ERR_FORMAT, line, ERR_ARG, src));
}
