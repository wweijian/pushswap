/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:10:55 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 09:31:05 by wjhoe            ###   ########.fr       */
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
int			check_limits(char *arg);
int			check_digits(char *arg);
int			ft_atol(const char *nptr);

/* SOLVE_STACK.C */
void		solve_stack(int *stack_a, int count);
void		translate_stack(int **stack, int *stack_sorted, int count);
int			*init_stacks(int ac, char **av);

/* FIND_SOLUTION.C */
int			*find_solution(int *stack, int count);
void		ft_quicksort(int *stack, int start_index, int end_index);
int			ft_partition(int *stack, int start_index, int end_index);

/* WRITE_SOLUTION.C */
void		write_solution(int *stack_a, int *stack_b, int count);
void		return_top_partition(int *stack_a, int *stack_b, int count, t_push_data push_data);
void		return_btm_partition(int *stack_a, int *stack_b, int count, t_push_data push_data);
int			count_top_stack(int *stack_b, int count, t_push_data push_data);
int			count_btm_stack(int *stack_b, int count, t_push_data push_data);

/* PRESORT_STACK.C */
void		start_stack_b(int *stack_a, int *stack_b, int count, t_partition partition);
t_push_data	push_data_init(int count_btm, int count_top, int max, int min);
t_push_data	update_push(int *stack_b, int count, t_partition partition, t_push_data push_data);
t_push_data	presort_stack(int *stack_a, int *stack_b, int count);


/* PRESORT_STACK_UTILS.C */
int			find_btm_partition(int *stack_a, int count);
int			find_top_partition(int *stack_a, int count);
int			presort_push_btm(int *stack_a, int *stack_b, int count);
int			presort_push_top(int *stack_a, int *stack_b, int count);

/* MAKE_BASE.C */
void		make_base(int *stack_a, int *stack_b, int count);
void		make_base_3(int *stack_a, int count);
void		make_base_5(int *stack_a, int *stack_b, int count);

/* SORT_TO_A.C */
void		sort_to_a(int *stack_a, int *stack_b, int count);
int			find_stack_a_min(int *stack_a, int *stack_b, int count);
void		rotate_a_to_position(int *stack_a, int *stack_b, int count);

/* SORT_AND_PUSH.C*/
void		sort_and_push(int *stack_a, int *stack_b, int count, int count_top);
void		sort_and_push_two(int *stack_a, int *stack_b, int count, int count_top);
void		sort_and_push_three(int *stack_a, int *stack_b, int count, int count_top);
void		sort_and_push_four(int *stack_a, int *stack_b, int count, int count_top);
void		sort_and_push_five(int *stack_a, int *stack_b, int count, int count_top);

/* SWAP_UTILS.C */
void		swap_a(int *stack_a, int *stack_b, int count);
void		swap_b(int *stack_a, int *stack_b, int count);

/* PUSH_SWAP_OPS.C */
void		swap_top(int *stack_a, int *stack_b, int count);
int			push_a_to_b(int *stack_a, int *stack_b, int count);
int			push_b_to_a(int *stack_a, int *stack_b, int count);
void		rotate_stack(int *stack_a, int *stack_b, int count);
void		reverse_rotate_stack(int *stack_a, int *stack_b, int count);

/* PUSH_SWAP_UTILS.C */
void		reverse_move_stack(int *stack, int count);
void		move_stack(int *stack, int count);

/* UTILS.C */
int			top_of_stack(int *stack, int count);
void		ft_swap(int *a, int *b);
int			find_median(int *stack_a, int count);
void		rotate_to_destination(int *stack_a, int count);
int			find_max(int *stack_b, int count, int count_top);

#endif