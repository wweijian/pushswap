/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 02:41:44 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 12:44:34 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_data	presort_stack(t_stack stack)
{
	int			i;
	t_partition	partition;
	t_push_data	push_data;

	i = top_of_stack(stack.a, stack.count);
	partition.top = find_top_partition(stack.a, stack.count);
	partition.btm = find_btm_partition(stack.a, stack.count);
	push_data = push_data_init(0, 0, partition.top - 1, i + 1);
	start_stack_b(stack, partition);
	push_data = update_push(stack.b, stack.count, partition, push_data);
	i = top_of_stack(stack.a, stack.count);
	while (i < partition.top - 1)
	{
		if (stack.a[i] < partition.btm)
			push_data.count_btm += presort_push_btm(stack);
		else if (stack.a[i] < partition.top)
		{
			push_data.count_top += presort_push_top(stack);
		}
		else
			rotate_stack(stack.a, NULL, stack.count, stack);
		i = top_of_stack(stack.a, stack.count);
	}
	return (push_data);
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

void	start_stack_b(t_stack stack, t_partition partition)
{
	int	i;
	int	j;

	i = top_of_stack(stack.a, stack.count);
	j = top_of_stack(stack.b, stack.count);
	if (j < stack.count - 1)
		return ;
	while (!(stack.a[i] < partition.top))
		rotate_stack(stack.a, NULL, stack.count, stack);
	push_a_to_b(stack.a, stack.b, stack.count, stack);
	j = top_of_stack(stack.b, stack.count);
	if (j < stack.count - 1 && (stack.b[j] < stack.b[j + 1]))
		swap_b(stack);
	start_stack_b(stack, partition);
}

t_push_data	update_push(int *stack_b, int count, t_partition partition,
							t_push_data push_data)
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
