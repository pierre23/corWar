/*
** vm.h for  in /home/elodie.billiot/Corewar/CPE_2016_corewar/vm
** 
** Made by Elodie Billiot
** Login   <elodie.billiot@epitech.net>
** 
** Started on  Mon Mar 27 12:49:37 2017 Elodie Billiot
** Last update Fri Mar 31 12:32:04 2017 Elodie Billiot
*/

#ifndef VM_H_
# define VM_H_

# include "op.h"

# define WIN_STRING	"The player %d(%s) has won.\n"
# define LIVE_STRING	"The player %d(%s) is alive.\n"

# define HELP		"-h"
# define USAGE		"USAGE\n\t%s [-dump nbr_cycle] [[-n prog_number] "
# define ARG_HELP	"[-a load_address] prog_name] ...\n\nDESCRIPTION\n\t"
# define DESC		"-dump nbr_cycle dumps the memory after the nbr_cycle"
# define EXEC		"execution (if the round isn't\n\t\t\talready over) "
# define FORM_DUMP	"with the following format: 32 bytes/line in\n\t\t\t"
# define HEXA		"hexadecimal (A0BCDEFE1DD3...)\n\t"
# define PROG_NB	"-n prog_number sets the next program's number. "
# define DEFAULT_NB	"By default, the first free number\n\t\t\t"
# define PARAMS		"in the parameter order\n\t"
# define A_LOAD		"-a load_address sets the next program's loading "
# define ADDRESS	"address. When no address is\n\t\t\t"
# define OPTI		"specified, optimize the addresses so that the "
# define PROCESS	"processes are as far\n\t\t\t"
# define POSSIBLE	"away from each other as possible. "
# define MEM_ADDR	"The addresses are MEM_SIZE modulo.\n"

# define POS_ARENA(x)	(x < 0) ? ((MEM_SIZE - (-x % MEM_SIZE)) % MEM_SIZE)\
  : ((x) % MEM_SIZE)

int	vm(char **);
char	*create_arena();
int	dump_mem(char *);
int	print_value_in_arena(char *, int, int, unsigned int);

#endif	/* VM_H_ */
