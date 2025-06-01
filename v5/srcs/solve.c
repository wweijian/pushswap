/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:39:39 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/01 23:12:18 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_solution(int *stack_a, int *stack_b, int count)
{
	int			i;
	t_push_data	push_data;

	i = top_of_stack(stack_a, count);
	if (count - i + 1 < 6)
	{
		make_base(stack_a, stack_b, count);
		return ;
	}
	push_data = split_thirds(stack_a, stack_b, count);
	i = top_of_stack(stack_a, count);
	write_solution(stack_a, stack_b, count);
	return_top_partition(stack_a, stack_b, count, push_data);
	return_btm_partition(stack_a, stack_b, count, push_data);
}

/* 
	for (int i = 0; i < count; i++)
		printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
*/

/* 
 printf("hi %d  %d  %d  %d\n", j, stack_b[j], i, stack_a[i]);
 */

/* static void	split_stack(int *stack_a, int *stack_b, int count, int index)
{
	int	i;

	i = 0;
	while (count - i > 3)
	{
		if (stack_a[i] < count - 2)
		{
			push_a_to_b(stack_a, stack_a, count);
			i++;
		}
		else
			rotate_stack(stack_a, NULL, count);
	}
	(void) index;
} */

	// rotate_to_destination(stack_a, count);