/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 23:34:10 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/27 09:17:39 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_move_stack(int *stack, int count)
{
	int	i;
	int	temp;

	i = count - 1;
	temp = stack[i];
	if (count == 2)
	{
		stack[1] = stack[0];
		stack[0] = temp;
		return ;
	}
	while (stack[i - 1] || i == 1)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = temp;
}

void	move_stack(int *stack, int count)
{
	int	i;
	int	temp;

	i = 0;
	while (!stack[i] && i < count)
		i++;
	temp = stack[i];
	if (count == 2)
	{
		stack[0] = stack[1];
		stack[1] = temp;
		return ;
	}
	while (!stack[i])
		i++;
	while (i < count - 1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = temp;
}
