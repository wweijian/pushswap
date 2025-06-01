/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:28:50 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 01:36:42 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	*stack_a;

	if (ac < 2)
		return (0);
	stack_a = make_stack(ac, av);
	if (!stack_a)
	{
		write(1, "error\n", 6);
		return (0);
	}
	solve_stack(stack_a, ac - 1);
	free(stack_a);
}

// setvbuf(stdout, NULL, _IONBF, 0);