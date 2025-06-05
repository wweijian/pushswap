/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:38:18 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 00:02:56 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_top(t_stack stack, t_push_data push_data, int min, int max)
{
	int j;
	if (push_data.count.b_top <= 5)
		return (finish_sort_b(stack, push_data.count.b_top));
	push_data.count = reset_count(push_data.count.b_top, push_data.count);
	push_data.top_third = find_top_partition(min, max);
	push_data.mid_third = find_btm_partition(min, max);
	while (push_data.count.keep > 0)
	{
		j = top_of_stack(stack.b, stack.count);
		if (stack.b[j] < push_data.mid_third)
			push_data.count.a_btm += push_to_a_btm(stack);
		else if (stack.b[j] < push_data.top_third)
			push_data.count.b_btm += rotate_to_b_btm(stack);
		else
			push_data.count.a_top += push_to_a_top(stack);
		push_data.count.keep--;
	}
	sort_a_top(stack, push_data, push_data.top_third, max);
	sort_b_btm(stack, push_data, push_data.mid_third, push_data.top_third - 1);
	sort_a_btm(stack, push_data, min, push_data.mid_third - 1);
}

void	sort_a_top(t_stack stack, t_push_data push_data, int min, int max)
{
	int i;
	if (push_data.count.a_top <= 5)
		return (finish_sort_a(stack, push_data.count.a_top));
	push_data.count = reset_count(push_data.count.a_top, push_data.count);
	push_data.top_third = find_top_partition(min, max);
	push_data.mid_third = find_btm_partition(min, max);
	while (push_data.count.keep > 0)
	{
		i = top_of_stack(stack.a, stack.count);

		if (stack.a[i] < push_data.mid_third)
			push_data.count.b_btm += push_to_b_btm(stack);
		else if (stack.a[i] < push_data.top_third)
			push_data.count.b_top += push_to_b_top(stack);
		else
			push_data.count.a_btm += rotate_to_a_btm(stack);
		push_data.count.keep--;
	}
	sort_a_btm(stack, push_data, push_data.top_third, max);
	sort_b_top(stack, push_data, push_data.mid_third, push_data.top_third - 1);
	sort_b_btm(stack, push_data, min, push_data.mid_third - 1);
}

void	sort_b_btm(t_stack stack, t_push_data push_data, int min, int max)
{	
	push_data.count = reset_count(push_data.count.b_btm, push_data.count);
	multiple_op(reverse_rotate_stack_b, stack, push_data.count.keep);
	push_data.count.b_top = push_data.count.keep;
	sort_b_top(stack, push_data, min, max);
}

void	sort_a_btm(t_stack stack, t_push_data push_data, int min, int max)
{
	push_data.count = reset_count(push_data.count.a_btm, push_data.count);
	multiple_op(reverse_rotate_stack_a, stack, push_data.count.keep);
	push_data.count.a_top = push_data.count.keep;
	sort_a_top(stack, push_data, min, max);
}