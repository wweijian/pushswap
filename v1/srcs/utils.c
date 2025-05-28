/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 08:46:30 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/27 12:29:41 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	top_of_stack(int *stack, int count)
{
	int	i;

	i = 0;
	while (i < count && !stack[i])
		i++;

	return (i);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	find_median(int count)
{
	if (count % 2)
		return (count / 2 + 1);
	else
		return (count / 2);
}