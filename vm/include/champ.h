/*
** champ.h for include in /home/sylvain.lefevre/git/CPE_2016_corewar/include
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Thu Mar 09 21:25:30 2017 Sylvain Lefevre
** Last update Mon Mar 27 17:47:57 2017 ugo lafaille
*/

#ifndef CHAMP_H_
# define CHAMP_H_

# include "my_vm_ar.h"
# include "loop.h"
# include "process.h"

# define MAX_SIZE_CHAMP		((MEM_SIZE - 100) / 4)

# define SIZE_OF_HEADER		2188
# define POS_NAME		0
# define POS_SIZE		132
# define POS_COMMENT		136
# define ERR			-1

unsigned int	read_uns_int_buffer(char *);
unsigned int	read_uns_int_fd(int);
int		check_valid_cor(int);
int		create_champ_from_list(t_champ *);
char		*get_champ_name(t_champ *, int);
int		calc_space_between_champ(t_champ *);
int		count_champ(t_champ *);
t_process	*set_defeat_champ(t_champ *, t_live *, t_process *);
int		print_winner(t_champ *);
unsigned int	get_position_champ(t_champ *);
int		put_champ_address(t_champ *, char *);
int		place_champs(t_champ *, char *);
int		put_in_arena(char *, char *, int);
int		find_pos(char *, int, int);
int		place_each_dash_a(t_champ *, char *);
int		put_in_arena_dash_a(char *, char *, int, t_champ *);

#endif	/* CHAMP_H_ */
