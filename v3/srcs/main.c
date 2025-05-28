/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:28:50 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/28 14:35:08 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



static void	translate_stack(int **stack, int *stack_sorted, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count)
		{
			if ((*stack)[i] != stack_sorted[j])
				j++;
			else
			{
				(*stack)[i] = j + 1;
				break ;
			}
		}
		i++;
	}
}

static void	solve_stack(int *stack_a, int count)
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
	free(stack_sorted);
	free(stack_b);
}

static int	*make_stack(int ac, char **av)
{
	int	i;
	int	*stack;

	i = 1;
	stack = malloc(sizeof(*stack) * (ac - 1));
	if (!stack)
		return (NULL);
	while (av[i])
	{
		if (!validate_argument(av[i]))
		{
			free(stack);
			return (NULL);
		}
		stack[i - 1] = ft_atoi(av[i]);
		i++;
	}
	if (!check_duplicates(stack, i - 1))
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}

int	main(int ac, char **av)
{
	int	*stack_a;
	setvbuf(stdout, NULL, _IONBF, 0);
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

// printf("hi\n");

/* 
for (int i = 0; i < count; i++)
	printf("index %d:\t%d\n", i, stack_a[i]);
 */