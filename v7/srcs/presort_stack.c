/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 02:41:44 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/03 15:05:12 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_data	presort_stack(t_stack stack)
{
	int			i;
	t_push_data	push_data;

	i = top_of_stack(stack.a, stack.count);
	push_data = push_data_init(stack);
	start_stack_b(stack, push_data);
	push_data = update_push(stack.b, stack.count, push_data);
	i = top_of_stack(stack.a, stack.count);
	while (i < push_data.partition.top - 1)
	{
		if (stack.a[i] < push_data.partition.btm)
			push_data.count.b_btm += presort_push_btm(stack);
		else if (stack.a[i] < push_data.partition.top)
			push_data.count.b_top += presort_push_top(stack);
		else
			rotate_stack_a(stack);
		i = top_of_stack(stack.a, stack.count);
	}
	return (push_data);
}

t_push_data	push_data_init(t_stack stack)
{
	t_push_data	push_data;
	int			i;

	i = top_of_stack(stack.a, stack.count);
	push_data.min = i + 1;
	push_data.partition.top = find_top_partition(push_data.min, stack.count);
	push_data.partition.btm = find_btm_partition(push_data.min, stack.count);
	push_data.max = push_data.partition.top - 1;
	push_data.count.a_btm = 0;
	push_data.count.b_btm = 0;
	push_data.count.b_top = 0;
	return (push_data);
}

void	start_stack_b(t_stack stack, t_push_data push_data)
{
	int	i;
	int	j;

	i = top_of_stack(stack.a, stack.count);
	j = top_of_stack(stack.b, stack.count);
	if (j < stack.count - 1)
		return ;
	while (!(stack.a[i] < push_data.partition.top))
		rotate_stack_a(stack);
	push_a_to_b(stack);
	j = top_of_stack(stack.b, stack.count);
	if (j < stack.count - 1 && (stack.b[j] < stack.b[j + 1]))
		swap_b(stack);
	start_stack_b(stack, push_data);
}

t_push_data	update_push(int *stack_b, int count, t_push_data push_data)
{
	int	j;

	j = top_of_stack(stack_b, count);
	if (j < count - 3)
		return (push_data);
	while (j < count)
	{
		if (stack_b[j] < push_data.partition.btm)
			push_data.count.b_btm++;
		else if (stack_b[j] < push_data.partition.top)
			push_data.count.b_top++;
		j++;
	}
	return (push_data);
}
