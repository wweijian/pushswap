# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 14:07:38 by wjhoe             #+#    #+#              #
#    Updated: 2025/06/06 09:33:21 by wjhoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#MANDATORY
NAME = push_swap

HDRS = includes/

OPS_PATH = ./operations
OPS	= rotate.c push.c rev_rotate.c swap.c check_counter_spin.c put_operation.c \
		check_double_spin.c check_double_counter_spin.c check_double_swap.c
OPS := ${addprefix ${OPS_PATH}/, ${OPS}}

SRCS_PATH = ./srcs
SRCS = main.c \
		validate_argument.c find_solution.c solve_stack.c init_stack.c\
		presort_stack.c make_base.c finish_sort_b.c \
		presort_stack_utils.c utils.c sort_stack_a.c sort_stack_b.c \
		sort_stacks_utils.c finish_sort_a.c finish_sort_utils.c
SRCS := ${addprefix ${SRCS_PATH}/, ${SRCS}}
SRCS += ${OPS}

LIB_PATH = ./libraries
LIB = ${LIB_PATH}/libftprintf.a

# BONUS
B_NAME = checker

B_MAIN_PATH = ./bonus/srcs
B_SRCS_PATH = ./srcs

B_MAIN = gnl_bonus.c gnl_utils_bonus.c main_bonus.c sort_bonus.c utils_bonus.c
B_MAIN := ${addprefix ${B_MAIN_PATH}/, ${B_MAIN}}

B_SRCS = validate_argument.c find_solution.c solve_stack.c init_stack.c\
			presort_stack.c make_base.c finish_sort_b.c \
			presort_stack_utils.c utils.c sort_stack_a.c sort_stack_b.c \
			sort_stacks_utils.c finish_sort_a.c finish_sort_utils.c
B_SRCS := ${addprefix ${B_SRCS_PATH}/, ${B_SRCS}}
B_SRCS += ${OPS} ${B_MAIN}

B_HDRS = ./bonus/includes

# COMPILE RULES
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr

all: ${NAME}

${NAME}: ${LIB} ${SRCS} ${HDRS}
		${CC} ${CFLAGS} ${SRCS} -I ${HDRS} -L. ${LIB} -o ${NAME}

bonus: ${LIB} ${B_SRCS} ${B_HDRS} ${HDRS}
		${CC} ${CFLAGS} ${B_SRCS} -I ${B_HDRS} -I ${HDRS} -L. ${LIB} -o ${B_NAME}

${LIB}:
		make -C ${LIB_PATH} all

clean:
		make -C ${LIB_PATH} clean

fclean: clean
		${RM} ${NAME} ${B_NAME}
		make -C ${LIB_PATH} fclean

re: fclean all

.PHONY: all clean fclean re bonus