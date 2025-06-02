/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:19:16 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 01:32:06 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_a(int *stack_a, int *stack_b, int count)
{
	rotate_a_to_position(stack_a, stack_b, count);
	push_b_to_a(stack_a, stack_b, count);
}

int	find_stack_a_min(int *stack_a, int *stack_b, int count)
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
	while (i < count)
	{
		if (stack_b[j] < stack_a[i] && stack_a[i] < stack_a[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	rotate_a_to_position(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	min_index;
	int	rotate_counter;

	i = top_of_stack(stack_a, count);
	min_index = find_stack_a_min(stack_a, stack_b, count);
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
