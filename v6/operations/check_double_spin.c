/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_spin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:54:17 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 23:20:36 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_double_spin(t_list **solution) 
{
	t_list	*search;
	int		flag;

	search = *solution;
	flag = 0;

	while(search->next)
	{
		if (ft_strncmp(search->next->content, "ra\n", 3) == 0)
			flag = check_ra_for_rb(&search);
		else if (ft_strncmp(search->next->content, "rb\n", 3) == 0)
			flag = check_rb_for_ra(&search);
		else if (ft_strncmp(search->next->content, "rra\n", 4) == 0)
			flag = check_rra_for_rrb(&search);
		else if (ft_strncmp(search->next->content, "rrb\n", 4) == 0)
			flag = check_rrb_for_rra(&search);
		if (flag == 1)
			return (remove_double_spin(solution));
		search = search->next;
	}
}

int	check_ra_for_rb(t_list **solution)
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
		before->next = search->next;
		ft_lstdelone(search, free);
		ft_strlcpy(after->content, "rr\n", 4);
		flag = 1;
	}
	return (flag);
}

int	check_rb_for_ra(t_list **solution)
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
		before->next = search->next;
		ft_lstdelone(search, free);
		ft_strlcpy(after->content, "rr\n", 4);
		flag = 1;
	}
	return (flag);
}

int	check_rra_for_rrb(t_list **solution)
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
		before->next = search->next;
		ft_lstdelone(search, free);
		ft_strlcpy(after->content, "rrr\n", 5);
		flag = 1;
	}
	return (flag);
}

int	check_rrb_for_rra(t_list **solution)
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
		before->next = search->next;
		ft_lstdelone(search, free);
		ft_strlcpy(after->content, "rrr\n", 5);
		flag = 1;
	}
	return (flag);
}