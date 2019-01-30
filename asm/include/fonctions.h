/*
** fonctions.h for  in /home/ugolaf/delivery/CPE_2016_corewar/include
** 
** Made by ugo lafaille
** Login   <ugolaf@epitech.net>
** 
** Started on  Thu Mar  2 14:23:20 2017 ugo lafaille
** Last update Thu Mar 23 13:00:22 2017 ugo lafaille
*/

#ifndef FONCTIONS_H_
# define FONCTIONS_H_

int	calc_bytes(int, char *, int);
int	free_tab(char **);
int	check_virgule(char *);
int	remove_space(char *);
int	change_nbr(char *, int, int);
int	verif_args(char, char *, int);
int	check_register(char *, int);
int	check_indirect(char *, int);
int	check_direct(char *, int);

#endif /* !FONCTIONS_H_ */
