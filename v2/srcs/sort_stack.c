/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 20:47:03 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/28 11:27:54 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top(int *stack_a, int *stack_b, int count)
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
		write (1, "sa\n", 3);
	if (!stack_a && stack_b)
		write (1, "sb\n", 3);
	if (stack_a && stack_b)
		write (1, "ss\n", 3);
}

int	push_a(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	j;

	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	ft_swap(&stack_a[i], &stack_b[j - 1]);
	write (1, "pa\n", 3);
	return (top_of_stack(stack_a, count));
}

int	push_b(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	j;

	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	ft_swap(&stack_a[i - 1], &stack_b[j]);
	write (1, "pb\n", 3);
	return (top_of_stack(stack_b, count));
}

void	reverse_rotate_stack(int *stack_a, int *stack_b, int count)
{
	if (stack_a)
		reverse_move_stack(stack_a, count);
	if (stack_b)
		reverse_move_stack(stack_b, count);
	if (stack_a && !stack_b)
		write (1, "rra\n", 4);
	if (!stack_a && stack_b)
		write (1, "rrb\n", 4);
	if (stack_a && stack_b)
		write (1, "rrr\n", 4);
}

void	rotate_stack(int *stack_a, int *stack_b, int count)
{
	if (stack_a)
		move_stack(stack_a, count);
	if (stack_b)
		move_stack(stack_b, count);
	if (stack_a && !stack_b)
		write (1, "ra\n", 3);
	if (!stack_a && stack_b)
		write (1, "rb\n", 3);
	if (stack_a && stack_b)
		write (1, "rr\n", 3);
}
