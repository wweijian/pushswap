/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:43:08 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 23:14:45 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_operation(t_stack stack, char *operation)
{
	t_list	*node;
	char	*string;
	
	string = ft_strdup(operation);
	node = ft_lstnew(string);
	ft_lstadd_back(stack.solution, node);
}

void	print_solution(t_stack stack)
{
	t_list	*search;
	t_list	*remove;

	search = *stack.solution;
	remove = search;
	remove_counter_spin(stack.solution);
	remove_double_spin(stack.solution);
	while (search)
	{
		ft_printf("%s", (char *)(search)->content);
		remove = search;
		search = search->next;
		ft_lstdelone(remove, free);
	}
}