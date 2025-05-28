/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:39:39 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/28 11:36:33 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	if i already push 50 times i'll stop
*/

static void	split_stack(int *stack_a, int *stack_b, int count, int index)
{
	int	i;
	int	median;
	int	rotation;
	int	push_count;

	rotation = 0;
	push_count = 0;
	median = find_median(stack_a, count);
	if (count - index < 3)
		return ;
	while (rotation < count - index || push_count < median - index)
	{
		i = top_of_stack(stack_a, count);
		while (stack_a[i] <= median)
		{
			i = push_a(stack_a, stack_b, count);
			push_count++;
		}
		rotate_stack(stack_a, NULL, count);
		rotation++;
	}
	i = top_of_stack(stack_a, count);
	if (count - i > 3)
		return (split_stack (stack_a, stack_b, count, i));
}

static void	make_base(int *stack_a, int count)
{
	while (stack_a[count - 1] != count)
		rotate_stack(stack_a, NULL, count);
	if (stack_a[count - 2] < stack_a[count - 3])
		swap_top(stack_a, NULL, count);
}

void	stack_dump(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	j;

	j = push_b(stack_a, stack_b, count);
	i = top_of_stack(stack_a, count);
	if (stack_b[j] < stack_a[i] && stack_b[j] > stack_a[count - 1])
		return (stack_dump(stack_a, stack_b, count));
}

void	populate_stack_a(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	j;

	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	if (j == count)
		return ;
	while (j != count && stack_b[j] < stack_a[i])
	{
		j = push_b(stack_a, stack_b, count);
		i = top_of_stack(stack_a, count);
	}
	while (stack_b[j] > stack_a[i])
		rotate_stack(stack_a, NULL, count);
	stack_dump(stack_a, stack_b, count);
	while (stack_a[count - 1] != count)
		reverse_rotate_stack(stack_a, NULL, count);
	return (populate_stack_a(stack_a, stack_b, count));
}

void	write_solution(int *stack_a, int *stack_b, int count)
{
	for (int i = 0; i < count; i++)
		printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
	split_stack(stack_a, stack_b, count, 0);
	for (int i = 0; i < count; i++)
		printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
	make_base(stack_a, count);
	populate_stack_a(stack_a, stack_b, count);
	for (int i = 0; i < count; i++)
		printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
}

/* 
	for (int i = 0; i < count; i++)
		printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
 */

/*
	sa
	ra
	sa
	pa
	sa
	pa
*/

/* 
if (stack_a[i] < median)
{
	if (stack_a[i] < stack_a[i + 1])
		push_a(stack_a, stack_b, count);
	else
		swap_a(stack_a, stack_b, count);
}
 */