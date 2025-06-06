/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_null_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:55:53 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/20 21:17:28 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_null(t_flags flags)
{
	int	count;

	count = 0;
	flags.zero = 0;
	if (flags.left)
		count += write (1, "(nil)", 5);
	count += write_padding(3, flags);
	if (!flags.left)
		count += write (1, "(nil)", 5);
	return (count);
}

int	ft_print_null_str(t_flags flags)
{
	int		count;
	int		len;
	char	*str;

	count = 0;
	if (flags.precision == -1)
		str = ft_strdup("(null)");
	else if (flags.precision > 5)
		str = ft_strdup("(null)");
	else
	{
		flags.precision = 0;
		str = ft_strdup("");
	}
	len = ft_strlen(str);
	if (flags.left)
		count += write(1, str, len);
	count += write_padding(len, flags);
	if (!flags.left)
		count += write(1, str, len);
	free(str);
	return (count);
}
