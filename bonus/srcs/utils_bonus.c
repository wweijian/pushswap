/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:20:42 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/06 16:04:47 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	input_operations(t_stack stack, t_list **ops_list)
{
	t_list	*search;

	read_operations(ops_list);
	search = *ops_list;
	while (search)
	{
		if (!ft_strncmp(search->content, "ra\n", 3)
			|| !ft_strncmp(search->content, "rb\n", 3)
			|| !ft_strncmp(search->content, "rr\n", 3)
			|| !ft_strncmp(search->content, "rra\n", 4)
			|| !ft_strncmp(search->content, "rrb\n", 4)
			|| !ft_strncmp(search->content, "rrr\n", 4)
			|| !ft_strncmp(search->content, "sa\n", 3)
			|| !ft_strncmp(search->content, "sb\n", 3)
			|| !ft_strncmp(search->content, "ss\n", 3)
			|| !ft_strncmp(search->content, "pa\n", 3)
			|| !ft_strncmp(search->content, "pb\n", 3))
			sort_operations(stack, search->content);
		else
			return (0);
		search = search->next;
	}
	return (1);
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

void	free_all(t_stack stack, t_list **ops_list, int *stack_sorted, char **av)
{
	free_argv(av);
	free(stack.a);
	free(stack.b);
	ft_lstclear(stack.solution, free);
	free(stack.solution);
	if (ops_list)
	{
		ft_lstclear(ops_list, free);
		free(ops_list);
	}
	if (stack_sorted)
		free(stack_sorted);
}

void	write_result(t_stack stack, int flag)
{
	if (flag == 1)
	{
		if (check_sorted(stack))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(2, "Error\n", 6);
}

int	check_status(char **av)
{
	if (!av)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
