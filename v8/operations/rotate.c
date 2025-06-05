/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:35:04 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 19:24:38 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_a(t_stack stack)
{
	int i;
	
	i = top_of_stack(stack.a, stack.count);
	if (i > stack.count - 2)
		return ;
	rotate_stack(stack.a, stack.count);
	put_operation(stack,"ra\n");
}

void	rotate_stack_b(t_stack stack)
{
	int j;
	
	j = top_of_stack(stack.a, stack.count);
	if (j > stack.count - 2)
		return ;
	rotate_stack(stack.b, stack.count);
	put_operation(stack,"rb\n");
}

void	rotate_stack_both(t_stack stack)
{
	int	i;
	int	j;
	
	i = top_of_stack(stack.a, stack.count);
	j = top_of_stack(stack.a, stack.count);
	if (j < stack.count - 2)
		rotate_stack(stack.b, stack.count);
	if (i < stack.count - 2)
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
