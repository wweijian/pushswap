/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:25:38 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 18:37:51 by wjhoe            ###   ########.fr       */
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
	recursive_solve(stack);
}

void	recursive_solve(t_stack stack)
{
	int			i;
	t_push_data	push_data;

	i = top_of_stack(stack.a, stack.count);
	if (stack.count - i < 6)
	{
		make_base(stack);
		return ;
	}
	push_data = presort_stack(stack);
	recursive_solve(stack);
	sort_b_top(stack, push_data, push_data.mid_third, push_data.top_third - 1);
	if (push_data.mid_third == find_btm_partition(1, stack.count))
		sort_b_top(stack, push_data, i + 1, push_data.mid_third - 1);
	else
		sort_b_btm(stack, push_data, i + 1, push_data.mid_third - 1);
}
