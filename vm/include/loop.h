/*
** loop.h for include in /home/sylvain.lefevre/git/CPE_2016_corewar/include
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Sat Mar 11 13:18:57 2017 Sylvain Lefevre
** Last update Sat Mar 11 13:18:57 2017 Sylvain Lefevre
*/

#ifndef LOOP_H_
# define LOOP_H_

# include "my_vm_ar.h"

typedef struct		s_live
{
  int			cid;
  struct s_live		*next;
}			t_live;

# include "process.h"

int	vm_loop(char *, t_process *, t_champ *, int);
int	add_in_live_list(t_live *, int, t_champ *);
t_live	*create_live();
int	check_in_live_list(t_live *, int);
int	is_champ_in_live(t_live *, int);
void	*free_live(t_live *);
int	free_arena(char *, t_champ *, t_process *);

#endif	/* LOOP_H_ */
