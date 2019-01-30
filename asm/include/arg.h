/*
** arg.h for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/include
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Tue Feb 28 14:59:34 2017 PierreL
** Last update Fri Mar 31 15:48:39 2017 PierreL
*/

#ifndef ARG_H_
# define ARG_H_

# include "asm.h"

typedef struct		s_arg
{
  int			value;
  char			type;
  struct s_arg		*next;
}			t_arg;

# define FALSE			1
# define TYPE_REG		1
# define TYPE_DIRECT		2
# define TYPE_INDIRECT		3

# define INDIC_REG		'r'
# define INDIC_INDIRECT_S	'0'
# define INDIC_INDIRECT_I	'9'

# define EXIT_KO		0
# define EXIT_OK		0
# define EXIT_ERROR		84

# define END_OF_STRING		0
# define INIT_VALUE		0
# define NEG_OPERANT		'-'

# define VAL_MAX		'9'
# define VAL_MIN		'0'
# define ONE_TYPE		2

# define SIZE_OF_OCT		8

void		*free_struct(t_arg *, char **str);
void		print_arg(t_arg *ctrl, int);
t_arg           *new_link(t_arg *ctrl);
int             put_value_in_link(t_labels *lab, char *str,
				  int adress, int *err);
t_arg           *put_arg_in_link(t_labels *lab, char *str,
				 t_arg *ctrl, int address);
t_arg           *pars_arg(t_labels *lab, char *tabl, int address);
int		is_it_on_array(char *str, char car);
int		is_good_label(char *str, char *is);
int		put_label_in_link(t_labels *lab, char *name,
				  int address, int *err);
char		find_nbr_arg(t_arg *ctrl);

#endif /* !ARG_H_ */
