/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 02:41:44 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 23:26:36 by wjhoe            ###   ########.fr       */
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
	while (i < push_data.top_third - 1)
	{
		if (stack.a[i] < push_data.mid_third)
			push_data.count.b_btm += push_to_b_btm(stack);
		else if (stack.a[i] < push_data.top_third)
			push_data.count.b_top += push_to_b_top(stack);
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
	push_data.top_third = find_top_partition(i + 1, stack.count);
	push_data.mid_third = find_btm_partition(i + 1, stack.count);
	push_data.count.a_btm = 0;
	push_data.count.a_top = 0;
	push_data.count.b_btm = 0;
	push_data.count.b_top = 0;
	push_data.count.keep = 0;
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
	while (!(stack.a[i] < push_data.top_third))
		rotate_stack_a(stack);
	push_a_to_b(stack);
	j = top_of_stack(stack.b, stack.count);
	if (j < stack.count - 1 && (stack.b[j] < stack.b[j + 1]))
		swap_top_b(stack);
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
		if (stack_b[j] < push_data.mid_third)
			push_data.count.b_btm++;
		else if (stack_b[j] < push_data.top_third)
			push_data.count.b_top++;
		j++;
	}
	return (push_data);
}
