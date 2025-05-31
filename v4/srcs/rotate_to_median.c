/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_median.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 02:41:44 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/31 03:19:16 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next_top(int *stack_a, int count, int median)
{
	int	i;
	
	i = top_of_stack(stack_a, count);
	while (stack_a[i] > median)
		i++;
	return (i - top_of_stack(stack_a, count));
}

int	find_next_btm(int *stack_a, int count, int median)
{
	int	i;
	
	if (stack_a[top_of_stack(stack_a, count)] < median)
		return (count);
	i = 1;
	while (stack_a[count - i] > median)
		i++;
	return (i);
}

void	recursive_populate_b(int *stack_a, int *stack_b, int count, int median)
{
	int	i;
	int	next_top;
	int	next_btm;
	
	i = top_of_stack(stack_a, count);
	if (i >= median)
		return ;
	next_top = find_next_top(stack_a, count, median);
	next_btm = find_next_btm(stack_a, count, median);
	if (stack_a[i] <= median)
		push_a_to_b(stack_a, stack_b, count);
	else if (next_top <= next_btm)
	{
		while (stack_a[i] > median)
			rotate_stack(stack_a, NULL, count);
	}
	else
	{
		while (stack_a[i] > median)
			reverse_rotate_stack(stack_a, NULL, count);
	}
	return(recursive_populate_b(stack_a, stack_b, count, median));
}

