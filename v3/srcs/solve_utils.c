/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:48:38 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/28 16:43:13 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	Find the smallest number in stack a
	That is bigger than the number in stack b
*/

#include "push_swap.h"

static int	find_stack_min(int *stack_a, int *stack_b, int count)
{
	int	j;
	int	i;
	int	min_index;

	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	min_index = 0;
	while (min_index == 0 && i < count)
	{
		if (stack_a[i] > stack_b[j])
			min_index = i;
		i++;
	}
	// printf("stack_a[%d]: %d > stack_b[%d]: %d\n", i, stack_a[i], j, stack_b[j]);
	while (i < count)
	{
		if (stack_a[i] > stack_b[j] && stack_a[i] < stack_a[min_index])
			min_index = i;
		i++;
	}
	// printf("min_index: %d   stacka[i]: %d,   stackb[j]: %d\n", min_index, stack_a[i], stack_b[j]);
	return (min_index);
}

void	rotate_to_min(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	min_index;
	int	rotate_counter;

	i = top_of_stack(stack_a, count);
	min_index = find_stack_min(stack_a, stack_b, count);
	if (count - min_index < ((count - i) / 2))
	{
		rotate_counter = count - min_index;
		while (rotate_counter > 0)
		{
			reverse_rotate_stack(stack_a, NULL, count);
			rotate_counter--;
		}
	}
	else
	{
		rotate_counter = min_index - i;
		while (rotate_counter > 0)
		{
			rotate_stack(stack_a, NULL, count);
			rotate_counter--;
		}
	}
}

void	rotate_to_destination(int *stack_a, int count)
{
	while (stack_a[count - 1] != count)
		rotate_stack(stack_a, NULL, count);
}
