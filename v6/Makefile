# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 14:07:38 by wjhoe             #+#    #+#              #
#    Updated: 2025/06/02 09:30:20 by wjhoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HDRS = includes

SRCS_PATH = ./srcs
SRCS = main.c \
		validate_argument.c find_solution.c solve_stack.c init_stack.c\
		presort_stack.c make_base.c sort_and_push.c sort_back.c push_swap_ops.c\
		presort_stack_utils.c sort_back_utils.c  push_swap_utils.c swap_utils.c utils.c
SRCS := $(addprefix $(SRCS_PATH)/, $(SRCS))

LIBFT_PATH = ./libft
LIBFT = ${LIBFT_PATH}/libft.a

CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr

ARGS100 = 100.txt
ARGS101 = 101.txt
ARGS6 = 6.txt
ARGS5 = 5.txt

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

# REMOVE ALL TEST BEFORE SUBMISSION


101: ${NAME}
		clear
		xargs ./${NAME} < ${ARGS101}

101a: ${NAME}
		clear
		xargs ./${NAME} < ${ARGS101} > output.txt

100: ${NAME}
		clear
		xargs ./${NAME} < ${ARGS100}

100a: ${NAME}
		clear
		xargs ./${NAME} < ${ARGS100} > output.txt
		
100h: ${NAME}
		clear
		xargs ./${NAME} < ${ARGS100} | head -n 3000 > output.txt
		
5: ${NAME}
		clear
		xargs ./${NAME} < ${ARGS5}

6: ${NAME}
		clear
		xargs ./${NAME} < ${ARGS6}


100l: ${NAME}
		clear
		xargs ./${NAME} < ${ARGS100} | wc -l

100l2: ${NAME}
		clear
		xargs ./${NAME} < 100-1.txt | wc -l

500l: ${NAME}
		clear
		xargs ./${NAME} < 500.txt | wc -l

500a: ${NAME}
		clear
		xargs ./${NAME} < 500.txt > output.txt
		
re: fclean all

.PHONY: all clean fclean re bonus 5 6 100 101