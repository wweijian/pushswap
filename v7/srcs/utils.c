/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 08:46:30 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/04 09:35:38 by wjhoe            ###   ########.fr       */
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

int	find_median(int *stack_a, int count)
{
	int	i;

	i = top_of_stack(stack_a, count);
	return ((count + i) / 2);
}

void	rotate_to_destination(t_stack stack)
{
	while (stack.a[stack.count - 1] != stack.count)
		reverse_rotate_stack_a(stack);
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
			max_index = i - nmemb - 1;
		nmemb--;
	}
	return (max_index);
}
