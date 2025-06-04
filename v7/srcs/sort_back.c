/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:39:39 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/04 13:24:06 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_top(t_stack stack, t_push_data push_data)
{
	int	j;
printf("\nSORT B TOP\n");
	if (push_data.count.b_top <= 5)
		return (sort_and_push(stack, push_data.count.b_top));
	push_data = reset_push_data(push_data, 3);
	push_data.count = reset_count(push_data.count.b_top, push_data.count);
	push_data.count.b_top = push_data.count.keep;
	while (push_data.count.b_top > 0)
	{
		j = top_of_stack(stack.b, stack.count);
		if (stack.b[j] < push_data.partition.btm)
			push_data.count.b_btm += sortback_push_b_btm(stack);
		else if (stack.b[j] < push_data.partition.top)
			push_data.count.a_btm += sortback_push_a_btm(stack);
		else
			push_data.count.a_top += sortback_push_a_top(stack);
		push_data.count.b_top--;
	}
	// for (int i = 0; i < stack.count; i++)
	// 	printf("index %d:\t%d\t%d\n", i, stack.a[i], stack.b[i]);
	sort_a_top(stack, push_data);
	sort_a_btm(stack, push_data);
	sort_b_btm(stack, push_data);
}

void	sort_a_top(t_stack stack, t_push_data push_data)
{
	int	i;
	printf("\nSORT A TOP\n");

	push_data = reset_push_data(push_data, 3);
	push_data.count = reset_count(push_data.count.a_top, push_data.count);
	push_data.count.a_top = push_data.count.keep;
	printf("push_data.count.a_top: %d\n", push_data.count.a_top);
	if (push_data.count.a_top <= 5)
		return (finish_a_top(stack, push_data.count.b_top));
	while (push_data.count.a_top > 0)
	{
		i = top_of_stack(stack.a, stack.count);
		printf("stack.a[i] %d < push_data.partition.btm%d  push_data.partition.top:%d\n", stack.a[i], push_data.partition.btm, push_data.partition.top);
		if (stack.a[i] < push_data.partition.btm)
			push_data.count.b_btm += presort_push_btm(stack);
		else if (stack.a[i] < push_data.partition.top)
			push_data.count.b_top += presort_push_top(stack);
		else
			push_data.count.a_btm += rotate_to_btm_a(stack);
		push_data.count.a_top--;
	}
	for (int i = 0; i < stack.count; i++)
		printf("index %d:\t%d\t%d\n", i, stack.a[i], stack.b[i]);
	sort_a_btm(stack,push_data);
	sort_b_top(stack, push_data);
	sort_b_btm(stack, push_data);
}


void	sort_b_btm(t_stack stack, t_push_data push_data)
{
	printf("\nSORT B BTM\n");
	push_data = reset_push_data(push_data, 1);
	push_data.count = reset_count(push_data.count.b_btm, push_data.count);
	push_data.count.b_btm = push_data.count.keep;
	while (push_data.count.b_btm > 0)
	{
		reverse_rotate_stack_b(stack);
		push_data.count.b_btm--;
		push_data.count.b_top++;
	}
	// for (int i = 0; i < stack.count; i++)
	// 	printf("index %d:\t%d\t%d\n", i, stack.a[i], stack.b[i]);
	// printf("\nFROM: SORT B BTM ");
	return (sort_b_top(stack, push_data));
}

void	sort_a_btm(t_stack stack, t_push_data push_data)
{	
	printf("\nSORT A BTM\n");

	push_data = reset_push_data(push_data, 3);
	push_data.count = reset_count(push_data.count.a_btm, push_data.count);
	push_data.count.a_btm = push_data.count.keep;
	while (push_data.count.a_btm > 0)
	{
		reverse_rotate_stack_a(stack);
		push_data.count.a_btm--;
		push_data.count.a_top++;
	}
	// for (int i = 0; i < stack.count; i++)
	// 	printf("index %d:\t%d\t%d\n", i, stack.a[i], stack.b[i]);
	return (sort_a_top(stack, push_data));
}


/* 
	for (int i = 0; i < count; i++)
		printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
*/