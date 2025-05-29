/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:10:55 by wjhoe             #+#    #+#             */
/*   Updated: 2025/05/28 16:37:16 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // remove before submission
# include <limits.h> // remove before submission


/* ARGUMENT VALIDATION FUNCTIONS */
int		validate_argument(char *arg);
int		check_duplicates(int *stack, int count);

/* SOLVING FUNCTIONS */
// void	solve_stack(int *stack_a, int count);
int		*find_solution(int *stack, int count);
void	write_solution(int *stack_a, int *stack_b, int count);
void	rotate_to_min(int *stack_a, int *stack_b, int count);
void	rotate_to_destination(int *stack_a, int count);

// /* STACK SORTING ALGORITHMS */
// void	find_anchor(int *stack_a, int *stack_b, int count);
// void	rev_rotate_to_anchor_a(int *stack_a, int *stack_b, int count);
// void	rev_rotate_to_anchor_b(int *stack_a, int *stack_b, int count);
// void	rotate_to_anchor_a(int *stack_a, int *stack_b, int count);
// void	rotate_to_anchor_b(int *stack_a, int *stack_b, int count);

/* STACK SORTING FUNCTIONS */
void	swap_top(int *stack_a, int *stack_b, int count);
int		push_a_to_b(int *stack_a, int *stack_b, int count);
int		push_b_to_a(int *stack_a, int *stack_b, int count);
void	rotate_stack(int *stack_a, int *stack_b, int count);
void	reverse_rotate_stack(int *stack_a, int *stack_b, int count);

/* SORTING ALGO UTILITIES */
void	write_rotate(int *stack_a, int *stack_b, int direction);
void	reverse_move_stack(int *stack, int count);
void	move_stack(int *stack, int count);

// /* SWAP UTILITIES*/
// void	swap_a(int *stack_a, int *stack_b, int count);
// void	swap_b(int *stack_a, int *stack_b, int count);
// void	check_swap_a(int *stack_a, int *stack_b, int count);
// void	check_swap_b(int *stack_a, int *stack_b, int count);

/* FINALIZING UTILITIES*/
int		verify_stack_a(int *stack_a, int count);

/* GENERAL UTILITIES */
void	ft_swap(int *a, int *b);
int		top_of_stack(int *stack, int count);
int		find_median(int *stack_a, int count);



#endif