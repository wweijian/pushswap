/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 00:48:33 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 00:50:54 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_stack(int *stack_a, int count)
{
	int	*stack_b;
	int	*stack_sorted;

	stack_b = ft_calloc(count, sizeof(*stack_b));
	if (!stack_b)
		return ;
	stack_sorted = find_solution(stack_a, count);
	if (!stack_sorted)
	{
		free(stack_b);
		return ;
	}
	translate_stack(&stack_a, stack_sorted, count);
	write_solution(stack_a, stack_b, count);
	rotate_to_destination(stack_a, count);
	free(stack_sorted);
	free(stack_b);
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

/* 
for (int i = 0; i < count; i++)
	printf("index %d:\t%d\n", i, stack_a[i]);
 */