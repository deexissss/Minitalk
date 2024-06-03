# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 13:11:20 by tjehaes           #+#    #+#              #
#    Updated: 2024/05/07 09:25:55 by tjehaes          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER_SRC = server.c
CLIENT_SRC = client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
OBJ = $(CLIENT_OBJ) $(SERVER_OBJ)

LIBFT_LIB = libft/libft.a
PRINTF_LIB = printf/libftprintf.a

CC = gcc
FLAGS = -Wall -Wextra -Werror

BLUE := \033[0;34m
PINK := \033[1;35m
BLUE2 := \033[0;36m
NOCOLOR := \033[0m

all: $(NAME)

$(NAME): lib_compilation ft_server ft_client

lib_compilation:
	@echo "$(BLUE)STARTING COMPILATION$(NOCOLOR)"
	@cd libft && make
	@cd printf && make

ft_server: $(SERVER_OBJ)
	@$(CC) $(FLAGS) $(SERVER_OBJ) $(PRINTF_LIB) $(LIBFT_LIB) -o server

ft_client: $(CLIENT_OBJ)
	@$(CC) $(FLAGS) $(CLIENT_OBJ) $(PRINTF_LIB) $(LIBFT_LIB) -o client
	@echo "$(BLUE)COMPILATION READY$(NOCOLOR)"

clean:
	@echo "$(BLUE2)STARTING CLEANING$(NOCOLOR)"
	@rm -f $(OBJ)
	@cd libft && make clean
	@cd printf && make clean
	@echo "$(BLUE2)ALL OBJ FILES DELETED"

fclean: clean
	@echo "$(PINK)STARTING FCLEANING$(NOCOLOR)"
	@rm -f server client
	@cd libft && make fclean
	@cd printf && make fclean
	@echo "$(PINK)EVERYTHING CLEAN UP"
%.o: %.c
	$(CC) -c $(FLAGS) $< -o $@

re:	fclean all

.PHONY: all minitalk server client clean fclean re libft printf
