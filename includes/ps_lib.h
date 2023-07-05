/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:36:46 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/12 11:56:53 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_LIB_H
# define PS_LIB_H

# include "../lib/lib.h"

void	init_args(int argc, char **argv, t_args *a);
void	push_swap(t_stack *sa, t_stack *sb);
int		subsq_len(int *array, int size);
int		*get_subsq(int *array, int size, int dim);
t_stack	longest_subsq(int *array, int size);
int		is_in_subsq(int n, t_stack *temp);
void	first_step(t_stack *sa, t_stack *sb);
void	begin_algorithm(t_stack *sa, t_stack *sb);
void	next_step(t_stack *sa, t_stack *sb, int to_move);
int		easiest_to_move(t_stack *sa, t_stack *sb);
int		steps_to_push(int num, t_stack *sb);
int		steps_to_push_help(int num, t_stack *sb, int i);
int		steps_from_head(int index, float middle, t_stack *stack);
float	middle_point_index(t_stack *stack);
void	do_double_move(t_stack *sa, t_stack *sb, char *move);
char	**get_moves(t_stack *sa, t_stack *sb, int to_move);
char	**fill_same_moves(char **ma, char **mb);
char	**fill_diff_moves(char **ma, char **mb);
char	**get_moves_b(t_stack *sa, t_stack *sb, int to_move);
char	**get_moves_a(t_stack *sa, int to_move);
char	**alloc_same_len(int len, int move_len);
char	**alloc_diff_len(int lf, int ls, int move_len, char **stack);
int		push_insertion_point(int to_move, t_stack *sb);
int		final_push_ip(int to_move, t_stack *st);
void	push_back_all(t_stack *sa, t_stack *sb);
void	sort_small(t_stack *sa, t_stack *sb);
void	push_back_small(t_stack *sa, t_stack *sb, int status);
void	sort_four(t_stack *sa, t_stack *sb, int status);
void	sort_five(t_stack *sa, t_stack *sb);
void	sort_array(t_stack *stack);

#endif
