/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:29:05 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/06 08:50:56 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_min_to_b(t_stack stack, int top, int min_value)
{
	int	i;
	int	count;

	i = top_of_stack(stack.a, stack.count);
	count = top;
	while (count > 0)
	{
		if (stack.a[i] <= min_value + 1)
			i = push_a_to_b(stack);
		else
			rotate_stack_a(stack);
		count--;
	}
	return (count);
}
