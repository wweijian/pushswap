/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:39:39 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 01:37:00 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_solution(int *stack_a, int *stack_b, int count)
{
	int			i;
	t_push_data	push_data;

	i = top_of_stack(stack_a, count);
	if (count - i + 1 < 6)
	{
		make_base(stack_a, stack_b, count);
		return ;
	}
	push_data = split_thirds(stack_a, stack_b, count);
	i = top_of_stack(stack_a, count);
	write_solution(stack_a, stack_b, count);
	return_top_partition(stack_a, stack_b, count, push_data);
	return_btm_partition(stack_a, stack_b, count, push_data);
}

void	return_top_partition(int *stack_a, int *stack_b,
							int count, t_push_data push_data)
{
	int	j;

	j = top_of_stack(stack_b, count);
	if (push_data.count_top <= 5)
		return (sort_and_push(stack_a, stack_b, count, push_data.count_top));
	push_data.count_btm = 0;
	push_data.median = ((push_data.max - push_data.count_top + 1) + (push_data.max)) / 2;
	while (push_data.count_top > 0)
	{
		if (stack_b[j] > push_data.median)
		{
			sort_to_a(stack_a, stack_b, count);
			j = top_of_stack(stack_b, count);
		}
		else
		{
			rotate_stack(NULL, stack_b, count);
			push_data.count_btm++;
		}
		push_data.count_top--;
	}
	return (return_btm_partition(stack_a, stack_b, count, push_data));
}

void	return_btm_partition(int *stack_a, int *stack_b,
	int count, t_push_data push_data)
{
	push_data.count_top = 0;
	while (push_data.count_btm > 0)
	{
		reverse_rotate_stack(NULL, stack_b, count);
		push_data.count_btm--;
		push_data.count_top++;
	}
	push_data.max = push_data.min + push_data.count_top - 1;
	return (return_top_partition(stack_a, stack_b, count, push_data));
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