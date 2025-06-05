/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:03:14 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 09:16:46 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sort_rotate(t_stack stack, char* operation)
{
	if (!ft_strncmp(operation, "ra\n", 3))
		rotate_stack_a(stack);
	else if (!ft_strncmp(operation, "rb\n", 3))
		rotate_stack_b(stack);
	else if (!ft_strncmp(operation, "rr\n", 3))
		rotate_stack_both(stack);
}

void	sort_rev_rotate(t_stack stack, char* operation)
{
	if (!ft_strncmp(operation, "rra\n", 4))
		reverse_rotate_stack_a(stack);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		reverse_rotate_stack_b(stack);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		reverse_rotate_stack_both(stack);
}

void	sort_swap(t_stack stack, char* operation)
{
	if (!ft_strncmp(operation, "sa\n", 3))
		swap_top_a(stack);
	else if (!ft_strncmp(operation, "sb\n", 3))
		swap_top_b(stack);
	else if (!ft_strncmp(operation, "ss\n", 3))
		swap_top_both(stack);
}

void	sort_push(t_stack stack, char* operation)
{
	if (!ft_strncmp(operation, "pa\n", 3))
		push_b_to_a(stack);
	else if (!ft_strncmp(operation, "pb\n", 3))
		push_a_to_b(stack);
}