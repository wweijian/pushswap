/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:25:38 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 09:27:03 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_stack(int *stack_a, int count)
{
	int	*stack_b;
	int	*stack_sorted;

	stack_b = ft_calloc(count, sizeof(*stack_b));
	if (!stack_b)
		return ;
	stack_sorted = find_solution(stack_a, count);
	if (!stack_sorted)
	{
		free(stack_b);
		return ;
	}
	translate_stack(&stack_a, stack_sorted, count);
	write_solution(stack_a, stack_b, count);
	rotate_to_destination(stack_a, count);
	free(stack_sorted);
	free(stack_b);
}

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
	push_data = presort_stack(stack_a, stack_b, count);
	i = top_of_stack(stack_a, count);
	write_solution(stack_a, stack_b, count);
	return_top_partition(stack_a, stack_b, count, push_data);
	return_btm_partition(stack_a, stack_b, count, push_data);
}