/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:25:38 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 10:58:55 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_stack(t_stack stack)
{
	int	*stack_sorted;

	stack_sorted = find_solution(stack);
	translate_stack(&stack.a, stack_sorted, stack.count);
	if (stack_sorted)
		free (stack_sorted);
	write_solution(stack);
	rotate_to_destination(stack.a, stack.count);
}

void	write_solution(t_stack stack)
{
	int			i;
	t_push_data	push_data;

	i = top_of_stack(stack.a, stack.count);
	if (stack.count - i + 1 < 6)
	{
		make_base(stack);
		return ;
	}
	push_data = presort_stack(stack);
	i = top_of_stack(stack.a, stack.count);
	write_solution(stack);
	return_top_partition(stack, push_data);
	return_btm_partition(stack, push_data);
}