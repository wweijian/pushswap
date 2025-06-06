/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:10:55 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/06 15:31:22 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // remove before submission
# include <limits.h>

/*
	count_a_btm:	counst the number of in the biggest third (bottom of a)
	count_b_btm:	counts numbers in the bottom third
					or numbers presorted to the BTM of stackb
	count_a_top:	counts numbers in the biggest third
					temporarily placed on the top of A for stack management
	count_b_top:	counts numbers in the middle third
					or numbers presorted to the TOP of stackb
*/

typedef struct s_args
{
	int		count;
	char	**vec;
}			t_args;

typedef struct s_stack
{
	int		*a;
	int		*b;
	int		count;
	t_list	**solution;
}			t_stack;

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
	int			top_third;
	int			mid_third;
	t_count		count;
}			t_push_data;

/* MAKE_ARG_V.C */
t_args		make_argv(int ac, char **av);
void		free_argv(char **av);
char		*make_single_string(int ac, char **av, int arg_len);

/* ARGUMENT VALIDATION FUNCTIONS */
int			validate_argument(char **av);
int			check_duplicates(int *stack, int count);
int			check_limits(char *arg);
int			check_digits(char *arg);
long		ft_atol(const char *nptr);

/* INIT_STACK.C */
t_stack		init_prog(int ac, char **av);
void		translate_stack(int **stack, int *stack_sorted, int count);
t_stack		empty_stack(void);
t_stack		init_stack(int ac, char **av);
int			check_sorted(t_stack stack);

/* FIND_SOLUTION.C */
int			*find_solution(t_stack stack);
void		ft_quicksort(int *stack, int start_index, int end_index);
int			ft_partition(int *stack, int start_index, int end_index);

/* SOLVE_STACK.C */
void		solve_stack(t_stack stack);

/* PRESORT_STACK.C */
t_push_data	presort_stack(t_stack stack);
void		start_stack_b(t_stack stack, t_push_data push_data);
t_push_data	push_data_init(t_stack stack);
t_push_data	update_push(int *stack_b, int count, t_push_data push_data);

/* PRESORT_STACK_UTILS.C */
int			find_btm_partition(int min, int max);
int			find_top_partition(int min, int max);

/* MAKE_BASE.C */
void		make_base(t_stack stack);
void		make_base_3(t_stack stack);
void		make_base_5(t_stack stack);

/* SORT_STACK_B.C */
void		sort_b_top(t_stack stack, t_push_data push_data, int min, int max);
void		sort_b_btm(t_stack stack, t_push_data push_data, int min, int max);
int			rotate_to_b_btm(t_stack stack);
int			push_to_a_top(t_stack stack);
int			rotate_to_a_btm(t_stack stack);

/* SORT_STACK_A.C */
void		sort_a_top(t_stack stack, t_push_data push_data, int min, int max);
void		sort_a_btm(t_stack stack, t_push_data push_data, int min, int max);
int			push_to_b_btm(t_stack stack);
int			push_to_b_top(t_stack stack);
int			push_to_a_btm(t_stack stack);

/* FINISH_SORT_A.C */
void		finish_sort_a(t_stack stack, int count);
void		finish_sort_a_two(t_stack stack, int top);
void		finish_sort_a_three(t_stack stack, int top);
void		finish_sort_a_four(t_stack stack, int top);
void		finish_sort_a_five(t_stack stack, int top);

/* SORT_STACK_UTILS.C */
t_count		reset_count(int keep, t_count count);
t_push_data	reset_push_data(t_push_data push_data, int min, int max);

/* FINISH_SORT_B.C */
void		finish_sort_b(t_stack stack, int count_top);
void		finish_sort_b_two(t_stack stack, int count_top);
void		finish_sort_b_three(t_stack stack, int count_top);
void		finish_sort_b_four(t_stack stack, int count_top);
void		finish_sort_b_five(t_stack stack, int count_top);

/* FINISH_SORT_UTILS.C */
int			sort_min_to_b(t_stack stack, int top, int min_value);

/* UTILS.C */
int			top_of_stack(int *stack, int count);
void		ft_swap(int *a, int *b);
int			find_max(int *stack_b, int count, int count_top);
int			find_min(int *stack, int stack_count, int nmemb);
void		multiple_op(void (*f)(t_stack), t_stack stack, int n);

/* PUSH SWAP OPERATIONS*/

/* PUSH_SWAP_ALGO */
int			push_a_to_b(t_stack stack);
int			push_b_to_a(t_stack stack);
void		reverse_rotate_stack_a(t_stack stack);
void		reverse_rotate_stack_b(t_stack stack);
void		reverse_rotate_stack_both(t_stack stack);
void		reverse_rotate_stack(int *stack, int count);
void		rotate_stack_a(t_stack stack);
void		rotate_stack_b(t_stack stack);
void		rotate_stack_both(t_stack stack);
void		rotate_stack(int *stack, int count);
void		swap_top_a(t_stack stack);
void		swap_top_b(t_stack stack);
void		swap_top_both(t_stack stack);

/* PUSH_SWAP_UTILS.C */
void		reverse_move_stack(int *stack, int count);
void		move_stack(int *stack, int count);

/* POST SORTING*/

/* CHECK_COUNTER_SPIN,C */
void		remove_counter_spin(t_list **solution);
int			check_ra_for_rra(t_list **solution);
int			check_rra_for_ra(t_list **solution);
int			check_rb_for_rrb(t_list **solution);
int			check_rrb_for_rb(t_list **solution);

/* CHECK_DOUBLE_SPIN.C */
void		remove_double_spin(t_list **solution);
int			check_ra_for_rb(t_list **solution);
int			check_rb_for_ra(t_list **solution);
int			check_rra_for_rrb(t_list **solution);
int			check_rrb_for_rra(t_list **solution);

/* CHECK_DOUBLE_COUNTER_SPIN.C */
int			check_rr_for_rrr(t_list **solution);
int			check_rrr_for_rr(t_list **solution);

/* CHECK_DOUBLE_SWAP.C */
void		remove_double_swap(t_list **solution);
int			check_sa_for_sa(t_list **solution);
int			check_sb_for_sb(t_list **solution);
int			check_sa_for_sb(t_list **solution);
int			check_sb_for_sa(t_list **solution);

/* PRINT_LIST.C */
void		put_operation(t_stack stack, char *operation);
void		print_solution(t_stack stack);

#endif