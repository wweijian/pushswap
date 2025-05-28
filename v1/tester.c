/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:29:23 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/27 22:53:17 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	anchor_ra_rb(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	j;

	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	while (stack_a[count - 1] != count && stack_b[count - 1] != 1)
	{
		if (stack_a[i] != count && stack_b[j] != 1)
		{
			check_swap_a(stack_a, stack_b, count);
			check_swap_b(stack_a, stack_b, count);
			reverse_rotate_stack(stack_a, stack_b, count);
		}
		reverse_rotate_stack(stack_a, stack_b, count);
	}
	rotate_to_anchor_a(stack_a, stack_b, count);
	rotate_to_anchor_b(stack_a, stack_b, count);
}

int main ()
{
	int stack_a[11] = {0, 0, 0, 0, 0, 0, 10, 8, 11, 7, 9};
	int stack_b[11] = {0, 0, 0, 0, 0, 6, 1, 3, 2, 4, 5};
	int count = 11;	

	for (int i = 0; i < count; i++)
		printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
	anchor_ra_rb(stack_a, stack_b, count);
	for (int i = 0; i < count; i++)
		printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
}

/* 
for (int i = 0; i < count; i++)
printf("index %d:\t%d\t\t%d\n", i, stack_a[i], stack_b[i]);
 */