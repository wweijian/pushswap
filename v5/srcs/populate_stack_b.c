/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   populate_stack_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 02:41:44 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/01 23:13:02 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	start_stack_b(int *stack_a, int *stack_b, int count, t_partition partition)
{
	int	i;
	int	j;

	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	if (j < count - 1)
		return ;
	while (!(stack_a[i] < partition.top))
		rotate_stack(stack_a, NULL, count);
	push_a_to_b(stack_a, stack_b, count);
	j = top_of_stack(stack_b, count);
	if (j < count - 1 && (stack_b[j] < stack_b[j + 1]))
		swap_b(stack_a, stack_b, count);
	start_stack_b(stack_a, stack_b, count, partition);
}

t_push_data	push_data_init(int count_btm, int count_top, int max, int min)
{
	t_push_data	push_data;

	push_data.count_btm = count_btm;
	push_data.count_top = count_top;
	push_data.max = max;
	push_data.min = min;
	push_data.median = 0;
	return (push_data);
}

t_push_data update_push(int *stack_b, int count,
							t_partition partition, t_push_data push_data)
{
	int	j;

	j = top_of_stack(stack_b, count);
	if (j < count - 3)
		return (push_data);
	while (j < count)
	{
		if (stack_b[j] < partition.btm)
			push_data.count_btm++;
		else if (stack_b[j] < partition.top)
			push_data.count_top++;
		j++;
	}
	return (push_data);
}

t_push_data	split_thirds(int *stack_a, int *stack_b, int count)
{
	int			i;
	
	t_partition	partition;
	t_push_data	push_data;
	i = top_of_stack(stack_a, count);
	partition.top = find_top_partition(stack_a, count);
	partition.btm = find_btm_partition(stack_a, count);
	push_data = push_data_init(0, 0, partition.top - 1, i + 1);
	start_stack_b(stack_a, stack_b, count, partition);
	push_data = update_push(stack_b, count, partition, push_data);
	i = top_of_stack(stack_a, count);
	while (i < partition.top - 1)
	{
		if (stack_a[i] < partition.btm)
			push_data.count_btm += presort_push_btm(stack_a, stack_b, count);
		else if (stack_a[i] < partition.top)
		{
			push_data.count_top += presort_push_top(stack_a, stack_b, count);
		}
		else
			rotate_stack(stack_a, NULL, count);
		i = top_of_stack(stack_a, count);
	}
	return (push_data);
}
