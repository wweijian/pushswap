/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:28:50 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 20:54:02 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac < 2)
		return (0);
	stack = init_prog(ac, av);
	if (!stack.a)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (!check_sorted(stack))
	{
		solve_stack(stack);
		print_solution(stack);
	}
	free(stack.a);
	free(stack.b);
	free(stack.solution);
}

// ./ps_gen.sh -s 500-500 -t 5500