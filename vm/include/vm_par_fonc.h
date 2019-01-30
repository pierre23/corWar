/*
** vm_par_fonc.h for  in /home/pierrel/delivery/semestre_2/corewar/CPE_2016_corewar/vm/src/fonction
** 
** Made by PierreL
** Login   <pierre.leleu@epitech.eu>
** 
** Started on  Sun Mar 12 13:20:45 2017 PierreL
** Last update Wed Mar 29 13:16:16 2017 Elodie Billiot
*/

#ifndef VM_PAR_FONC_H_
# define VM_PAR_FONC_H_

# include "op.h"
# include "vm.h"
# include "process.h"

# define FD_IDX_MOD(x)		(x == DEFAULT_IDX || x == EXCEPTION)\
  ? (IDX_MOD) : (MOD_MAX)

# define EXIT_OK		0
# define EXIT_FAIL		-1
# define EXIT_ERROR		84

# define BAD_IND_FONC		0
# define TABL_INST_SIZE		17

# define MAX_MASK		128
# define ONE_ARG		1

# define DEFAULT		0
# define EXCEPTION		2
# define DEFAULT_IDX		1
# define EXCEPTION_IDX		3
# define MOD_MAX		1000000000

# define REG_TYPE		1
# define DIR_TYPE		2
# define INDIR_TYPE		3
# define REG_MIN		1

# define ERROR_VAL		-48

typedef struct		s_arg_value
{
  int			pos;
  int			pos_in_arg;
  int			arg_nbr;
}			t_arg_value;

int		set_the_carry(int, t_arg_value *, int, t_process *);
int		set_child_process(t_process *);
int		read_int_buffer_nbyte(char *, int, unsigned int);
int		registre_value(t_process *, char *, t_arg_value *);
int		direct_value(char *, t_arg_value *, int);
int		indirect_value(char *, t_arg_value *);
int		check_type_arg(int , char , int);
int		find_type_value(t_process *, char *, t_arg_value *, int);
int		check_valid_instruct(char *, int);
void		put_in_tabl(int (*tabl[23])(t_process *, char *));
int		parsing_instruct(t_process *, char *, t_live *, t_champ *);
int		live_fonction(t_process *, char *, t_live *, t_champ *);

#endif  /* !VM_PAR_FONC_H_ */
