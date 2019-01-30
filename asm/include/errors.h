/*
** errors_asm.h for include in /home/sylvain.lefevre/git/CPE_2016_corewar/include
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Wed Mar 22 14:39:36 2017 Sylvain Lefevre
** Last update Wed Mar 22 15:51:31 2017 ugo lafaille
*/

#ifndef ERRORS_ASM_H_
# define ERRORS_ASM_H_

# define ERR_FORMAT	"\033[31mError:\033[m line %d: %s%s.\n"
# define ERR_FORMAT_WL	"\033[31mError:\033[m: %s%s.\n"
# define ERR_MUL_DLAB	"Multiple definition of: "
# define ERR_INV_INST	"Invalid instruction: "
# define ERR_INV_FILE	"Invalid file: "
# define ERR_EXP_ARG	"Expected arguments"
# define ERR_LABEL	"Unknown label"
# define ERR_ARG	"Unknown Argument: "
# define ERR_NBARG	"Invalid number of argument(s)"
# define ERR_NO_HEAD	"No .name and .comment"
# define ERR_NO_NAME	"No .name"
# define ERR_NO_COMM	"No .comment"
# define ERR_RE_NAME	"Double definition of .name"
# define ERR_RE_COMM	"Double definition of .comment"
# define ERR_NAME	"Invalid .name"
# define ERR_COMM	"Invalid .comment"
# define ERR_REG	"Invalid register: "
# define ERR_DIR	"Invalid direct: "
# define ERR_IND	"Invalid indirect: "

#endif	/* ERRORS_ASM_H_ */
