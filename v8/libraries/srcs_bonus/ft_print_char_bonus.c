/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:33:29 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/20 19:45:41 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_char(char c, t_flags flags)
{
	int	count;

	count = 0;
	flags.zero = 0;
	flags.precision = 0;
	if (flags.left)
		count += write(1, &c, 1);
	count += write_padding(1, flags);
	if (!flags.left)
		count += write(1, &c, 1);
	return (count);
}
