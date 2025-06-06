/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:28:50 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/06 15:40:08 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;
	t_args	args;

	if (ac < 2)
		return (0);
	args = make_argv(ac, av);
	if (!args.vec)
		return (0);
	stack = init_prog(args.count, args.vec);
	if (!stack.a)
	{
		write(1, "Error\n", 6);
		free_argv(args.vec);
		return (0);
	}
	if (!check_sorted(stack))
	{
		solve_stack(stack);
		print_solution(stack);
	}
	free_argv(args.vec);
	free(stack.a);
	free(stack.b);
	free(stack.solution);
}
