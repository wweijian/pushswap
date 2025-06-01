/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:10:55 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/01 23:24:01 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // remove before submission
# include <limits.h> // remove before submission

/*
	count_btm:	counts numbers in the bottom third
					or numbers presorted to the BTM of stackb
	count_top:	counts numbers in the middle third
					or numbers presorted to the TOP of stackb
	max 		stores the biggest VALUE (not index) inclusive in the sort
	min			stores the lowst VALUE (not index) inclusive in the sort
*/

/* 
typedef struct s_stack
{
	int		count;
	int		*a;
	int 	*b;
	t_list *solution
} 				t_stack;
 */

typedef struct s_push_data
{
	int	count_btm;
	int	count_top;
	int	max;
	int	min;
	int	median;
}				t_push_data;

typedef struct s_partition
{
	int			top;
	int			btm;
}				t_partition;

/* ARGUMENT VALIDATION FUNCTIONS */
int			validate_argument(char *arg);
int			check_duplicates(int *stack, int count);

/* SOLVING FUNCTIONS */
// void	solve_stack(int *stack_a, int count);
int			*find_solution(int *stack, int count);
void		write_solution(int *stack_a, int *stack_b, int count);
void		rotate_to_min(int *stack_a, int *stack_b, int count);
void		rotate_to_destination(int *stack_a, int count);
void		rotate_a_to_position(int *stack_a, int *stack_b, int count);
void		stack_dump(int *stack_a, int *stack_b, int count);
int			find_stack_a_min(int *stack_a, int *stack_b, int count);
void		rotate_to_next_op(int *stack_a, int *stack_b, int count);
int			stack_dump_count(int *stack_a, int i, int *stack_b, int j);
int			count_rrb_dump(int *stack_b, int count, int rrb);
int			count_rb(int *stack_a, int *stack_b, int count);
int			count_ra_rotation(int *stack_a, int *stack_b, int count);
int			count_rb_rotation(int *stack_a, int *stack_b, int count);
int			count_rrb_rotation(int *stack_a, int *stack_b, int count);
int			count_ra_stack_dump(int *stack_a, int *stack_b, int count);
int			count_rb_stack_dump(int *stack_a, int *stack_b, int count);
int			count_rrb_stack_dump(int *stack_a, int *stack_b, int count);
int			choose_option(int ra_score, int rb_score, int rrb_score);
int			rev_option(int ra_score, int rb_score, int rrb_score, int option);
t_push_data	split_thirds(int *stack_a, int *stack_b, int count);
int			presort_push_btm(int *stack_a, int *stack_b, int count);
int			presort_push_top(int *stack_a, int *stack_b, int count);
void		swap_b(int *stack_a, int *stack_b, int count);
void		make_base(int *stack_a, int *stack_b, int count);
void		swap_a(int *stack_a, int *stack_b, int count);
void		return_top_partition(int *stack_a, int *stack_b, int count, t_push_data push_data);
void		return_btm_partition(int *stack_a, int *stack_b, int count, t_push_data push_data);
int			find_top_partition(int *stack_a, int count);
int			find_btm_partition(int *stack_a, int count);
void		sort_to_a(int *stack_a, int *stack_b, int count);
void		sort_and_push_two(int *stack_a, int *stack_b, int count, int count_top);


/* STACK SORTING FUNCTIONS */
void		swap_top(int *stack_a, int *stack_b, int count);
int			push_a_to_b(int *stack_a, int *stack_b, int count);
int			push_b_to_a(int *stack_a, int *stack_b, int count);
void		rotate_stack(int *stack_a, int *stack_b, int count);
void		reverse_rotate_stack(int *stack_a, int *stack_b, int count);

/* SORTING ALGO UTILITIES */
void		write_rotate(int *stack_a, int *stack_b, int direction);
void		reverse_move_stack(int *stack, int count);
void		move_stack(int *stack, int count);

// /* SWAP UTILITIES*/
// void	swap_a(int *stack_a, int *stack_b, int count);
// void	swap_b(int *stack_a, int *stack_b, int count);
// void	check_swap_a(int *stack_a, int *stack_b, int count);
// void	check_swap_b(int *stack_a, int *stack_b, int count);

/* FINALIZING UTILITIES*/
int			verify_stack_a(int *stack_a, int count);

/* GENERAL UTILITIES */
void		ft_swap(int *a, int *b);
int			top_of_stack(int *stack, int count);
int			find_median(int *stack_a, int count);

#endif