/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presort_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 21:28:22 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/04 22:35:09 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_btm_partition(int min, int max)
{
	int	range;
	int	third;
	
	range = max - min + 1;
	third = (range) / 3 + (range % 3) / 2;
	return (min + third);
}

int	find_top_partition(int min, int max)
{
	int	range;
	int	third;
	
	range = max - min + 1;
	third = (range) / 3 + (range % 3) / 2;
	return (min + third + third);
}