/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:10:55 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/02 11:20:26 by wjhoe            ###   ########.fr       */
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

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		count;
	t_list	*solution;
}			t_stack;

typedef struct s_push_data
{
	int	count_btm;
	int	count_top;
	int	max;
	int	min;
	int	median;
}			t_push_data;

typedef struct s_partition
{
	int	top;
	int	btm;
}			t_partition;

/* ARGUMENT VALIDATION FUNCTIONS */
int			validate_argument(char **av);
int			check_duplicates(int *stack, int count);
int			check_limits(char *arg);
int			check_digits(char *arg);
int			ft_atol(const char *nptr);

/* SOLVE_STACK.C */
void		solve_stack(t_stack stack);
void		translate_stack(int **stack, int *stack_sorted, int count);
t_stack		init_prog(int ac, char **av);

/* FIND_SOLUTION.C */
int			*find_solution(t_stack stack);
void		ft_quicksort(int *stack, int start_index, int end_index);
int			ft_partition(int *stack, int start_index, int end_index);

/* WRITE_SOLUTION.C */
void		write_solution(t_stack stack);
void		return_top_partition(t_stack stack, t_push_data push_data);
void		return_btm_partition(t_stack stack, t_push_data push_data);
int			count_top_stack(int *stack_b, int count, t_push_data push_data);
int			count_btm_stack(int *stack_b, int count, t_push_data push_data);

/* PRESORT_STACK.C */
t_push_data	presort_stack(t_stack stack);
void		start_stack_b(t_stack stack, t_partition partition);
t_push_data	push_data_init(int count_btm, int count_top, int max, int min);
t_push_data	update_push(int *stack_b, int count, t_partition partition, t_push_data push_data);

/* PRESORT_STACK_UTILS.C */
int			find_btm_partition(int *stack_a, int count);
int			find_top_partition(int *stack_a, int count);
int			presort_push_btm(t_stack stack);
int			presort_push_top(t_stack stack);

/* MAKE_BASE.C */
void		make_base(t_stack stack);
void		make_base_3(int *stack_a, int count);
void		make_base_5(t_stack stack);

/* SORT_BACK_UTILS.C */
void		sort_to_a(t_stack stack);
int			find_stack_a_min(t_stack stack);
void		rotate_a_to_position(t_stack stack);

/* SORT_AND_PUSH.C*/
void		sort_and_push(t_stack stack, int count_top);
void		sort_and_push_two(t_stack stack, int count_top);
void		sort_and_push_three(t_stack stack, int count_top);
void		sort_and_push_four(t_stack stack, int count_top);
void		sort_and_push_five(t_stack stack, int count_top);

/* SWAP_UTILS.C */
void		swap_a(t_stack stack);
void		swap_b(t_stack stack);

/* PUSH_SWAP_OPS.C */ // FIXME:
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