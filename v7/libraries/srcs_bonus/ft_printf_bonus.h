/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:18:36 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/20 21:20:17 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_flags
{
	int	width;
	int	left;
	int	zero;
	int	star;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}		t_flags;

/* PRIMARY FUNCTION */
int		ft_printf(const char *format, ...);

/* SPECIFIER FUNCTIONS */
t_flags	*ft_specifier_flags(char **format);
int		ft_print_char(char c, t_flags flags);
int		ft_print_str(char *string, t_flags flags);
int		ft_print_num(int n, t_flags flags);
int		ft_print_hex(unsigned int n, char hex_case, t_flags flags);
int		ft_print_unsigned(unsigned int num, t_flags flags);
int		ft_print_ptr(unsigned long long num, t_flags flags);

/* ANCILLIARY FUNCTIONS */
int		hex_len(unsigned long int num, t_flags flags);
int		max_print(int num1, int num2);
int		count_digits(long num, t_flags flags);
int		write_zero(int num_len, t_flags flags);
int		write_padding(int len, t_flags flags);
int		write_xtoa(unsigned long long num, int len, char hex_case);
int		ft_print_null(t_flags flags);
int		ft_print_null_str(t_flags flags);

#endif