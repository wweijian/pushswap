/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 08:46:30 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/04 23:55:20 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_of_stack(int *stack, int stack_count)
{
	int	i;

	i = 0;
	while (i < stack_count && !stack[i])
		i++;
	return (i);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

 int	find_max(int *stack, int stack_count, int nmemb)
{
	int	i;
	int	max_index;
	
	i = top_of_stack(stack, stack_count);
	max_index = i;
	while (nmemb)
	{
		if (stack[i + nmemb - 1] > stack[max_index])
			max_index = i + nmemb - 1;
		nmemb--;
	}
	return (max_index);
}

void	multiple_op(void (*f)(t_stack), t_stack stack, int n)
{
	while (n)
	{
		f(stack);
		n--;
	}
}