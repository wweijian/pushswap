/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 08:46:30 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/29 20:55:34 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	top_of_stack(int *stack, int count)
{
	int	i;

	i = 0;
	while (i < count && !stack[i])
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

void	rotate_to_destination(int *stack_a, int count)
{
	while (stack_a[count - 1] != count)
		rotate_stack(stack_a, NULL, count);
}