# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 13:46:46 by rumachad          #+#    #+#              #
#    Updated: 2023/09/13 16:04:42 by rumachad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
LIBFT_DIR = libft
LIBFT_PATH = ${LIBFT_DIR}/libft.a
HEADER = include/minitalk.h
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I include

${NAME}:	
			${CC} ${CFLAGS} -c server.c
			${CC} ${CFLAGS} -c client.c
			make -C ${LIBFT_DIR}
			${CC} ${CFLAGS} server.o ${LIBFT_PATH} -o server
			${CC} ${CFLAGS} client.o ${LIBFT_PATH} -o client
			

all:	${NAME}

clean:	
		make clean -C ${LIBFT_DIR}
		${RM} server.o client.o

fclean: clean
		make fclean -C ${LIBFT_DIR}
		${RM} server client

re:	fclean all

.SILENT: