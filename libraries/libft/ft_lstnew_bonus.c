/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:28:20 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/06 09:11:41 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/* #include <stdio.h>
int main(void)
{
	int		a = 42;

	t_list	*list;
	list = ft_lstnew(&a);
	printf("Value of new->data: %d\n", *(int *)list->content);
	printf("Value of new->next: %p\n", (void *)list->next);

	free(list);
} */