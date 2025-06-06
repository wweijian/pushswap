/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:51:22 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/06 16:00:46 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_args	make_argv(int ac, char **av)
{
	t_args	args;
	char	*temp;
	int		i;
	int		arg_len;

	i = 1;
	args.count = 0;
	arg_len = 1;
	while (i < ac)
	{
		arg_len += ft_strlen(av[i]) + 1;
		i++;
	}
	temp = make_single_string(ac, av, arg_len);
	if (!temp)
	{
		args.vec = NULL;
		return (args);
	}
	args.vec = ft_split(temp, ' ');
	while (args.vec[args.count])
		args.count++;
	free(temp);
	return (args);
}

void	free_argv(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

char	*make_single_string(int ac, char **av, int arg_len)
{
	int		i;
	char	*temp;

	i = 1;
	temp = ft_calloc(arg_len, sizeof(char));
	if (temp == NULL)
		return (NULL);
	while (i < ac)
	{
		ft_strlcat(temp, av[i], arg_len);
		ft_strlcat(temp, " ", arg_len);
		if (!ft_strncmp(av[i], "", 1))
		{
			free(temp);
			return (NULL);
		}
		i++;
	}
	return (temp);
}
