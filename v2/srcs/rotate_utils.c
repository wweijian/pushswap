/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 22:06:48 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/27 22:52:47 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_to_anchor_a(int *stack_a, int *stack_b, int count)
{
	while (stack_a[count - 1] != count)
	{
		if (stack_a[count - 2] != count)
		{
			check_swap_a(stack_a, stack_b, count);
			reverse_rotate_stack(stack_a, NULL, count);
		}
		reverse_rotate_stack(stack_a, NULL, count);
	}
}

void	rev_rotate_to_anchor_b(int *stack_a, int *stack_b, int count)
{
	while (stack_b[count - 1] != 1)
	{
		if (stack_b[count - 2] != 1)
		{
			check_swap_b(stack_a, stack_b, count);
			reverse_rotate_stack(NULL, stack_b, count);
		}
		reverse_rotate_stack(NULL, stack_b, count);
	}
}

void	rotate_to_anchor_a(int *stack_a, int *stack_b, int count)
{
	int	i;

	i = top_of_stack(stack_a, count);
	while (stack_a[count - 1] != count)
	{
		if (stack_a[i] != count)
		{
			check_swap_a(stack_a, stack_b, count);
			rotate_stack(stack_a, NULL, count);
		}
		rotate_stack(stack_a, NULL, count);
	}
}

void	rotate_to_anchor_b(int *stack_a, int *stack_b, int count)
{
	int	i;

	i = top_of_stack(stack_b, count);
	while (stack_b[count - 1] != 1)
	{
		if (stack_b[i] != 1)
		{
			check_swap_b(stack_a, stack_b, count);
			rotate_stack(NULL, stack_b, count);
		}
		rotate_stack(NULL, stack_b, count);
	}
}


