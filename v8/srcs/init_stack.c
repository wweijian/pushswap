/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:48:33 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 18:19:04 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	init_prog(int ac, char **av)
{
	int		i;
	t_stack	stack;

	i = 1;
	if (!validate_argument(av))
		return (empty_stack());
	stack = init_stack(ac, av);
	if (stack.a)
	{
		if (!check_duplicates(stack.a, i - 1))
		{
			free(stack.a);
			free(stack.b);
			free(stack.solution);
			return (empty_stack());
		}
	}
	return (stack);
}

t_stack	init_stack(int ac, char **av)
{
	t_stack	stack;
	int		i;

	i = 1;
	stack.count = ac - 1;
	stack.solution = malloc(sizeof(void *));
	stack.a = malloc(sizeof(*stack.a) * stack.count);
	stack.b = ft_calloc(stack.count, sizeof(*stack.b));
	while (av[i])
	{
		stack.a[i - 1] = ft_atoi(av[i]);
		i++;
	}
	if (stack.a == NULL || stack.b == NULL || stack.solution == NULL)
	{
		if (stack.a != NULL)
			free(stack.a);
		if (stack.b != NULL)
			free(stack.b);
		if (stack.solution != NULL)
			free(stack.solution);
		return (empty_stack());
	}
	return (stack);
}

void	translate_stack(int **stack, int *stack_sorted, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if ((*stack)[i] != stack_sorted[j])
				j++;
			else
			{
				(*stack)[i] = j + 1;
				break ;
			}
		}
		i++;
	}
}

t_stack	empty_stack(void)
{
	t_stack	stack;

	stack.count = 0;
	stack.solution = NULL;
	stack.a = NULL;
	stack.b = NULL;
	return (stack);
}
