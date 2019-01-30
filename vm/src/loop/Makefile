##
## Makefile for 101pong in /home/sylvain.lefevre/git/101pong
## 
## Made by Sylvain Lefevre
## Login   <sylvain.lefevre@epitech.net>
## 
## Started on  Tue Nov  8 13:36:03 2016 Sylvain Lefevre
## Last update Thu Mar 30 16:28:50 2017 PierreL
##

CC      = gcc

RM      = rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS  += -I../../../include/
CFLAGS	+= -I../../include/

LDFLAGS = -L../../../lib/my/ -lmy

NAMEL	= ../../../lib/my/libmy.a

SRCSL	= ../../../lib/my/my_fputstr.c		\
	  ../../../lib/my/get_next_line.c	\
	  ../../../lib/my/my_getnbr.c		\
	  ../../../lib/my/my_strcmp.c		\
	  ../../../lib/my/my_strdopy.c		\
	  ../../../lib/my/my_strdup.c		\
	  ../../../lib/my/my_strstr.c		\
	  ../../../lib/my/my_str_to_wordtab.c	\
	  ../../../lib/my/free.c

SRCS	= ../main.c						\
	  ../parsing_arg/put_arg_in_link.c			\
	  ../arena/arena.c					\
	  ../arena/create_champ.c				\
	  ../arena/read_file.c					\
	  ../arena/put_champ.c                  		\
	  ../arena/check_dash_a.c				\
	  ../arena/action.c					\
	  create_process.c					\
	  champ.c						\
	  live.c						\
	  process.c						\
	  vm.c							\
	  ../../../src/op.c					\
	  free_process.c					\
	  defeat.c						\
	  ../parsing_arg/fonction_parsing_arg.c			\
	  ../fonction/instruction_asm/fonction_fork.c		\
	  ../fonction/instruction_asm/fonction_operat.c		\
	  ../fonction/instruction_asm/fonction_asm_spe.c	\
	  ../fonction/instruction_asm/fonction_binary_op.c	\
	  ../fonction/instruction_asm/fonction_load_values.c	\
	  ../fonction/instruction_asm/fonction_store.c		\
	  ../fonction/parsing_instruct.c			\
	  ../fonction/print_value.c				\
	  ../fonction/set_the_carry.c				\
	  ../fonction/find_value_arg.c				\
	  dump.c

OBJS	= $(SRCS:.c=.o)

OBJSL   = $(SRCSL:.c=.o)

NAME	= test

all:	$(NAMEL) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

$(NAMEL): $(OBJSL)
	@ar rc $(NAMEL) $(OBJSL)
	@ranlib $(NAMEL)

clean:
	@$(RM) $(OBJSL) $(OBJS)

fclean:	clean
	@$(RM) $(NAMEL) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
