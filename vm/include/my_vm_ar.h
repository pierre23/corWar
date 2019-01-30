/*
** my_vm_ar.h for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/include
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Thu Mar  9 11:40:23 2017 PierreL
** Last update Fri Mar 31 17:40:48 2017 PierreL
*/

#ifndef MY_VM_AR_H_
# define MY_VM_AR_H_

# include "op.h"

# define EXIT_ERROR	84
# define EXIT_OK	0
# define EXIT_KO	0
# define EXIT_FLAG	2

# define DEFAULT_VALUE  -1
# define DEFAULT_DUMP	0
# define JUMP_DUMP_V	3

# define DUMP_FLAG	"-dump"
# define CHAR_FLAG	'-'
# define PROG_NBR_FLAG	"-n"
# define LOAD_ADR_FLAG	"-a"

# define MAX_CHAMP	3

typedef struct		s_champ
{
  char			*file_name;
  int			prog_nbr;
  int			load_adress;
  char			name[PROG_NAME_LENGTH + 1];
  char			comment[COMMENT_LENGTH + 1];
  unsigned int		size;
  char			*content;
  unsigned int		defeat_pos;
  struct s_champ	*next;
}			t_champ;

void            *free_struct(t_champ *, char *, char *);
void		print_link(t_champ *);
int             my_put_dump(int *, char **);
t_champ         *put_arg_list(t_champ *, char **, int);
t_champ         *put_arg_in_link(char **, int *);
t_champ         *complet_nbr(t_champ *);
int             numbr_is_ok(t_champ *, int);
t_champ         *my_put_load_adr(t_champ *, char *);
t_champ         *my_put_prog_nbr(t_champ *, t_champ *, char *);
t_champ         *new_link(t_champ *);

#endif /* !MY_VM_AR_H_ */
