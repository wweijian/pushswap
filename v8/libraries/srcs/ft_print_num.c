/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:33:29 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/20 21:18:19 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_sign(int num, t_flags flags)
{
	int	count;

	count = 0;
	if (num < 0)
		count += write (1, "-", 1);
	else
	{
		if (flags.space)
			count += write(1, " ", 1);
		else if (flags.plus)
			count += write(1, "+", 1);
	}
	return (count);
}

static int	write_digit(int num, t_flags flags)
{
	int		count;
	char	*str;

	count = 0;
	if (num == -2147483648)
	{
		count += write(1, "2147483648", 10);
		return (count);
	}
	if (num == 0 && flags.precision == 0)
		return (count);
	if (num < 0)
		num *= -1;
	if (num == 0)
		str = ft_strdup("0");
	else if (num > 0)
		str = ft_itoa(num);
	else
		str = ft_strdup("");
	count += write(1, str, ft_strlen(str));
	free(str);
	return (count);
}

static int	write_num(int num, int num_len, t_flags flags)
{
	int	count;

	count = 0;
	count += write_zero(num_len, flags);
	count += write_digit(num, flags);
	return (count);
}

int	ft_print_num(int num, t_flags flags)
{
	int	count;
	int	len;

	count = 0;
	len = count_digits(num, flags);
	if (num < 0)
		flags.plus = 1;
	if (flags.left)
	{
		count += write_sign(num, flags);
		count += write_num(num, len, flags);
		count += write_padding(len, flags);
	}
	if (!flags.left)
	{
		if (flags.zero == 0)
			count += write_padding(len, flags);
		count += write_sign(num, flags);
		if (flags.zero == 1)
			count += write_padding(len, flags);
		count += write_num(num, len, flags);
	}
	return (count);
}
