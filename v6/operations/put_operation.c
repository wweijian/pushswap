/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_operation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:43:08 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 13:01:06 by wjhoe            ###   ########.fr       */
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
	t_list *search;

	search = *stack.solution;
	remove_counter_spin(stack.solution);
	while (search)
	{
		printf("%s", (char *)(search)->content);
		search = search->next;
	}
}