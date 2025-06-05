/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 19:34:08 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/20 20:41:43 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*ft_utoa(unsigned int num, t_flags flags)
{
	char	*str;
	int		len;

	len = count_digits(num, flags);
	str = malloc(sizeof(*str) * (len + 1));
	while (len > 0)
	{
		str[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

static int	write_num(char *str, int num_len, t_flags flags)
{
	int	count;

	count = 0;
	while (flags.precision-- > num_len)
		count += write(1, "0", 1);
	count += write (1, str, num_len);
	return (count);
}

int	ft_print_unsigned(unsigned int num, t_flags flags)
{
	char	*str;
	int		len;
	int		count;

	count = 0;
	str = ft_utoa(num, flags);
	len = count_digits(num, flags);
	if (flags.left)
		count += write_num(str, len, flags);
	count += write_padding(len, flags);
	if (!flags.left)
		count += write_num(str, len, flags);
	free (str);
	return (count);
}
