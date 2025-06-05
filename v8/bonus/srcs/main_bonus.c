/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 13:25:59 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/05 23:38:57 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	int		*stack_sorted;
	t_list	**ops_list;
	t_stack	stack;

	if (ac < 2)
		return (0);
	stack = init_prog(ac, av);
	if (!stack.a)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	stack_sorted = find_solution(stack);
	translate_stack(&stack.a, stack_sorted, stack.count);
	if (stack_sorted)
		free(stack_sorted);
	ops_list = malloc(sizeof(void *));
	*ops_list = NULL;
	if (input_operations(stack, ops_list))
	{
		if (check_sorted(stack))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
		write(2, "Error\n", 6);
	free(stack.a);
	free(stack.b);
	ft_lstclear(stack.solution, free);
	free(stack.solution);
	printf("opslist:\n");
	ft_lstclear(ops_list, free);
	free(ops_list);
}

int	input_operations(t_stack stack, t_list **ops_list)
{
	t_list	*search;

	search = *ops_list;
	read_operations(ops_list);
	while (search)
	{
		if (!ft_strncmp((*ops_list)->content, "ra\n", 3)
			|| !ft_strncmp((*ops_list)->content, "rb\n", 3)
			|| !ft_strncmp((*ops_list)->content, "rr\n", 3))
			sort_rotate(stack, (*ops_list)->content);
		else if (!ft_strncmp((*ops_list)->content, "rra\n", 4)
			|| !ft_strncmp((*ops_list)->content, "rrb\n", 4)
			|| !ft_strncmp((*ops_list)->content, "rrr\n", 4))
			sort_rev_rotate(stack, (*ops_list)->content);
		else if (!ft_strncmp((*ops_list)->content, "sa\n", 3)
			|| !ft_strncmp((*ops_list)->content, "sb\n", 3)
			|| !ft_strncmp((*ops_list)->content, "ss\n", 3))
			sort_swap(stack, (*ops_list)->content);
		else if (!ft_strncmp((*ops_list)->content, "pa\n", 3)
			|| !ft_strncmp((*ops_list)->content, "pb\n", 3))
			sort_push(stack, (*ops_list)->content);
		else
			return (0);
		if (search->next)
			*search = *(search)->next;
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
