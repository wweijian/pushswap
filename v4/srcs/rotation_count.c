/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:53:40 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/31 00:40:13 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_ra_rotation(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	min_index;

	i = top_of_stack(stack_a, count);
	min_index = find_stack_a_min(stack_a, stack_b, count);
	if (min_index - i < count - min_index)
		return (min_index - i);
	else
		return (count - min_index);
}

int	count_rrb_rotation(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	rotation;
	int	base_num;
	
	rotation = 1;
	i = top_of_stack(stack_a, count);
	base_num = stack_a[count - 1];
	while (stack_b[count - rotation] > stack_a[i] 
			&& stack_b[count - rotation] < base_num
			&& rotation <= count)
		rotation++;
	return (rotation);
}

int	count_rb_rotation(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	j;
	int	base_num;
	int	rotation;

	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	rotation = 1;
	base_num = stack_a[count - 1];
	if (stack_a[count - 1] == count)
		base_num = 0;
	while (stack_b[j + rotation] > stack_a[i]
			&& stack_b[j + rotation] > base_num
			&& j + rotation < count)
		rotation++;
	return (rotation);
}