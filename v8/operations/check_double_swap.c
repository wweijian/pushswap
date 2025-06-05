/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 23:38:34 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/04 23:49:30 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_double_swap(t_list **solution)
{
	t_list	*search;
	int		flag;

	search = *solution;
	flag = 0;
	while(search->next)
	{
		if (ft_strncmp(search->next->content, "sa\n", 3) == 0)
			flag = check_sa_for_sa(&search);
		if (ft_strncmp(search->next->content, "sb\n", 3) == 0)
			flag = check_sb_for_sb(&search);
		if (ft_strncmp(search->next->content, "sa\n", 3) == 0 && flag == 0)
			flag = check_sa_for_sb(&search);
		if (ft_strncmp(search->next->content, "sb\n", 3) == 0 && flag == 0)
			flag = check_sb_for_sa(&search);
		if (flag == 1)
			return (remove_counter_spin(solution));
		search = search->next;
	}
}

int	check_sa_for_sa(t_list **solution)
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
	if (ft_strncmp(after->content,"sa\n", 3) == 0)
	{
		before->next = after->next;
		ft_lstdelone(target, free);
		ft_lstdelone(after, free);
		flag = 1;
	}
	return (flag);
}

int	check_sb_for_sb(t_list **solution)
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
	if (ft_strncmp(after->content,"sb\n", 3) == 0)
	{
		before->next = after->next;
		ft_lstdelone(target, free);
		ft_lstdelone(after, free);
		flag = 1;
	}
	return (flag);
}

int	check_sa_for_sb(t_list **solution)
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
	while (ft_strncmp(after->content,"ss\n", 3) == 0)
		after = after->next;
	if (ft_strncmp(after->content,"sb\n", 3) == 0)
	{
		before->next = target->next;
		ft_lstdelone(target, free);
		ft_strlcpy(after->content, "ss\n", 4); 
		flag = 1;
	}
	return (flag);
}

int	check_sb_for_sa(t_list **solution)
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
	while (ft_strncmp(after->content,"ss\n", 3) == 0)
		after = after->next;
	if (ft_strncmp(after->content,"sa\n", 3) == 0)
	{
		before->next = target->next;
		ft_lstdelone(target, free);
		ft_strlcpy(after->content, "ss\n", 4); 
		flag = 1;
	}
	return (flag);
}