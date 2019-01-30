##
## Makefile for 101pong in /home/sylvain.lefevre/git/101pong
## 
## Made by Sylvain Lefevre
## Login   <sylvain.lefevre@epitech.net>
## 
## Started on  Tue Nov  8 13:36:03 2016 Sylvain Lefevre
## Last update Thu Mar 30 16:29:44 2017 PierreL
##

CC      = gcc

RM      = rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS  += -I../../include/
CFLAGS	+= -I../include/

LDFLAGS = -L../../lib/my/ -lmy

NAMEL	= ../../lib/my/libmy.a

SRCSL	= ../../lib/my/my_fputstr.c		\
	  ../../lib/my/get_next_line.c		\
	  ../../lib/my/free.c			\
	  ../../lib/my/my_strcmp.c		\
	  ../../lib/my/my_strdup.c		\
	  ../../lib/my/my_strstr.c		\
	  ../../lib/my/my_str_to_wordtab.c	\
	  ../../lib/my/my_getnbr.c

SRCS	= main.c				\
	  file/file.c				\
	  file/file_source.c			\
	  verbose.c				\
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
	  print.c				\
	  asm.c					\
	  fonctions/remove_space.c		\
	  fonctions/check_virgule.c		\
	  fonctions/check_register.c		\
	  fonctions/check_direct.c		\
	  fonctions/check_indirect.c		\
	  fonctions/verif_args.c		\
	  fonctions/calc_bytes.c		\
	  file/file_name.c			\
	  cmd.c

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
