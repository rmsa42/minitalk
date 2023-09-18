# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 13:46:46 by rumachad          #+#    #+#              #
#    Updated: 2023/09/18 14:48:40 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
BONUS = bonus
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

${NAME}:	
			make -C ${LIBFT_DIR}
			${CC} ${CFLAGS} src/server.c ${LIBFT} -o server
			${CC} ${CFLAGS} src/client.c ${LIBFT} -o client

${BONUS}:
			make -C ${LIBFT_DIR}
			${CC} ${CFLAGS} src_bonus/server_bonus.c ${LIBFT} -o server
			${CC} ${CFLAGS} src_bonus/client_bonus.c ${LIBFT} -o client

all:	${NAME}

clean:	
		make clean -C ${LIBFT_DIR}
		${RM}

fclean: clean
		make fclean -C ${LIBFT_DIR}
		${RM} server client

re:	fclean all
