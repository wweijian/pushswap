/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:17:52 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 00:55:15 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*find_solution(int *stack, int count)
{
	int	*stack_sorted;
	int	i;

	i = 0;
	stack_sorted = malloc(sizeof(*stack_sorted) * count);
	if (!stack_sorted)
		return (NULL);
	while (i++ < count)
		stack_sorted[i - 1] = stack[i - 1];
	ft_quicksort(stack_sorted, 0, count - 1);
	return (stack_sorted);
}

void	ft_quicksort(int *stack, int start_index, int end_index)
{
	int	pivot_index;

	if (start_index < end_index)
	{
		pivot_index = ft_partition(stack, start_index, end_index);
		ft_quicksort(stack, start_index, pivot_index - 1);
		ft_quicksort(stack, pivot_index + 1, end_index);
	}
}

int	ft_partition(int *stack, int start_index, int end_index)
{
	int	pivot;
	int	i;
	int	j;

	pivot = stack[end_index];
	i = start_index - 1;
	j = start_index;
	while (j < end_index)
	{
		if (stack[j] < pivot)
		{
			i++;
			ft_swap(&stack[i], &stack[j]);
		}
		j++;
	}
	ft_swap(&stack[i + 1], &stack[end_index]);
	return (i + 1);
}
