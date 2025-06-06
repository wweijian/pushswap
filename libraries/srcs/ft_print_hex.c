/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:26:33 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/20 21:18:27 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_xtoa(unsigned long long num, int len, char hex_case)
{
	char	*res;
	char	*hex_base;
	int		i;
	int		count;

	hex_base = "0123456789ABCDEF";
	i = len;
	count = 0;
	res = ft_calloc((len + 1), sizeof(*res));
	if (!res)
		res = NULL;
	while (i-- > 0)
	{
		res[i] = hex_base[num % 16];
		num = num / 16;
	}
	if (hex_case == 'x')
	{
		while (i++ < len)
			res[i] = ft_tolower(res[i]);
	}
	count += write(1, res, len);
	free (res);
	return (count);
}

int	hex_len(unsigned long int num, t_flags flags)
{
	int	len;

	len = 0;
	if (num == 0 && flags.precision == 0)
		return (0);
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

static int	write_hex(unsigned int num, int len, char hex_case, t_flags flags)
{
	int		count;

	count = 0;
	if (flags.hash == 1 && num > 0)
	{
		if (hex_case == 'X')
			count += write(1, "0X", 2);
		else if (hex_case == 'x')
			count += write(1, "0x", 2);
	}
	count += write_zero(len, flags);
	count += write_xtoa(num, len, hex_case);
	return (count);
}

int	ft_print_hex(unsigned int num, char hex_case, t_flags flags)
{
	int		count;
	int		len;

	count = 0;
	if (num == 0)
		flags.hash = 0;
	len = hex_len(num, flags);
	if (flags.left)
		count += write_hex(num, len, hex_case, flags);
	count += write_padding(len, flags);
	if (!flags.left)
		count += write_hex(num, len, hex_case, flags);
	return (count);
}
