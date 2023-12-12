NAME	= libftprintfc.a

SRVO	= server

SRVOB	= server_bonus

CLTO	= client

CLTOB	= client_bonus

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(SRVO) $(CLTO)

$(NAME):
	make -C ./ft_printf
	cp ./ft_printf/libftprintfc.a .
$(SRVO): $(NAME)
	$(CC) $(CFLAGS) server.c $(NAME) -o server

$(CLTO): $(NAME)
	$(CC) $(CFLAGS) client.c $(NAME) -o client

bonus: $(SRVOB) $(CLTOB)

$(SRVOB): $(NAME)
	$(CC) $(CFLAGS) server_bonus.c $(NAME) -o server_bonus

$(CLTOB): $(NAME)
	$(CC) $(CFLAGS) client_bonus.c $(NAME) -o client_bonus

clean:
	make clean -C ft_printf
	rm -rf server client client_bonus server_bonus libftprintfc.a

fclean: clean
	make fclean -C ft_printf
	
re: fclean all