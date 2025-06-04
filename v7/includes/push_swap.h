/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:10:55 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/04 10:15:52 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // remove before submission
# include <limits.h> // remove before submission

/*
	count_a_btm:	counst the number of in the biggest third (bottom of a)
	count_b_btm:	counts numbers in the bottom third
					or numbers presorted to the BTM of stackb
	count_a_top:	counts numbers in the biggest third
					temporarily placed on the top of A for stack management
	count_b_top:	counts numbers in the middle third
					or numbers presorted to the TOP of stackb
	max 			stores the biggest VALUE (not index) inclusive in the sort
					that is being output in the sort
	min				stores the lowst VALUE (not index) inclusive in the sort

	// partition
	e.g. 100 >> 0 - 33, 34 - 67, 68 - 100
	int	top: 68
	int	btm: 34

*/

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		count;
	t_list	**solution;
}			t_stack;

typedef struct s_partition
{
	int	top;
	int	btm;
}			t_partition;

typedef struct s_count
{
	int	a_btm;
	int	b_btm;
	int	a_top;
	int	b_top;
	int	keep;
}			t_count;

typedef struct s_push_data
{
	int			max;
	int			min;
	int			median; // FIXME: DELETE
	t_partition	partition;
	t_count		count;
}			t_push_data;

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
t_stack 	empty_stack(void);
t_stack 	init_stack(int ac, char **av);

/* FIND_SOLUTION.C */
int			*find_solution(t_stack stack);
void		ft_quicksort(int *stack, int start_index, int end_index);
int			ft_partition(int *stack, int start_index, int end_index);

/* WRITE_SOLUTION.C */
void		recursive_solve(t_stack stack);
void		return_top_partition(t_stack stack, t_push_data push_data);
void		return_btm_partition(t_stack stack, t_push_data push_data);
int			count_top_stack(int *stack_b, int count, t_push_data push_data);
int			count_btm_stack(int *stack_b, int count, t_push_data push_data);

/* PRESORT_STACK.C */
t_push_data	presort_stack(t_stack stack);
void		start_stack_b(t_stack stack, t_push_data push_data);
t_push_data	push_data_init(t_stack stack);
t_push_data	update_push(int *stack_b, int count, t_push_data push_data);

/* PRESORT_STACK_UTILS.C */
int			find_btm_partition(int min, int max);
int			find_top_partition(int min, int max);
int			presort_push_btm(t_stack stack);
int			presort_push_top(t_stack stack);

/* MAKE_BASE.C */
void		make_base(t_stack stack);
void		make_base_3(t_stack stack);
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

/* PUSH_SWAP_UTILS.C */
void		reverse_move_stack(int *stack, int count);
void		move_stack(int *stack, int count);

/* UTILS.C */
int			top_of_stack(int *stack, int count);
void		ft_swap(int *a, int *b);
int			find_median(int *stack_a, int count);
void		rotate_to_destination(t_stack stack);
int			find_max(int *stack_b, int count, int count_top);

/* OPERATIONS*/

/* PUSH_SWAP_ALGO */
int		push_a_to_b(t_stack stack);
int		push_b_to_a(t_stack stack);
void	reverse_rotate_stack_a(t_stack stack);
void	reverse_rotate_stack_b(t_stack stack);
void	reverse_rotate_stack_both(t_stack stack);
void	reverse_rotate_stack(int *stack, int count);
void	rotate_stack_a(t_stack stack);
void	rotate_stack_b(t_stack stack);
void	rotate_stack_both(t_stack stack);
void	rotate_stack(int *stack, int count);
void	swap_top_a(t_stack stack);
void	swap_top_b(t_stack stack);
void	swap_top_both(t_stack stack);

/* POST_PRO.C */
void		remove_counter_spin(t_list **solution);
int			check_ra_for_rra(t_list **solution);
int			check_rra_for_ra(t_list **solution);
int			check_rb_for_rrb(t_list **solution);
int			check_rrb_for_rb(t_list **solution);
void		remove_double_spin(t_list **solution);
int			check_ra_for_rb(t_list **solution);
int			check_rb_for_ra(t_list **solution);
int			check_rra_for_rrb(t_list **solution);
int			check_rrb_for_rra(t_list **solution);


/* PRINT_LIST.C */
void 		put_operation(t_stack stack, char *operation);
void		print_solution(t_stack stack);

/* TODO: NEW FUNCTIONS */


// presort_stack_utils.c
t_partition set_partition(int min, int max);

// sort_a_top
void	finish_a_top(t_stack stack, int count);
void 	finish_a_top_two(t_stack stack, int top);
void 	finish_a_top_three(t_stack stack, int top);
void 	finish_a_top_four(t_stack stack, int top);
void 	finish_a_top_five(t_stack stack, int top);
void	multiple_op(void (*f)(t_stack), t_stack stack, int n);

void	sort_b_top(t_stack stack, t_push_data push_data);
void	sort_a_top(t_stack stack, t_push_data push_data);
void	sort_b_btm(t_stack stack, t_push_data push_data);
void	sort_a_btm(t_stack stack, t_push_data push_data);

int	sortback_push_b_btm(t_stack stack);
int	sortback_push_a_btm(t_stack stack);
int	sortback_push_a_top(t_stack stack);
int	rotate_to_btm_a(t_stack stack);
t_count	reset_count(int keep, t_count count);
t_push_data reset_push_data (t_push_data push_data, int option);


#endif