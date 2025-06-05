/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:38:07 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 23:35:29 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack_a(t_stack stack)
{
	int	i;

	i = top_of_stack(stack.a, stack.count);
	if (i > stack.count - 2)
		return ;
	reverse_rotate_stack(stack.a, stack.count);
	put_operation(stack, "rra\n");
}

void	reverse_rotate_stack_b(t_stack stack)
{
	int	j;

	j = top_of_stack(stack.a, stack.count);
	if (j > stack.count - 2)
		return ;
	reverse_rotate_stack(stack.b, stack.count);
	put_operation(stack, "rrb\n");
}

void	reverse_rotate_stack_both(t_stack stack)
{
	int	i;
	int	j;

	i = top_of_stack(stack.a, stack.count);
	j = top_of_stack(stack.a, stack.count);
	if (j < stack.count - 2)
		reverse_rotate_stack(stack.b, stack.count);
	if (i < stack.count - 2)
		reverse_rotate_stack(stack.a, stack.count);
	put_operation(stack, "rrr\n");
}

void	reverse_rotate_stack(int *stack, int count)
{
	int	i;
	int	temp;

	i = count - 1;
	temp = stack[i];
	if (count == 2)
		ft_swap(&stack[count - 1], &stack[count - 2]);
	while (i >= 1 && stack[i - 1])
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = temp;
}
