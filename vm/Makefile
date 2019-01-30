##
## Makefile for 101pong in /home/sylvain.lefevre/git/101pong
## 
## Made by Sylvain Lefevre
## Login   <sylvain.lefevre@epitech.net>
## 
## Started on  Tue Nov  8 13:36:03 2016 Sylvain Lefevre
## Last update Fri Mar 31 12:59:08 2017 Elodie Billiot
##

CC      = gcc

RM      = rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS  += -I../include/
CFLAGS	+= -I./include/

LDFLAGS = -L../lib/my/ -lmy

SRC	= main.c						\
	  parsing_arg/put_arg_in_link.c				\
	  parsing_arg/placement_nbr.c				\
	  arena/arena.c						\
	  arena/create_champ.c					\
	  arena/read_file.c					\
	  arena/put_champ.c                  			\
	  arena/check_dash_a.c					\
	  arena/action.c					\
	  loop/create_process.c					\
	  loop/champ.c						\
	  loop/live.c						\
	  loop/process.c					\
	  loop/vm.c						\
	  ../../src/op.c					\
	  loop/free_process.c					\
	  loop/defeat.c						\
	  parsing_arg/fonction_parsing_arg.c			\
	  fonction/instruction_asm/fonction_fork.c		\
	  fonction/instruction_asm/fonction_operat.c		\
	  fonction/instruction_asm/fonction_asm_spe.c		\
	  fonction/instruction_asm/fonction_binary_op.c		\
	  fonction/instruction_asm/fonction_load_values.c	\
	  fonction/instruction_asm/fonction_store.c		\
	  fonction/parsing_instruct.c				\
	  fonction/print_value.c				\
	  fonction/set_the_carry.c				\
	  fonction/find_value_arg.c				\
	  loop/dump.c

SRC_DIR	= ./src/

SRCS	= $(addprefix $(SRC_DIR), $(SRC))

OBJS	= $(SRCS:.c=.o)

NAME	= vm

all:
	make -C ../lib/
	make $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	make clean -C ../lib/
	@$(RM) $(OBJS)

fclean:	clean
	make fclean -C ../lib/
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
