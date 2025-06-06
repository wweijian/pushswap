/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:25:59 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/06 16:00:20 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	int		*stack_sorted;
	t_list	**ops_list;
	t_stack	stack;
	t_args	args;

	if (ac < 2)
		return (0);
	args = make_argv(ac, av);
	if (!check_status(args.vec))
		return (0);
	stack = init_prog(args.count, args.vec);
	if (!stack.a)
	{
		free_argv(av);
		write(2, "Error\n", 6);
		return (0);
	}
	stack_sorted = find_solution(stack);
	translate_stack(&stack.a, stack_sorted, stack.count);
	ops_list = malloc(sizeof(void *));
	*ops_list = NULL;
	write_result(stack, input_operations(stack, ops_list));
	free_all(stack, ops_list, stack_sorted, args.vec);
}

int	check_status(char **av)
{
	if (!av)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
