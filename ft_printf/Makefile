SRCS	= ft_printf.c ft_printf_utils.c ft_convert_base.c ft_write_adress.c ft_convert_base.c

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintfc.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cp libft/libft.a .
	mv libft.a $(NAME)
	ar rc $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)
	make clean -C libft 

fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a

re: fclean all

.PHONY: clean fclean re