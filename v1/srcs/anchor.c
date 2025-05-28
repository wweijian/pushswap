/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anchor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:39:04 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/27 22:49:04 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	purpose of find_anchor is to use the number which should be in the lowest
	position and then put it there and use it as an anchor

	count - index gives me the distance to the bottom
	index - top_of_stack gives me the distance to the top
	these 2 are related by these 2 added together should give me height of stack

	reverse rotate, moves down  | rotate moves up

	if ((count - i) - (j - top_of_stack(stack_b, count)) <= median / 2)
	if i can turn in opposite directions under height / 2, i should do it
	otherwise, it's not that much more efficient than turning same direction
	
	The other consideration is the follwing
	if ((count - i) - (count - j) >= median / 2)
	which really is just the inverse, but if they're at least height / 2 apart
	then it'll be more efficient to rotate in a different direction

	we go into anchor rra knowing:
	anchor for a is closer to bottom
	anchor for b is closer from the top
	
*/


void	anchor_rra_rb(int *stack_a, int *stack_b, int count)
{
	rev_rotate_to_anchor_a(stack_a, stack_b, count);
	rotate_to_anchor_b(stack_a, stack_b, count);
}

void	anchor_ra_rrb(int *stack_a, int *stack_b, int count)
{
	rotate_to_anchor_a(stack_a, stack_b, count);
	rev_rotate_to_anchor_b(stack_a, stack_b, count);
}

void	anchor_rra_rrb(int *stack_a, int *stack_b, int count)
{
	while (stack_a[count - 1] != count && stack_b[count - 1] != 1)
	{
		if (stack_a[count - 2] != count && stack_b[count - 2] != 1)
		{
			check_swap_a(stack_a, stack_b, count);
			check_swap_b(stack_a, stack_b, count);
			reverse_rotate_stack(stack_a, stack_b, count);
		}
		reverse_rotate_stack(stack_a, stack_b, count);
	}
	rev_rotate_to_anchor_a(stack_a, stack_b, count);
	rev_rotate_to_anchor_b(stack_a, stack_b, count);
}

void	anchor_ra_rb(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	j;

	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	while (stack_a[count - 1] != count && stack_b[count - 1] != 1)
	{
		if (stack_a[i] != count && stack_b[j] != 1)
		{
			check_swap_a(stack_a, stack_b, count);
			check_swap_b(stack_a, stack_b, count);
			reverse_rotate_stack(stack_a, stack_b, count);
		}
		reverse_rotate_stack(stack_a, stack_b, count);
	}
	rotate_to_anchor_a(stack_a, stack_b, count);
	rotate_to_anchor_b(stack_a, stack_b, count);
}

void	find_anchor(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	j;
	int	median;

	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	median = find_median(count);
	while (stack_a[i] != count)
		i++;
	while (stack_b[j] != 1)
		j++;
	if (i == count && j == count)
		return ;
	if ((count - 1 - i) + (j - top_of_stack(stack_b, count)) <= median / 2)
		anchor_rra_rb(stack_a, stack_b, count);
	else if ((i - top_of_stack(stack_a, count)) + (count - 1 - j) <= median / 2)
		anchor_ra_rrb(stack_a, stack_b, count);
	else if ((count - 1 - i) + (count - 1 - j) < median)
		anchor_rra_rrb(stack_a, stack_b, count);
	else
		anchor_ra_rb(stack_a, stack_b, count);
}
