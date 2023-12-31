# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 13:46:46 by rumachad          #+#    #+#              #
#    Updated: 2023/09/22 10:50:19 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
BONUS = bonus
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

${NAME}:	server client

${BONUS}:	server_bonus client_bonus

server:
		make -C ${LIBFT_DIR}
		${CC} ${CFLAGS} src/server.c ${LIBFT} -o server

client:
		make -C ${LIBFT_DIR}
		${CC} ${CFLAGS} src/client.c ${LIBFT} -o client

server_bonus:
				make -C ${LIBFT_DIR}
				${CC} ${CFLAGS} src_bonus/server_bonus.c ${LIBFT} -o server_bonus
			
client_bonus:
				make -C ${LIBFT_DIR}
				${CC} ${CFLAGS} src_bonus/client_bonus.c ${LIBFT} -o client_bonus

all:	${NAME}

clean:	
		make clean -C ${LIBFT_DIR}
		${RM}

fclean: clean
		make fclean -C ${LIBFT_DIR}
		${RM} server client server_bonus client_bonus

re:	fclean all
