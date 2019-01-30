/*
** errors.h for include in /home/sylvain.lefevre/git/CPE_2016_corewar/vm/include
** 
** Made by Sylvain Lefevre
** Login   <sylvain.lefevre@epitech.eu>
** 
** Started on  Fri Mar 24 20:22:32 2017 Sylvain Lefevre
** Last update Thu Mar 30 15:40:35 2017 ugo lafaille
*/

#ifndef ERRORS_H_
# define ERRORS_H_

# define SAME_POS	"Two champions are at the same address"
# define TOO_BIG	"The memory size isn't large enough"
# define FEW_PRG_NBR	"There are more than one prog number flag"
# define ONE_CHAMP	"Please put more than one champion"
# define MISS_FILE	"Missing file name"
# define TWO_LOAD_NBR	"There are more than one load address flag"
# define BAD_DUMP_NBR	"Bad dump number"
# define BAD_LOAD_NBR	"Invalid load number"
# define BAD_ADDR	"Invalid load address: "
# define BAD_FLAG	"This option is invalid: "
# define TOO_CHAMP	"There are too many champions"
# define ERR_FORMAT	"\033[31mError:\033[m %s%s.\n"
# define ERR_INV_FILE	"Invalid file: "
# define CHAMP_SAME_PL	"Some champion have the same place"
# define INV_PLACE	"A champion place is invalid"
# define ERR_INV_COR	"Invalid magic number in: "
# define ERR_INV_HEAD	"Invalid header in: "
# define ERR_INV_SIZE	"Invalid size in: "
# define ERR_BIG_SIZE	"Size too big in: "
# define ERR_INV_ARGS	"Expected arguments"

#endif	/* !ERRORS_H_ */
