/*
** my.h for navy in /home/sylvain.lefevre/git/navy/test
** 
** Made by Sylvain Lefevre
** Login   <sylvain-lefevre@epitech.net>
** 
** Started on  Sat Jan 28 13:49:46 2017 Sylvain Lefevre
** Last update Fri Mar 31 17:38:20 2017 PierreL
*/

#ifndef MY_H_
# define MY_H_

# define IS_NUM(c)	(c >= '0' && c <= '9') ? 1 : 0

# define EXIT_SUCCESS	0
# define EXIT_FAILURE	1
# define EXIT_MALLOC	0
# define EXIT_TEK	84

int	my_pow(int, int);
char	**my_str_to_wordtab(char *, char);
char	*convert_base(char *, char *, char *);
char	*my_strcapitaliz(char *);
char	*free_str(char *);
char	**free_char_array(char **);
int	str_isnum(char *);
int	convert_to_base_10(char *, char *);
int	my_strlen(const char *);
int	my_strcmp(char *, char *);
int	my_getnbr(char *);
int	my_strcapitalize(char *);
int	my_fputstr(int, char *, ...);
char	*my_strdup(char *);
int	my_strcat(char *, char *);
int	my_str_cmp(char *, char *);
char	*my_strstr(char *, char *);
int	my_arr_len(char **);
char	**my_arrdup(char **);
char	**free_arr(char **);
char	*my_strcopy(char *, char *);
int	is_in_string(char *, char);
char	*my_strstr_args(char *, char *);

#endif	/* MY_H_ */
