/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:42:56 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 23:36:20 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_top_a(t_stack stack)
{
	int	i;

	i = top_of_stack(stack.a, stack.count);
	if (i > stack.count - 2)
		return ;
	ft_swap(&stack.a[i], &stack.a[i + 1]);
	put_operation(stack, "sa\n");
}

void	swap_top_b(t_stack stack)
{
	int	j;

	j = top_of_stack(stack.b, stack.count);
	if (j > stack.count - 2)
		return ;
	ft_swap(&stack.b[j], &stack.b[j + 1]);
	put_operation(stack, "sb\n");
}

void	swap_top_both(t_stack stack)
{
	int	i;
	int	j;

	i = top_of_stack(stack.a, stack.count);
	if (i > stack.count - 2)
		return ;
	j = top_of_stack(stack.b, stack.count);
	if (j > stack.count - 2)
		return ;
	ft_swap(&stack.a[i], &stack.a[i + 1]);
	ft_swap(&stack.b[j], &stack.b[j + 1]);
	put_operation(stack, "ss\n");
}
