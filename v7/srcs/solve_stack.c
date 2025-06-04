/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 09:25:38 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/04 13:11:13 by wjhoe            ###   ########.fr       */
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
	// for (int i = 0; i < stack.count; i++)
	// 	printf("index %d:\t%d\t%d\n", i, stack.a[i], stack.b[i]);
	recursive_solve(stack);
	rotate_to_destination(stack);
}

void	recursive_solve(t_stack stack)
{
	int			i;
	t_push_data	push_data;

	i = top_of_stack(stack.a, stack.count);
	if (stack.count - i < 6)
	{
		make_base(stack);
		// for (int i = 0; i < stack.count; i++)
		// 	printf("index %d:\t%d\t%d\n", i, stack.a[i], stack.b[i]);
		return ;
	}
	printf("\nSOLVE STACK: RECURSIVE SOLVE\n");
	// for (int i = 0; i < stack.count; i++)
	// 	printf("index %d:\t%d\t%d\n", i, stack.a[i], stack.b[i]);
	push_data = presort_stack(stack);
	recursive_solve(stack);
	sort_b_top(stack, push_data);
	sort_b_btm(stack, push_data);
}

/* 

printf(">> hi << \n");

for (int i = 0; i < count; i++)
	printf("index %d:\t%d\t%d\n", i, stack.a[i], stack.b[i]);
*/