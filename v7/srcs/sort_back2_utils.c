/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back2_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:57:24 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/04 13:06:49 by wjhoe            ###   ########.fr       */
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
	push_b_to_a(stack);
	rotate_stack_a(stack);
	return (1);
}

int	sortback_push_a_top(t_stack stack)
{
	push_b_to_a(stack);
	return(1);
}

int	rotate_to_btm_a(t_stack stack)
{
	rotate_stack_a(stack);
	return (1);
}

t_count	reset_count(int keep, t_count count)
{
	count.a_btm = 0;
	count.b_btm = 0;
	count.a_top = 0;
	count.b_top = 0;
	count.keep = keep;
	return (count);
}

/* 
	Set partition options:
	1: btm 3rd
	2: mid
	3: top 
*/

t_push_data reset_push_data (t_push_data push_data, int option)
{
	int	max;
	int	min;
	
	if (option == 1)
		push_data.max = push_data.partition.btm - 1;
	if (option == 2)
	{
		push_data.max = push_data.partition.top - 1;
		push_data.min = push_data.partition.btm;
	}
	if (option == 3)
		push_data.min = push_data.partition.top;
	max = push_data.max;
	min = push_data.min;
	push_data.partition.btm = find_btm_partition(min, max);
	push_data.partition.top = find_top_partition(min, max);
	return (push_data);
}
