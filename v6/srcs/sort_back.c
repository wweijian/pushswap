/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:39:39 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 11:14:07 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	return_top_partition(t_stack stack, t_push_data push_data)
{
	int	j;

	j = top_of_stack(stack.b, stack.count);
	if (push_data.count_top <= 5)
		return (sort_and_push(stack, push_data.count_top));
	push_data.count_btm = 0;
	push_data.median = ((push_data.max - push_data.count_top + 1) + (push_data.max)) / 2;
	while (push_data.count_top > 0)
	{
		if (stack.b[j] > push_data.median)
		{
			sort_to_a(stack);
			j = top_of_stack(stack.b, stack.count);
		}
		else
		{
			rotate_stack(NULL, stack.b, stack.count);
			push_data.count_btm++;
		}
		push_data.count_top--;
	}
	return (return_btm_partition(stack, push_data));
}

void	return_btm_partition(t_stack stack, t_push_data push_data)
{
	push_data.count_top = 0;
	while (push_data.count_btm > 0)
	{
		reverse_rotate_stack(NULL, stack.b, stack.count);
		push_data.count_btm--;
		push_data.count_top++;
	}
	push_data.max = push_data.min + push_data.count_top - 1;
	return (return_top_partition(stack, push_data));
}

int	count_top_stack(int *stack_b, int count, t_push_data push_data)
{
	int	j;
	int	res;
	int	median;

	res = 0;
	j = top_of_stack(stack_b, count);
	median = (push_data.max - push_data.min) / 2;
	while (stack_b[j] <= push_data.max && stack_b[j] > median)
	{
		res++;
		j++;
	}
	return (res);
}

int	count_btm_stack(int *stack_b, int count, t_push_data push_data)
{
	int	j;
	int	res;
	int	median;

	res = 0;
	j = top_of_stack(stack_b, count);
	median = (push_data.max - push_data.min) / 2;
	while (stack_b[j] <= push_data.max && stack_b[j] >= median)
	{
		res++;
		j++;
	}
	return (res);
}

/* 
	for (int i = 0; i < count; i++)
		printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
*/