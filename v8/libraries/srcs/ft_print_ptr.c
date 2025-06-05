/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 20:25:05 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/20 21:17:38 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_address(unsigned long long num, int len)
{
	int		count;

	count = 0;
	count += write(1, "0x", 2);
	count += write_xtoa(num, len, 'x');
	return (count);
}

int	ft_print_ptr(unsigned long long num, t_flags flags)
{
	int		count;
	int		len;

	count = 0;
	flags.zero = 0;
	flags.hash = 1;
	if (num == 0)
	{
		count += ft_print_null(flags);
		return (count);
	}
	len = hex_len(num, flags);
	if (flags.left)
		count += write_address(num, len);
	count += write_padding(len, flags);
	if (!flags.left)
		count += write_address(num, len);
	return (count);
}
