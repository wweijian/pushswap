/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_op_cost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:56:15 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/29 22:00:25 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_dump_count(int *stack, int count, int index)
{
	int	i;
	i = 1;
	while (stack[index + i - 1] > stack[index + i] && (index + i) < (count - 1))
		i++;
	return (i);
}

int	count_ra_score(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	j;
	int	ra;
	int	rra;

	ra = 1;
	rra = 1;
	i = top_of_stack (stack_a, count);
	j = top_of_stack (stack_b, count);
	while (stack_a[i + ra] < stack_b[j])
		ra++;
	while (stack_a[count - rra] < stack_b[j])
		rra++;
	if (ra != 0)
		ra = stack_dump_count(stack_b, count, 0) / ra;
	if (rra != 0)
		rra = stack_dump_count(stack_b, count, 0) / rra;
	if (ra > rra)
		return (ra);
	else
		return (rra);
}

int	count_rb(int *stack_a, int *stack_b, int count)
{
	int	j;
	int	i;
	int	rb;

	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	rb = 1;
	while (stack_b[rb + j - 1] > stack_a[i] && rb + j - 1 < count)
		rb++;
	return (stack_dump_count(stack_b, count, j + rb - 1) / rb);
}

int	count_rrb_dump(int *stack_b, int count, int rrb)
{
	int dump_count; 
	
	if (rrb == 0)
		return (0);
	dump_count = 0;
	while (stack_b[count - 1 - rrb] < stack_b[count - 1 - rrb + 1])
	{
		rrb++;
		dump_count++;
	}
	if (stack_b[top_of_stack(stack_b, count)] > stack_b[count])
		dump_count += stack_dump_count(stack_b, count, 0);
	return(dump_count);
}

int	count_rb_score(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	j;
	int	rb;
	int	rrb;

	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	rrb = 1;
	rb = count_rb(stack_a, stack_b, count);
	if (stack_a[i] < stack_b[j])
		while (stack_b[count - rrb] > stack_a[i])
			rrb++;
	if (rb != 0)
		rb = stack_dump_count(stack_b, count, rb) / rb;
	if (rrb != 0)
		rrb = count_rrb_dump(stack_b, count, rrb) / rrb;
	if (rrb > rb)
		return (rrb);
	else
		return (rb);
}

// printf(">> hi2 << \n");
// for (int x = 0; x < count; x++)
// 		printf("index %d:\t%d\t\t%d\n", x, stack_a[x], stack_b[x]);