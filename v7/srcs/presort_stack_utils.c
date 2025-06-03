/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:28:22 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/03 14:48:10 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_btm_partition(int min, int max)
{
	return ((max - min) / 3 + min);
}

int	find_top_partition(int min, int max)
{
	return (max - ((max - min) / 3) + 1);
}

int	presort_push_btm(t_stack stack)
{
	push_a_to_b(stack);
	rotate_stack_b(stack);
	return (1);
}

int	presort_push_top(t_stack stack)
{
	push_a_to_b(stack);
	return (1);
}
