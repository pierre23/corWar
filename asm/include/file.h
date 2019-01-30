/*
** asm_file.h for include in /home/sylvain.lefevre/git/CPE_2016_corewar/include
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Thu Mar 23 14:46:35 2017 Sylvain Lefevre
** Last update Thu Mar 23 14:46:35 2017 Sylvain Lefevre
*/

#ifndef ASM_FILE_H_
# define ASM_FILE_H_

typedef struct		s_file
{
  char			*line;
  struct s_file		*next;
}			t_file;

typedef struct		s_file_info
{
  t_file		*first;
  t_file		*last;
}			t_file_info;

void		*free_file_list(t_file *);
void		print_file(t_file *);
unsigned int	t_file_len(t_file *);
t_file		*append_in_file(t_file_info *, char *);

#endif	/* ASM_FILE_H_ */
