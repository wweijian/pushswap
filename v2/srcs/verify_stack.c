/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:44:54 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/27 13:57:54 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_stack_a(int *stack_a, int count)
{
	int	median;
	int	i;

	median = find_median(count);
	i = top_of_stack(stack_a, count);
	if (i != median)
		return (0);
	while (i < count)
	{
		if (stack_a[i] != i + 1)
			return (0);
		i++;
	}
	return (1);
}