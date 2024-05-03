# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 13:11:20 by tjehaes           #+#    #+#              #
#    Updated: 2024/05/03 13:50:31 by tjehaes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
OBJ = $(CLIENT_OBJ) $(SERVER_OBJ)

LIBFT = cd libft && make
LIBFT_LIB = libft/libft.a
PRINTF = cd printf && make
PRINTF_LIB = printf/libftprintf.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): lib_compilation ft_server ft_client

lib_compilation:
	@$(LIBFT)
	@$(PRINTF)

ft_server: $(SERVER_OBJ)
	@$(CC) $(FLAGS) $(SERVER_OBJ) $(PRINTF_LIB) $(LIBFT_LIB) -o server

ft_client: $(CLIENT_OBJ)
	@$(CC) $(FLAGS) $(CLIENT_OBJ) $(PRINTF_LIB) $(LIBFT_LIB) -o client

clean:
	@rm -f $(OBJ)
	@cd libft && make clean
	@cd printf && make clean

fclean: clean
	@rm -f server client
	@cd libft && make fclean
	@cd printf && make fclean

%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

re:	fclean all

.PHONY: all minitalk server client clean fclean re libft printf
