/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:28:22 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/04 09:01:52 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
	min = 1
	btm part (100 - 1) / 3 + 1 = 34 (1 - 33)
	top part 100 - (100 - 1 / 3) + 1 = 68 (34 - 67)
	max = 100 (68 - 100)
	
	min = 68
	max = 100 (92 - 100)
	top part 100 - (100 - 68 / 3) + 1 = 91 (79 - 91)
	btm part (100 - 68) / 3 + 68 = 78 (67 - 78)

	min = 92
	max = 100
	top part 100 - (100 - 92 / 3) + 1 = 99
	btm part (100 - 92) / 3 + min = 94 (92 - 93)

	1 2 3 4 5 6 7 8 9 10
	^min			  ^max
	(max - min + 1) > range
	range / 3 > 33%
	min + 33% (1 + 3) = 4
	max + 33% (10 - 3) = 7
	rest
	(1 - 3)(4 - 7)(8 - 10) 4-3-3
	(1 - 3)(4 - 7)(8 - 11) 4-4-3 
	(1 - 4)(5 - 8)(9 - 12) 4-4-4
	btm = min + 33%
	top = min + 33% + 1 

	(1 - 3)(4 - 7)(8 - 10) 4-3-3
	(1 - 3)(4 - 8)(9 - 11) 4-4-3 
	(1 - 4)(5 - 8)(9 - 12) 4-4-4
	btm = min + 33%
	top = max - 33% + 1
*/

int	find_btm_partition(int min, int max)
{
	int	third;
	
	third = (max - min + 1) / 3;
	return (min + third);
}

int	find_top_partition(int min, int max)
{
	int	third;
	
	third = (max - min + 1) / 3;
	return (max - third);
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