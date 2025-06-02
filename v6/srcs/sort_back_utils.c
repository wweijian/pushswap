/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:19:16 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 11:07:44 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_a(t_stack stack)
{
	rotate_a_to_position(stack);
	push_b_to_a(stack.a, stack.b, stack.count);
}

int	find_stack_a_min(t_stack stack)
{
	int	j;
	int	i;
	int	min_index;

	i = top_of_stack(stack.a, stack.count);
	j = top_of_stack(stack.b, stack.count);
	min_index = 0;
	while (min_index == 0 && i < stack.count)
	{
		if (stack.a[i] > stack.b[j])
			min_index = i;
		i++;
	}
	while (i < stack.count)
	{
		if (stack.b[j] < stack.a[i] && stack.a[i] < stack.a[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	rotate_a_to_position(t_stack stack)
{
	int	i;
	int	min_index;
	int	rotate_counter;

	i = top_of_stack(stack.a, stack.count);
	min_index = find_stack_a_min(stack);
	if (stack.count - min_index < ((stack.count - i) / 2))
	{
		rotate_counter = stack.count - min_index;
		while (rotate_counter > 0)
		{
			reverse_rotate_stack(stack.a, NULL, stack.count);
			rotate_counter--;
		}
	}
	else
	{
		rotate_counter = min_index - i;
		while (rotate_counter > 0)
		{
			rotate_stack(stack.a, NULL, stack.count);
			rotate_counter--;
		}
	}
}
