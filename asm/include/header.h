/*
** asm_header.h for include in /home/sylvain.lefevre/git/CPE_2016_corewar/include
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Wed Mar 22 21:41:33 2017 Sylvain Lefevre
** Last update Wed Mar 22 21:41:33 2017 Sylvain Lefevre
*/

#ifndef ASM_HEADER_H_
# define ASM_HEADER_H_

# include "op.h"

# define STRING_SEP		'"'
# define MIN_SIZE_NAME		0
# define MIN_SIZE_COMMENT	0

typedef struct		s_header
{
  char			name[PROG_NAME_LENGTH + 1];
  char			comment[COMMENT_LENGTH + 1];
  unsigned int		address;
  unsigned char		action;
}			t_header;

int	print_header(t_header *);

#endif	/* ASM_HEADER_H_ */
