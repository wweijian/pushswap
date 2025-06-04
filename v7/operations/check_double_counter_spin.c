/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_counter_spin.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 23:30:39 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/04 23:34:02 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rr_for_rrr(t_list **solution)
{
	t_list	*before;
	t_list	*target;
	t_list	*after;
	int		flag;

	if (!solution || !*solution || !(*solution)->next || !(*solution)->next->next)
		return (0);
	flag = 0;
	before = *solution;
	target = before->next;
	after = target->next;
	if (ft_strncmp(after->content,"rrr\n", 4) == 0)
	{
		before->next = after->next;
		ft_lstdelone(target, free);
		ft_lstdelone(after, free);
		flag = 1;
	}
	return (flag);
}

int	check_rrr_for_rr(t_list **solution)
{
	t_list	*before;
	t_list	*target;
	t_list	*after;
	int		flag;

	if (!solution || !*solution || !(*solution)->next || !(*solution)->next->next)
		return (0);
	flag = 0;
	before = *solution;
	target = before->next;
	after = target->next;
	if (ft_strncmp(after->content,"rr\n", 4) == 0)
	{
		before->next = after->next;
		ft_lstdelone(target, free);
		ft_lstdelone(after, free);
		flag = 1;
	}
	return (flag);
}
