# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 13:46:46 by rumachad          #+#    #+#              #
#    Updated: 2023/09/18 13:15:27 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
HEADER = include/minitalk.h
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I include

${NAME}:	
			make -C ${LIBFT_DIR}
			${CC} ${CFLAGS} src/server.c ${LIBFT} -o server
			${CC} ${CFLAGS} src/client.c ${LIBFT} -o client

all:	${NAME}

clean:	
		make clean -C ${LIBFT_DIR}
		${RM}

fclean: clean
		make fclean -C ${LIBFT_DIR}
		${RM} server client

re:	fclean all

.SILENT: