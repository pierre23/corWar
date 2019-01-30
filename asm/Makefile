##
## Makefile for 101pong in /home/sylvain.lefevre/git/101pong
## 
## Made by Sylvain Lefevre
## Login   <sylvain.lefevre@epitech.net>
## 
## Started on  Tue Nov  8 13:36:03 2016 Sylvain Lefevre
## Last update Fri Aug 18 16:00:15 2017 
##

CC      = gcc

RM      = rm -f

CFLAGS  += -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS  += -I./include/
CFLAGS	+= -I../include/

LDFLAGS = -L../lib/my/ -lmy

SRC	= main.c				\
	  file/file.c				\
	  file/file_source.c			\
	  file/t_file.c				\
	  labels/get_labels.c			\
	  get_opt.c				\
	  ../../src/op.c			\
	  labels/label_list.c			\
	  t_header.c				\
	  address.c				\
	  parsing_type/put_label_in_link.c	\
	  parsing_type/put_type_in_link.c	\
	  parsing_type/arg_nbr.c		\
	  parsing_type/print_arg.c		\
	  print.c 				\
	  asm.c					\
	  fonctions/remove_space.c		\
	  fonctions/check_virgule.c		\
	  fonctions/check_register.c 		\
	  fonctions/check_direct.c		\
	  fonctions/check_indirect.c		\
	  fonctions/verif_args.c		\
	  fonctions/calc_bytes.c		\
	  file/file_name.c			\
	  cmd.c					\
	  verbose.c	

SRC_DIR	= ./src/

SRCS	= $(addprefix $(SRC_DIR), $(SRC))

OBJS	= $(SRCS:.c=.o)

NAME	= asm

all:
	make -C ../lib/
	make $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	make clean -C ../lib/
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C ../lib/
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
