CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libftprintf.a
SRCS=ft_printf.c \
	ft_additional_functions.c \
	ft_functions.c \
	ft_init_struct.c \
	ft_fill_struct.c \
	ft_apply_flag.c
OBJS=$(SRCS:.c=.o)
INC=ft_printf.h
RM=rm -f
	
%.c%.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all:		$(NAME)

$(OBJS):	$(INC)

$(NAME): 	$(INC) $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BNS)

fclean: 	clean
	$(RM) $(NAME)

re:		fclean all
	
.PHONY: all bonus clean fclean re
