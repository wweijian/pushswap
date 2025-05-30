/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:48:38 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/29 22:20:35 by wjhoe            ###   ########.fr       */
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

	j = push_b_to_a(stack_a, stack_b, count);
	i = top_of_stack(stack_a, count);
	if (stack_b[j] < stack_a[i]
		&& (stack_b[j] > stack_a[count - 1] || stack_a[count - 1] == count))
		return (stack_dump(stack_a, stack_b, count));
}