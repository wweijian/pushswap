# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 14:07:38 by wjhoe             #+#    #+#              #
#    Updated: 2025/05/26 19:20:21 by wjhoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS_PATH = ./srcs
SRCS = main.c solve.c validate_argument.c find_solution.c
SRCS := $(addprefix $(SRCS_PATH)/, $(SRCS))
HDRS = includes

LIBFT_PATH = ./libft
LIBFT = ${LIBFT_PATH}/libft.a

CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr

all: ${NAME}

${NAME}: ${LIBFT} ${SRCS} ${OBJS} ${HDRS}
		${CC} ${CFLAGS} ${SRCS} -I ${HDRS} -L. ${LIBFT} -o ${NAME}

bonus: 

${LIBFT}:
		make -C ${LIBFT_PATH} all

clean:
		${RM} ${OBJS}
		make -C ${LIBFT_PATH} clean

fclean: clean
		${RM} ${NAME}
		make -C ${LIBFT_PATH} fclean

test: ${NAME}
		clear
		./${NAME} 0 -2147483648 2147483647 

re: fclean all

.PHONY: all clean fclean re bonus