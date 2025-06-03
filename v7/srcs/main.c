/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:28:50 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/03 11:41:42 by wjhoe            ###   ########.fr       */
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
	solve_stack(stack);
	print_solution(stack);
	for (int i = 0; i < stack.count; i++)
		printf("index %d:\t%d\t%d\n", i, stack.a[i], stack.b[i]);
	free(stack.a);
	free(stack.b);
	free(stack.solution);
}

// setvbuf(stdout, NULL, _IONBF, 0);

// xargs ./push_swap < 100.txt | ./checker_linux $(cat 100.txt)