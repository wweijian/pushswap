/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:25:59 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 20:18:57 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int main (int ac, char **av)
{
	t_stack	stack;
	t_list	**ops_list;

	if (ac < 2)
		return (0);
	stack = init_prog(ac, av);
	ops_list = malloc(sizeof(void *));
	input_operations(stack, ops_list);
	validate_result(stack);
	free(stack.a);
	free(stack.b);
}

void	input_operations(t_stack stack, t_list **ops_list)
{
	read_operations(ops_list);
	while(*ops_list)
	{
		if (!ft_strncmp((*ops_list)->content, "ra\n", 3)
				|| !ft_strncmp((*ops_list)->content, "rb\n", 3)
				|| !ft_strncmp((*ops_list)->content, "rr\n",3))
			sort_rotate(stack, (*ops_list)->content);
		else if (!ft_strncmp((*ops_list)->content, "rra\n", 4)
				|| !ft_strncmp((*ops_list)->content, "rrb\n", 4)
				|| !ft_strncmp((*ops_list)->content, "rrr\n", 4))
			sort_rev_rotate(stack, (*ops_list)->content);
		else if (!ft_strncmp((*ops_list)->content, "sa\n", 3)
				|| !ft_strncmp((*ops_list)->content, "sb\n", 3)
				|| !ft_strncmp((*ops_list)->content, "ss\n",3))
			sort_swap(stack, (*ops_list)->content);
		else if (!ft_strncmp((*ops_list)->content, "pa\n", 3)
				|| !ft_strncmp((*ops_list)->content, "pb\n", 3)) 
			sort_push(stack, (*ops_list)->content);
		*ops_list = (*ops_list)->next;
	}
}

void	read_operations(t_list **ops_list)
{
	char	*operation;
	
	operation = get_next_line(0);
	while (operation)
	{
		ft_lstadd_back(ops_list, ft_lstnew(ft_strdup(operation)));
		free(operation);
		operation = get_next_line(0);
	}
}

void	validate_result(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.count)
	{
		if (stack.a[i] != i + 1)
			{
				write(1, "KO!\n", 4);
				return ;
			}
		i++;
	}
	write(1, "OK!\n", 4);
	return ;
}