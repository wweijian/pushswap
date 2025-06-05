/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:32:26 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 23:35:56 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_a_to_b(t_stack stack)
{
	int	i;
	int	j;

	if (!stack.a[stack.count - 1])
		return (stack.count);
	i = top_of_stack(stack.a, stack.count);
	j = top_of_stack(stack.b, stack.count);
	ft_swap(&stack.a[i], &stack.b[j - 1]);
	put_operation(stack, "pb\n");
	return (top_of_stack(stack.a, stack.count));
}

int	push_b_to_a(t_stack stack)
{
	int	i;
	int	j;

	if (!stack.b[stack.count - 1])
		return (stack.count);
	i = top_of_stack(stack.a, stack.count);
	j = top_of_stack(stack.b, stack.count);
	ft_swap(&stack.a[i - 1], &stack.b[j]);
	put_operation(stack, "pa\n");
	return (top_of_stack(stack.b, stack.count));
}
