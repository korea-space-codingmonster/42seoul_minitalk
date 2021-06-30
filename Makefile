# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 13:47:41 by napark            #+#    #+#              #
#    Updated: 2021/06/30 14:31:51 by napark           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server

CLIENT   = client

SERVER_BONUS = server_bonus

CLIENT_BONUS = client_bonus

CC	     = gcc $(FLAGS)

FLAGS    = -Wall -Werror -Wextra

SERVER_SRC = minitalk/server.c minitalk/utils.c minitalk/utils2.c minitalk/stringhe.c 

CLIENT_SRC = minitalk/client.c minitalk/stringhe.c minitalk/utils.c minitalk/utils2.c

SERVER_BONUS_SRC = minitalk_bonus/bonus_server.c minitalk_bonus/stringhe_bonus.c minitalk_bonus/utils_bonus.c minitalk_bonus/utils2_bonus.c minitalk_bonus/utils3_bonus.c

CLIENT_BONUS_SRC = minitalk_bonus/bonus_client.c minitalk_bonus/stringhe_bonus.c minitalk_bonus/utils_bonus.c minitalk_bonus/utils2_bonus.c minitalk_bonus/utils3_bonus.c

SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)

CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

SERVER_SRC_OBJ	= $(SERVER_SRC:.c=.o)

CLIENT_SRC_OBJ	= $(CLIENT_SRC:.c=.o)

all :	fclean $(SERVER_SRC_OBJ) $(CLIENT_SRC_OBJ)
		@$(CC) $(SERVER_SRC) -I minitalk.h -o server
		@$(CC) $(CLIENT_SRC) -I minitalk.h -o client

bonus:	fclean $(SERVER_BONUS_OBJ) $(CLIENT_BONUS_OBJ)
		@$(CC) $(SERVER_BONUS_SRC) -I minitalk_bonus.h -o server_bonus
		@$(CC) $(CLIENT_BONUS_SRC) -I minitalk_bonus.h -o client_bonus

clean :
	@rm -rf ./minitalk_bonus/*.o ./minitalk/*.o

fclean: clean
	@rm -rf $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY : bonus all clean fclean
