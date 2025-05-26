/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:28:50 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/26 19:11:50 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*make_stack(int ac, char **av)
{
	int	i;
	int	*stack;

	i = 1;
	stack = malloc(sizeof(*stack) * (ac - 1));
	if (!stack)
		return (NULL);
	while (av[i])
	{
		if (!validate_argument(av[i]))
		{
			free(stack);
			return (NULL);
		}
		stack[i - 1] = ft_atoi(av[i]);
		i++;
	}
	if (!check_duplicates(stack, i - 1))
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

int	main(int ac, char **av)
{
	int	*stack_a;

	if (ac < 2)
		return (0);
	stack_a = make_stack(ac, av);
	if (!stack_a)
	{
		write(1, "error\n", 6);
		return (0);
	}
	solve_stack(stack_a, ac - 1);
	free(stack_a);
}

// printf("hi\n");