/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wjhoe <wjhoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:54:58 by wjhoe             #+#    #+#             */
/*   Updated: 2025/06/06 16:04:19 by wjhoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "gnl_bonus.h"

/* UTILS.C */
int		input_operations(t_stack stack, t_list **ops_list);
void	read_operations(t_list **ops_list);
void	free_all(t_stack stack, t_list **ops_list, int *stack_sorted,
			char **av);
void	write_result(t_stack stack, int flag);
int		check_status(char **av);

/* SORT.C */
void	sort_operations(t_stack stack, char *operation);
void	sort_rotate(t_stack stack, char *operation);
void	sort_rev_rotate(t_stack stack, char *operation);
void	sort_swap(t_stack stack, char *operation);
void	sort_push(t_stack stack, char *operation);

#endif