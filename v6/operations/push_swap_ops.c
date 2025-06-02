/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:47:03 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 12:41:37 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(int *stack_a, int *stack_b, int count, t_stack stack)
{
	int	i;

	if (stack_a)
	{
		i = top_of_stack(stack_a, count);
		ft_swap(&stack_a[i], &stack_a[i + 1]);
	}
	if (stack_b)
	{
		i = top_of_stack(stack_b, count);
		ft_swap(&stack_b[i], &stack_b[i + 1]);
	}
	if (stack_a && !stack_b)
		put_operation(stack,"sa\n");
	if (!stack_a && stack_b)
		put_operation(stack,"sb\n");
	if (stack_a && stack_b)
		put_operation(stack,"ss\n");
}

int	push_a_to_b(int *stack_a, int *stack_b, int count, t_stack stack)
{
	int	i;
	int	j;

	if (!stack_a[count - 1])
		return (count);
	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	ft_swap(&stack_a[i], &stack_b[j - 1]);
	put_operation(stack,"pb\n");
	return (top_of_stack(stack_a, count));
}

int	push_b_to_a(int *stack_a, int *stack_b, int count, t_stack stack)
{
	int	i;
	int	j;

	if (!stack_b[count - 1])
		return (count);
	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	ft_swap(&stack_a[i - 1], &stack_b[j]);
	put_operation(stack,"pa\n");
	return (top_of_stack(stack_b, count));
}

void	reverse_rotate_stack(int *stack_a, int *stack_b, int count, t_stack stack)
{
	if (stack_a)
		reverse_move_stack(stack_a, count);
	if (stack_b)
		reverse_move_stack(stack_b, count);
	if (stack_a && !stack_b)
		put_operation(stack,"rra\n");
	if (!stack_a && stack_b)
		put_operation(stack,"rrb\n");
	if (stack_a && stack_b)
		put_operation(stack,"rrr\n");
}

void	rotate_stack(int *stack_a, int *stack_b, int count, t_stack stack)
{
	if (stack_a)
		move_stack(stack_a, count);
	if (stack_b)
		move_stack(stack_b, count);
	if (stack_a && !stack_b)
		put_operation(stack,"ra\n");
	if (!stack_a && stack_b)
		put_operation(stack,"rb\n");
	if (stack_a && stack_b)
		put_operation(stack,"rr\n");
}
