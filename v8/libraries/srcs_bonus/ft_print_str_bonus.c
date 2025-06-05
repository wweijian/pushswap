/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:11:14 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/20 20:42:53 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	write_str_padding(int max_chars, t_flags flags)
{
	int	count;

	count = 0;
	while (flags.width-- > max_chars)
	{
		if (flags.zero)
			count += write(1, "0", 1);
		else
			count += write(1, " ", 1);
	}
	return (count);
}

int	ft_print_str(char *str, t_flags flags)
{
	int		max_chars;
	int		count;

	count = 0;
	flags.zero = 0;
	if (!str)
	{
		count += ft_print_null_str(flags);
		return (count);
	}
	max_chars = ft_strlen(str);
	if (max_chars > flags.precision && flags.precision != -1)
		max_chars = flags.precision;
	if (flags.left)
		count += write(1, str, max_chars);
	flags.precision = -1;
	count += write_str_padding(max_chars, flags);
	if (!flags.left)
		count += write(1, str, max_chars);
	return (count);
}
