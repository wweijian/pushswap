/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back2_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:57:24 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/03 13:40:29 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sortback_push_b_btm(t_stack stack)
{
	rotate_stack_b(stack);
	return (1);
}

int	sortback_push_a_btm(t_stack stack)
{
	int	j;

	j = top_of_stack(stack.b, stack.count);
	push_b_to_a(stack);
	rotate_stack_a(stack);
	return (1);
}

int	sortback_push_a_top(t_stack stack)
{
	push_b_to_a(stack);
	return(1);
}