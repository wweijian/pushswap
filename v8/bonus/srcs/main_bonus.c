/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:25:59 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/06 09:23:46 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	int		*stack_sorted;
	t_list	**ops_list;
	t_stack	stack;

	if (ac < 2)
		return (0);
	stack = init_prog(ac, av);
	if (!stack.a)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_sorted = find_solution(stack);
	translate_stack(&stack.a, stack_sorted, stack.count);
	ops_list = malloc(sizeof(void *));
	*ops_list = NULL;
	if (input_operations(stack, ops_list))
		write_result(stack);
	else
		write(2, "Error\n", 6);
	free_all(stack, ops_list, stack_sorted);
}