/*
** get_next_line.h for get_next_line in /home/sylvain.lefevre/git/CPE_2017_getnextline
** 
** Made by Sylvain Lefevre
** Login   <sylvain-lefevre@epitech.net>
** 
** Started on  Mon Jan  2 11:20:41 2017 Sylvain Lefevre
** Last update Thu Feb  2 11:29:28 2017 Sylvain Lefevre
*/

#ifndef GNL_H_

# ifndef READ_SIZE
#  define READ_SIZE	8192

# endif	/* !READ_SIZE */

# ifndef MAX_FD
#  define MAX_FD	1024

# endif /* !MAX_FD */

char	*get_next_line(const int);

#endif	/* !GNL_H_ */
