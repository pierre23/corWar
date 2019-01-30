##
## Makefile for 101pong in /home/sylvain.lefevre/git/101pong
## 
## Made by Sylvain Lefevre
## Login   <sylvain.lefevre@epitech.net>
## 
## Started on  Tue Nov  8 13:36:03 2016 Sylvain Lefevre
## Last update Wed Mar 29 16:12:55 2017 ugo lafaille
##

CC      = gcc

RM      = rm -f

CFLAGS	+= -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS  += -I../..//include/

LDFLAGS = -L../../../lib/my/ -lmy

NAMEL	= ../../../lib/my/libmy.a

SRCSL	= ../../../lib/my/my_fputstr.c		\
	  ../../../lib/my/get_next_line.c	\
	  ../../../lib/my/my_getnbr.c		\
	  ../../../lib/my/my_strcmp.c		\
	  ../../../lib/my/my_strdopy.c		\
	  ../../../lib/my/my_strdup.c		\
	  ../../../lib/my/my_strstr.c		\
	  ../../../lib/my/my_str_to_wordtab.c

SRCS	= main.c				\
	  ../parsing_arg/fonction_parsing_arg.c	\
	  ../parsing_arg/put_arg_in_link.c	\
	  arena.c				\
	  create_champ.c			\
	  read_file.c				\
	  put_champ.c				\
	  check_dash_a.c			\
	  action.c

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
