/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:48:33 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/06 14:08:31 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	init_prog(int ac, char **av)
{
	t_stack	stack;
	int		*stack_sorted;

	if (!validate_argument(av))
		return (empty_stack());
	stack = init_stack(ac, av);
	if (stack.a)
	{
		if (!check_duplicates(stack.a, stack.count))
		{
			free(stack.a);
			free(stack.b);
			free(stack.solution);
			return (empty_stack());
		}
	}
	stack_sorted = find_solution(stack);
	translate_stack(&stack.a, stack_sorted, stack.count);
	if (stack_sorted)
		free (stack_sorted);
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

t_stack	init_stack(int ac, char **av)
{
	t_stack	stack;
	int		i;

	i = 0;
	stack.count = ac;
	stack.solution = malloc(sizeof(void *));
	stack.a = malloc(sizeof(*stack.a) * stack.count);
	stack.b = ft_calloc(stack.count, sizeof(*stack.b));
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
	*(stack.solution) = NULL;
	while (av[i])
	{
		stack.a[i] = ft_atoi(av[i]);
		i++;
	}
	return (stack);
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

int	check_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.count)
	{
		if (stack.a[i] != i + 1)
			return (0);
		i++;
	}
	return (1);
}
