/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_flags_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 00:05:18 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/20 21:18:03 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	*flags_init(void)
{
	t_flags	*flags;

	flags = malloc(sizeof(*flags));
	if (!flags)
		return (NULL);
	flags->width = 0;
	flags->left = 0;
	flags->zero = 0;
	flags->star = 0;
	flags->precision = -1;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	return (flags);
}

static int	check_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static void	check_flags(t_flags *flags, char **format)
{
	if (**format == '#')
		flags->hash = 1;
	if (**format == '0')
	{
		if (flags->left == 0)
			flags->zero = 1;
	}
	if (**format == '-')
	{
		flags->left = 1;
		flags->zero = 0;
	}
	if (**format == '+')
	{
		flags->plus = 1;
		flags->space = 0;
	}
	if (**format == ' ')
	{
		if (flags->plus == 0)
			flags->space = 1;
	}
	(*format)++;
}

static void	flags_atoi(int *num, char **format)
{
	while (ft_isdigit(**format))
	{
		*num = *num * 10 + (**format - '0');
		(*format)++;
	}
}

t_flags	*ft_specifier_flags(char **format)
{
	t_flags	*flags;

	flags = flags_init();
	while (!check_specifier(**format))
	{
		if (ft_strchr("-0# +",**format))
			check_flags(flags, format);
		else if (**format == '.')
		{
			(*format)++;
			flags->precision = 0;
			if (ft_isdigit(**format))
			{
				flags->precision = 0;
				flags_atoi(&flags->precision, format);
			}
		}
		else if (ft_isdigit(**format))
			flags_atoi(&flags->width, format);
	}
	return (flags);
}
