##
## Makefile for MAKEFILE in /home/marcha_j//test/c/malloc/proj
## 
## Made by hugo marchadier
## Login   <marcha_j@epitech.net>
## 
## Started on  Wed Feb  1 18:08:19 2012 hugo marchadier
## Last update Fri Jun 22 17:53:20 2012 hugo marchadier
##

NAME=	ftrace

SRC=	main.c \
	tab_sym.c \
	dyntab_sym.c \
	ftrace.c \
	check_if_call.c \
	check_if_ret.c \
	decode_mode_rm.c \
	calc_disp.c \
	decode_sib.c \
	print.c \
	list.c \
	xfct.c \
	fct_annexe.c \
	ncurse.c \
	ncurse_legend.c \

CC=	gcc

CFLAGS+= -W -Wall -Wextra -D_XOPEN_SOURCE=700 -L. -lelf -lncurses

OBJ=    $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re