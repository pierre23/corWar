/*
** process.h for include in /home/sylvain.lefevre/git/CPE_2016_corewar/include
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Thu Mar 09 11:43:35 2017 Sylvain Lefevre
** Last update Thu Mar 23 20:50:56 2017 PierreL
*/

#ifndef PROCESS_H_
# define PROCESS_H_

# include "op.h"
# include "my_vm_ar.h"

# define FIRST_PID	1
# define POS_REG_CID	0

typedef struct		s_process
{
  int			registers[REG_NUMBER];
  int			pc;
  char			carry;
  int			cycles;
  unsigned int		pid;
  unsigned int		cid;
  struct s_process	*next;
}			t_process;

# include "loop.h"

t_process	*create_process_list(t_champ *);
t_process	*create_process(t_process *, int, int);
int		append_process(t_process *, int, int);
int		do_process(t_process *, char *, t_champ *, t_live *);
void		*free_next_process(t_process *);
void		print_process(t_process *);
void		*free_process_list(t_process *);
t_process	*kill_process(t_process *, unsigned int);

#endif	/* PROCESS_H_ */
