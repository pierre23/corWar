##
## Makefile for 101pong in /home/sylvain.lefevre/git/101pong
## 
## Made by Sylvain Lefevre
## Login   <sylvain.lefevre@epitech.net>
## 
## Started on  Tue Nov  8 13:36:03 2016 Sylvain Lefevre
## Last update Thu Mar 23 19:28:46 2017 PierreL
##

CC      = gcc

RM      = @rm -f

CFLAGS  += -Wextra -Wall -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS  += -I../include/

LDFLAGS = -L./my/ -lmy

NAMEL	= ./my/libmy.a

SRCSL	= my/my_fputstr.c		\
	  my/free.c			\
	  my/my_getnbr.c		\
	  my/my_strcmp.c		\
	  my/get_next_line.c		\
	  my/my_strdup.c		\
	  my/my_strstr.c		\
	  my/my_strdopy.c		\
	  my/my_str_to_wordtab.c

OBJSL   = $(SRCSL:.c=.o)

all:	$(NAMEL)

$(NAMEL): $(OBJSL)
	ar rc $(NAMEL) $(OBJSL)
	ranlib $(NAMEL)

clean:
	$(RM) $(OBJSL)

fclean:	clean
	$(RM) $(NAMEL)

re:	fclean all

.PHONY: all clean fclean re
