/*
** main.c for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/vm/src/parsing_arg
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Thu Mar  9 11:33:12 2017 PierreL
** Last update Mon Mar 27 12:07:27 2017 ugo lafaille
*/

#include <unistd.h>
#include "my_vm_ar.h"
#include "vm.h"
#include "my.h"
#include "champ.h"

int		main(int ac, char **av)
{
  t_champ	*s;
  int		i;
  char		*arena;

  if (ac == 1)
    return (84);
  i = 0;
  if (!(arena = create_arena()))
    return (84);
  if ((s = put_arg_in_link(av, &i)) == NULL)
    return (84);
  print_link(s);
  if (create_champ_from_list(s))
    return (84);
  print_link(s);
  if (place_champs(s, arena) == -1)
    return (84);
  print_link(s);
  return (0);
}
