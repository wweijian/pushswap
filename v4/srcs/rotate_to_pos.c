/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_to_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:19:16 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/31 00:40:17 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_stack_a_min(int *stack_a, int *stack_b, int count)
{
	int	j;
	int	i;
	int	min_index;

	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	min_index = 0;
	while (min_index == 0 && i < count)
	{
		if (stack_a[i] > stack_b[j])
			min_index = i;
		i++;
	}
	while (i < count)
	{
		if (stack_b[j] < stack_a[i] && stack_a[i] < stack_a[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

void	rotate_a_to_position(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	min_index;
	int	rotate_counter;

	i = top_of_stack(stack_a, count);
	min_index = find_stack_a_min(stack_a, stack_b, count);
	if (count - min_index < ((count - i) / 2))
	{
		rotate_counter = count - min_index;
		while (rotate_counter > 0)
		{
			reverse_rotate_stack(stack_a, NULL, count);
			rotate_counter--;
		}
	}
	else
	{
		rotate_counter = min_index - i;
		while (rotate_counter > 0)
		{
			rotate_stack(stack_a, NULL, count);
			rotate_counter--;
		}
	}
}

void	rotate_b_to_position(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	j;
	int	base_num;
	int	rotation;

	i = top_of_stack(stack_a, count);
	j = top_of_stack(stack_b, count);
	rotation = 1;
	base_num = stack_a[count - 1];
	if (stack_a[count - 1] == count)
		base_num = 0;
	rotate_stack(NULL, stack_b, count);
	while (stack_b[j + rotation] > stack_a[i]
			&& stack_b[j + rotation] > base_num
			&& j + rotation < count)
		rotate_stack(NULL, stack_b, count);
}

void	rev_rotate_b_to_position(int *stack_a, int *stack_b, int count)
{
	int	i;
	int	rotation;
	int	base_num;
	
	rotation = 1;
	i = top_of_stack(stack_a, count);
	base_num = stack_a[count - 1];
	reverse_rotate_stack(NULL, stack_b, count);
	while (stack_b[count - rotation] > stack_a[i] 
		&& stack_b[count - rotation] < base_num
		&& rotation <= count)
	reverse_rotate_stack(NULL, stack_b, count);
}

/* 
	FIXME:	main operation is here 
	
	TODO:TODO:TODO:	fixed the stack dump count, so i need to fix the rotation counter
*/

void	rotate_to_next_op(int *stack_a, int *stack_b, int count)
{
	int	ra_rotation;
	int	rb_rotation;
	int	rrb_rotation;
	int	ra_dump;
	int	rb_dump;
	int	rrb_dump;
	int	option;
	
	ra_rotation = count_ra_rotation(stack_a, stack_b, count);
	rb_rotation = count_rb_rotation(stack_a, stack_b, count);
	rrb_rotation = count_rrb_rotation(stack_a, stack_b, count);
	ra_dump = count_ra_stack_dump(stack_a, stack_b, count);
	rb_dump = count_rb_stack_dump(stack_a, stack_b, count);
	rrb_dump = count_rrb_stack_dump(stack_a, stack_b, count);
	option = choose_option(ra_dump / ra_rotation, rb_dump / rb_rotation, rrb_dump / rrb_rotation);
	printf("ra_dump / ra_rotation %d, rb_dump / rb_rotation %d, rrb_dump / rrb_rotation %d\n", ra_dump / ra_rotation, rb_dump / rb_rotation, rrb_dump / rrb_rotation);
	printf("opriton: %d rb_dump / rb_rotation %d / %d, rrb_dump / rrb_rotation %d / %d\n",option, rb_dump , rb_rotation, rrb_dump , rrb_rotation);
	option = rev_option(ra_rotation / ra_dump, rb_rotation / rb_dump, rrb_rotation / rrb_dump, option);
	if (option == 1)
		rotate_a_to_position(stack_a, stack_b, count);
	else if (option == 2)
		rotate_b_to_position(stack_a, stack_b, count);
	else if (option == 3)
		rev_rotate_b_to_position(stack_a, stack_b, count);
	else if (option == 0)
		rotate_stack(stack_a, stack_b, count);
}

// printf(">> hi << \n");
