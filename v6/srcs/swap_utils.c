/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:14:32 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 14:53:43 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack stack)
{
	int	j;

	j = top_of_stack(stack.b, stack.count);
	if (j < stack.count - 1)
	{
		if (stack.b[j] < stack.b[j + 1])
		{
			swap_top_both(stack);
		}
		else
			swap_top_a(stack);
	}
	else
		swap_top_a(stack);
}

void	swap_b(t_stack stack)
{
	int	i;

	i = top_of_stack(stack.a, stack.count);
	if (i < stack.count - 1)
	{
		if (stack.a[i] > stack.a[i + 1])
		{
			swap_top_both(stack);
		}
		else
			swap_top_b(stack);
	}
	else
		swap_top_b(stack);
}
