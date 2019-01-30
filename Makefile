##
## Makefile for CPE_2016_corewar in /home/sylvain.lefevre/git/CPE_2016_corewar
## 
## Made by Sylvain Lefevre
## Login   <sylvain.lefevre@epitech.eu>
## 
## Started on  Wed Mar 29 12:12:30 2017 Sylvain Lefevre
## Last update Thu Mar 30 16:30:24 2017 PierreL
##

all:
	make -C lib/
	make -C asm/
	make -C vm/
	@rand=$(shell \
		python -c 'from random import randint; print(randint(0, 0))') && \
	clear && cat ./makeimg/MAKE_$$rand

clean:
	make clean -C lib/
	make clean -C asm/
	make clean -C vm/

fclean:	
	make fclean -C lib/
	make fclean -C asm/
	make fclean -C vm/

re:	fclean all

.PHONY: all clean fclean re
