/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_back2_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:57:24 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 18:56:26 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_count	reset_count(int keep, t_count count)
{
	count.a_btm = 0;
	count.b_btm = 0;
	count.a_top = 0;
	count.b_top = 0;
	count.keep = keep;

	return (count);
}

t_push_data reset_push_data (t_push_data push_data, int min, int max)
{
	push_data.mid_third = find_btm_partition(min, max);
	push_data.top_third = find_top_partition(min, max);
	return (push_data);
}
