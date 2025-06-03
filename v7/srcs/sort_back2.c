/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:39:39 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/03 14:58:54 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_back_top(t_stack stack, t_push_data push_data)
{
	int	j;

	j = top_of_stack(stack.b, stack.count);
	if (push_data.count.b_top <= 5)
		return (sort_and_push(stack, push_data.count.b_top));
	push_data.count.a_btm = 0;
	push_data.count.b_btm = 0;
	push_data.partition.top = find_top_partition(stack.b, push_data.count.b_top);
	push_data.partition.btm = find_btm_partition(stack.b, push_data.count.b_top);
	while (push_data.count.b_top > 0)
	{
		if (stack.b[j] < push_data.partition.btm)
			push_data.count.b_btm += sortback_push_b_btm(stack);
		else if (stack.b[j] < push_data.partition.top)
			push_data.count.a_btm += sortback_push_a_btm(stack);
		else
			push_data.count.a_top += sortback_push_a_top(stack);
		push_data.count.b_top--;
	}
	sort_top_partition(stack, push_data);
	sort_mid_partition(stack, push_data);
	sort_btm_partition(stack, push_data);
}

void	sort_top_partition(t_stack stack, t_push_data push_data)
{
	// recreate partition
	// partition chooses which to sort where 
	// takes max available value, min available value
	// how do we know what those are? 
	push_data.partition.top = find_top_partition();
	push_data.partition.btm = find_btm_partition();
	
}

void	sort_btm_partition(t_stack stack, t_push_data push_data)
{
	push_data.count.b_top = 0;
	while (push_data.count.b_btm > 0)
	{
		reverse_rotate_stack_b(stack);
		push_data.count.b_btm--;
		push_data.count.b_top++;
	}
	push_data.max = push_data.min + push_data.count.b_top - 1;
	return (return_top_partition(stack, push_data));
}

/* 
	for (int i = 0; i < count; i++)
		printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
*/