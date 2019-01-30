/*
** asm.h for include in /home/sylvain.lefevre/git/CPE_2016_corewar/include
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.net>
** 
** Started on  Tue Feb 28 17:08:36 2017 Sylvain Lefevre
** Last update Thu Mar 23 12:41:36 2017 Elodie Billiot
*/

#ifndef ASM_H_
# define ASM_H_

# include "op.h"
# include "header.h"
# include "labels.h"

# define SIZE_OF_ARGS(x)	(x <= 1) ? 1 : ((x / 4) + 2)

# define HELP		"-h"

# define USAGE		"USAGE\n\t"
# define FILE_NAME	" file_name[.s]\nDESCRIPTION\n\t"
# define LANGUAGE	"file_name\tfile in assembly language to be converted "
# define FILE_COR	"into file_name.cor, an\n\t\t\texecutable "
# define V_M		"in the Virtual Machine.\n"

# define SPACE_CHAR	' '
# define TAB_CHAR	'\t'
# define S_COM_CHAR	';'
# define PATH_CHAR	'/'

# define AFF_ID		15
# define BIT_IN_BYTE	8

# define COMMENT_ID	16
# define NAME_ID	17
# define NBR_CMD	18

# define SOURCE_EXT	".s"
# define COR_EXT	".cor"

int		asm(char *);
void		verbose(char **);
int		set_file(char *);
char		*get_file_name(char *);
int		calc_address(int, char *, int);
int		put_hex(int, unsigned int);
int		get_cmd_id(char *cmd[NBR_CMD], char *);
int		set_cmd(char **cmd);
int		remove_useless(char *str);
char		**get_all_file(char *);
int		output_to_file(char **, t_labels *, t_header *);
int		set_comment(char *, t_header *, int);
int		set_name(char *, t_header *, int);
int		remove_space_tab(char *);
int		print_fd(char, char, ...);
int		print_str_fd(char *, int);

#endif	/* ASM_H_ */
