/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:39:39 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/27 11:26:35 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_and_sort(int *stack_a, int *stack_b, int count)
{
	int	median;
	int	i;

	median = count / 2;
	i = top_of_stack(stack_a, count);
	if (stack_a[i] < median)
	{
		if (stack_a[i] < stack_a[i + 1])
			push_a(stack_a, stack_b, count);
		else
			swap_a(stack_a, stack_b, count);
	}
	else
	{
		if (stack_a[i] > stack_a[i + 1])
			swap_a(stack_a, stack_b, count);
		else
			rotate_stack(stack_a, NULL, count);
	}
	if (top_of_stack(stack_b, count) > median)
		return (split_and_sort(stack_a, stack_b, count));
}



void	write_solution(int *stack_a, int *stack_b, int count)
{
	for (int i = 0; i < count; i++)
		printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
	split_and_sort(stack_a, stack_b, count);
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