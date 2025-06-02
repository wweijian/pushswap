/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:35:04 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 14:43:09 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_a(t_stack stack)
{
	rotate_stack(stack.a, stack.count);
	put_operation(stack,"ra\n");
}

void	rotate_stack_b(t_stack stack)
{
	rotate_stack(stack.b, stack.count);
	put_operation(stack,"rb\n");
}

void	rotate_stack_both(t_stack stack)
{
	rotate_stack(stack.b, stack.count);
	rotate_stack(stack.a, stack.count);
	put_operation(stack,"rr\n");
}

void	rotate_stack(int *stack, int count)
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
