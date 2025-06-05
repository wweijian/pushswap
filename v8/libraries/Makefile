# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 14:55:51 by wjhoe             #+#    #+#              #
#    Updated: 2025/06/03 08:25:02 by wjhoe            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCL = ./includes/
SRCS_PATH = ./srcs/
SRCS_B_PATH = ./srcs_bonus/

SRCS = ${SRCS_PATH}ft_print_null.c ${SRCS_PATH}ft_print_util.c \
	${SRCS_PATH}ft_print_char.c ${SRCS_PATH}ft_print_num.c \
	${SRCS_PATH}ft_specifier_flags.c ${SRCS_PATH}ft_printf.c \
	${SRCS_PATH}ft_print_ptr.c ${SRCS_PATH}ft_print_str.c \
	${SRCS_PATH}ft_print_hex.c ${SRCS_PATH}ft_print_unsigned.c
B_SRCS = ${SRCS_B_PATH}ft_print_null_bonus.c ${SRCS_B_PATH}ft_print_util_bonus.c \
	${SRCS_B_PATH}ft_print_char_bonus.c ${SRCS_B_PATH}ft_print_num_bonus.c \
	${SRCS_B_PATH}ft_specifier_flags_bonus.c ${SRCS_B_PATH}ft_printf_bonus.c \
	${SRCS_B_PATH}ft_print_ptr_bonus.c ${SRCS_B_PATH}ft_print_str_bonus.c \
	${SRCS_B_PATH}ft_print_hex_bonus.c ${SRCS_B_PATH}ft_print_unsigned_bonus.c


OBJS = ${SRCS:.c=.o}
B_OBJS = ${B_SRCS:.c=.o}

LIBFT_PATH = ./libft
LIBFT = ${LIBFT_PATH}/libft.a

AR = ar rcs
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCL}

all: ${NAME}

${NAME}: fclean ${LIBFT} ${OBJS}
		cp ${LIBFT} ${NAME}
		${AR} ${NAME} ${OBJS}

bonus: fclean ${LIBFT} ${B_OBJS}
		cp ${LIBFT} ${NAME}
		${AR} ${NAME} ${B_OBJS}

${LIBFT}:
		make -C ${LIBFT_PATH} bonus

clean:
		${RM} ${OBJS} ${B_OBJS}
		make -C ${LIBFT_PATH} clean

fclean: clean
		${RM} ${NAME}
		make -C ${LIBFT_PATH} fclean

re: fclean all

.PHONY: all clean fclean re bonus