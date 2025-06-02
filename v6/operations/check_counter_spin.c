/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_counter_spin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:55:12 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 22:57:53 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_counter_spin(t_list **solution)
{
	t_list	*search;
	int		flag;

	search = *solution;
	flag = 0;
	while(search->next)
	{
		if (ft_strncmp(search->next->content, "ra\n", 3) == 0)
			flag = check_ra_for_rra(&search);
		else if (ft_strncmp(search->next->content, "rb\n", 3) == 0)
			flag = check_rb_for_rrb(&search);
		else if (ft_strncmp(search->next->content, "rra\n", 4) == 0)
			flag = check_rra_for_ra(&search);
		else if (ft_strncmp(search->next->content, "rrb\n", 4) == 0)
			flag = check_rrb_for_rb(&search);
		if (flag == 1)
			return (remove_counter_spin(solution));
		search = search->next;
	}
}

int	check_ra_for_rra(t_list **solution)
{
	t_list	*before;
	t_list	*search;
	t_list	*after;
	int		flag;

	if (!solution || !*solution || !(*solution)->next || !(*solution)->next->next)
		return (0);
	flag = 0;
	before = *solution;
	search = before->next;
	after = search->next;
	if (ft_strncmp(after->content,"rra\n", 4) == 0)
	{
		before->next = after->next;
		ft_lstdelone(search, free);
		ft_lstdelone(after, free);
		flag = 1;
	}
	return (flag);
}

int	check_rra_for_ra(t_list **solution)
{
	t_list	*before;
	t_list	*search;
	t_list	*after;
	int		flag;

	if (!solution || !*solution || !(*solution)->next || !(*solution)->next->next)
		return (0);
	flag = 0;
	before = *solution;
	search = before->next;
	after = search->next;
	if (ft_strncmp(after->content,"ra\n", 3) == 0)
	{
		before->next = after->next;
		ft_lstdelone(search, free);
		ft_lstdelone(after, free);
		flag = 1;
	}	
	return (flag);
}

int	check_rb_for_rrb(t_list **solution)
{
	t_list	*before;
	t_list	*search;
	t_list	*after;
	int		flag;

	if (!solution || !*solution || !(*solution)->next || !(*solution)->next->next)
		return (0);
	flag = 0;
	before = *solution;
	search = before->next;
	after = search->next;
	if (ft_strncmp(after->content,"rrb\n", 4) == 0)
	{
		before->next = after->next;
		ft_lstdelone(search, free);
		ft_lstdelone(after, free);
		flag = 1;
	}	
	return (flag);
}

int	check_rrb_for_rb(t_list **solution)
{
	t_list	*before;
	t_list	*search;
	t_list	*after;
	int		flag;

	if (!solution || !*solution || !(*solution)->next || !(*solution)->next->next)
		return (0);
	flag = 0;
	before = *solution;
	search = before->next;
	after = search->next;
	if (ft_strncmp(after->content,"rb\n", 3) == 0)
	{
		before->next = after->next;
		ft_lstdelone(search, free);
		ft_lstdelone(after, free);
		flag = 1;
	}	
	return (flag);
}
