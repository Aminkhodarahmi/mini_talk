# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/18 19:10:55 by akhodara          #+#    #+#              #
#    Updated: 2023/03/18 19:10:55 by akhodara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror

CLIENT_SOURCE = client.c client_utils.c
CLIENT_OBJECT = $(CLIENT_SOURCE:%.c=%.o)
SERVER_SOURCE = server.c server_utils.c
SERVER_OBJECT = $(SERVER_SOURCE:%.c=%.o)

all : $(NAME)

$(NAME) : server client

	@echo ""
	@echo ""
	@echo "compiling done."
	@echo ""
	@echo ""
	@echo "Have Written by Amin Khodarahmi"
	@echo ""
	@echo ""
	@curl https://icanhazdadjoke.com
	@echo ""
	@echo ""

server : $(SERVER_OBJECT) $(LIBFT)
	cc -o server $(FLAGS) $(SERVER_OBJECT) $(LIBFT)

client : $(CLIENT_OBJECT) $(LIBFT)
	cc -o client $(FLAGS) $(CLIENT_OBJECT) $(LIBFT)

$(LIBFT) :
	make -C libft

%.o : %.c
	cc -c $(FLAGS) $^

clean :
	make -C libft clean
	rm -f $(SERVER_OBJECT) $(CLIENT_OBJECT)

fclean : clean
	make -C libft fclean
	rm -f server client

re : fclean all
