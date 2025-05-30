/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_option.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:56:15 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/31 00:07:02 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_option(int ra_score, int rb_score, int rrb_score)
{
	if (ra_score > rb_score && ra_score > rrb_score)
		return (1);
	if (rb_score > ra_score && rb_score > rrb_score)
		return (2);
	if (rrb_score > ra_score && rrb_score > rb_score)
		return (3);
	if (ra_score > rb_score && ra_score == rrb_score)
		return (4);
	if (rb_score > rrb_score && rb_score == ra_score)
		return (5);
	if (rrb_score > ra_score && rrb_score == rb_score)
		return (6);
	if (ra_score == rb_score && ra_score == rrb_score)
		return (7);
	return (0);
}

int	rev_option(int ra_score, int rb_score, int rrb_score, int option)
{
	if (option < 4)
		return (option);
	if (option == 4)
		rb_score = INT_MAX;
	if (option == 5)
		rrb_score = INT_MAX;
	if (option == 6)
		ra_score = INT_MAX;
	if (ra_score <= rb_score && ra_score <= rrb_score)
		return (1);
	else if (rb_score <= ra_score && rb_score <= rrb_score)
		return (2);
	else if (rrb_score <= ra_score && rrb_score <= rb_score)
		return (3);
	return (0);
}