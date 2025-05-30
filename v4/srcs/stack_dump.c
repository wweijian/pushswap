/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_dump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:48:38 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/31 00:02:50 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	Find the smallest number in stack a
	That is bigger than the number in stack b
*/

#include "push_swap.h"

void	stack_dump(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	j;

	j = top_of_stack(stack_b, count);
	i = top_of_stack(stack_a, count);
	if (stack_b[j] < stack_a[i]
		&& (stack_b[j] > stack_a[count - 1] || stack_a[count - 1] == count))
		j = push_b_to_a(stack_a, stack_b, count);
	if (stack_b[j] < stack_a[i]
		&& (stack_b[j] > stack_a[count - 1] || stack_a[count - 1] == count))
		return (stack_dump(stack_a, stack_b, count));
}

int	count_ra_stack_dump(int *stack_a, int *stack_b, int count)
{
	int	j;
	int base_num;
	int	min_index;
	int	dump_count;

	j = count - count_rrb_rotation(stack_a, stack_b, count);
	min_index = find_stack_a_min(stack_a, stack_b, count);
	dump_count = 1;
	base_num = stack_a[min_index - 1];
	if (top_of_stack(stack_a, count) == min_index)
	{
		base_num = stack_a[count - 1];
		if (base_num == count)
			base_num = 0;
	}
	else if (stack_a[min_index - 1] == count)
		base_num = 0;
	while (stack_b[j + 1] < stack_b[j] && stack_b[j + 1] > base_num
			&& j + 1 < count - 1)
	{
		j++;
		dump_count++;
	}
	return (dump_count);
}

int	count_rb_stack_dump(int *stack_a, int *stack_b, int count)
{
	int	dump_count;
	int	j;
	int base_num;

	dump_count = 1;
	j = top_of_stack(stack_b, count) + count_rb_rotation(stack_a, stack_b, count);
	base_num = stack_a[count - 1];
	if (base_num == count)
		base_num = 0;
	while (stack_b[j + 1] < stack_b[j] && stack_b[j + 1] < base_num 
			&& j + 1 < count - 1)
	{
		j++;
		dump_count++;
	}
	return (dump_count);
}

int	count_rrb_stack_dump(int *stack_a, int *stack_b, int count)
{
	int	dump_count;
	int	j;
	int	base_num;

	j = count - count_rrb_rotation(stack_a, stack_b, count);
	dump_count = 1;
	base_num = stack_a[count - 1];
	if (base_num == count)
		base_num = 0;
	while (stack_b[j + 1] < stack_b[j] && stack_b[j + 1] < base_num 
			&& j + 1 < count - 1)
	{
		j++;
		dump_count++;
	}
	if (stack_b[top_of_stack(stack_b, count)] < stack_b[j])
		j = top_of_stack(stack_b, count);
	while (stack_b[j + 1] < stack_b[j] && stack_b[j + 1] < base_num 
			&& j + 1 < count - 1)
	{
		j++;
		dump_count++;
	}
	return (dump_count);
}