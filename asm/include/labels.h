/*
** asm_labels.h for include in /home/sylvain.lefevre/git/CPE_2016_corewar/include
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Wed Mar 22 21:44:21 2017 Sylvain Lefevre
** Last update Wed Mar 22 21:44:21 2017 Sylvain Lefevre
*/

#ifndef ASM_LABELS_H_
# define ASM_LABELS_H_

typedef struct		s_labels
{
  char			*name;
  int			address;
  struct s_labels	*next;
}			t_labels;

t_labels	*free_labels(t_labels *);
t_labels	*put_in_labels(t_labels *, char *, int, int);
t_labels	*set_labels(char **, t_header *, int *);
int		print_labels(t_labels *);

#endif	/* ASM_LABELS_H_ */
