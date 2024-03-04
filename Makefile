# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehedeman <ehedeman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 13:51:06 by ehedeman          #+#    #+#              #
#    Updated: 2024/01/25 12:38:23 by ehedeman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = server
SRC_S = server.c

CLIENT = client
SRC_C= client.c

OBJS = $(SRC_S:.c=.o) $(SRC_C:.c=.o)
OBJS_DIR = objs/
OBJS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
#KILL = kill
#SRC_K = kill.c

CC = cc
CFLAGS = -Werror -Wall -Wextra

LIBFT = libft.a
LIB_PATH = ./libft/

all: $(LIBFT) $(CLIENT) $(NAME) #$(KILL)
	@printf "\e[38;5;118mLibft.a Done :D\n"
	@printf "\e[38;5;118mServer Done :D\n"
	@printf "\e[38;5;118mClient Done :D\n"

$(NAME): $(OBJS_PREFIXED)
	@$(CC) $(CFLAGS) $(SRC_S) -Ilibft -L$(LIB_PATH) -lft -o $(NAME)

$(OBJS_DIR)%.o : %.c minitalk.h
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@(cd libft && make all)

$(CLIENT): 
	@$(CC) $(CFLAGS) $(SRC_C) -Ilibft -L$(LIB_PATH) -lft -o $(CLIENT) 

#$(KILL): 
#	@$(CC) $(CFLAGS) $(SRC_K) -Ilibft -L$(LIB_PATH) -lft -o $(KILL)

clean:
	@rm -rf $(OBJS_DIR)
	@(cd libft && make clean)
	@printf "\e[033;31mRemoved object Files\n"

fclean: clean
	@(cd libft && make fclean)
	@printf "\e[033;31mRemoved libft.a\n"
	@rm -f $(CLIENT)
	@rm -f $(NAME)
#	@rm -f $(KILL)
	@printf "\e[033;31mRemoved client\n"
	@printf "\e[033;31mRemoved cerver\n"

re: fclean all

.PHONY: all clean re start_server fclean