/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:19:16 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/29 22:42:51 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (stack_a[i] > stack_b[j] && stack_a[i] < stack_a[min_index])
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

int	find_direction_b(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	rb;
	int	rrb;
	i = top_of_stack(stack_a, count);
	rrb = 0;
	rb = count_rb(stack_a, stack_b, count);
	while (stack_b[count - 1 - rrb] > stack_a[i])
		rrb++;
	if (rb != 0)
		rb = stack_dump_count(stack_b, count, rb) / rb;
	if (rrb != 0)
		rrb = count_rrb_dump(stack_b, count, rrb) / rrb;
	if (rrb > rb)
		return (-1);
	else
		return (1);
}

void	rotate_b_to_position(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	j;
	int	direction;

	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	direction = find_direction_b(stack_a, stack_b, count);
	while (stack_a[i] < stack_b[j])
	{
		printf("stack_a[%d] = %d, stack_b[%d] = %d\n", i, stack_a[i], j, stack_b[j]);
		if (direction == -1)
			reverse_rotate_stack(NULL, stack_b, count);
		if (direction == 1)
			rotate_stack(NULL, stack_b, count);
	}
	printf("[after] stacka: %d stackb: %d\n", stack_a[i], stack_b[j]);
}

void	rotate_to_next_op(int *stack_a, int *stack_b, int count)
{
	int	ra;
	int	rb;
	ra = count_ra_score(stack_a, stack_b, count);
	rb = count_rb_score(stack_a, stack_b, count);
	printf("rotation starts here\nra: %d rb: %d\t",ra ,rb);
	if (ra > rb)
	{
		printf("rotate a\n");
		rotate_a_to_position(stack_a, stack_b, count);
	}
	else
	{
		printf("rotate b\n");
		rotate_b_to_position(stack_a, stack_b, count);
	}
}

// printf(">> hi << \n");
