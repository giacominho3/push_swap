/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:38:25 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/12 16:40:28 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_lib.h"

void	push_back_all(t_stack *sa, t_stack *sb)
{
	int	i;

	while (sb->size)
	{
		i = final_push_ip(sb->array[0], sa);
		if ((float)i < middle_point_index(sa))
		{
			while (i--)
				rotate(sa, 1);
		}
		else
		{
			while (sa->size - i)
			{
				reverse_rotate(sa, 1);
				i++;
			}
		}
		push(sb, sa);
	}
}

void	do_double_move(t_stack *sa, t_stack *sb, char *move)
{
	if (!ft_strcmp(move, "SS"))
		swap_both(sa, sb);
	else if (!ft_strcmp(move, "RR"))
		rotate_both(sa, sb);
	else if (!ft_strcmp(move, "RRR"))
		reverse_rotate_both(sa, sb);
}

void	next_step(t_stack *sa, t_stack *sb, int to_move)
{
	char	**moves;
	int		i;

	moves = get_moves(sa, sb, to_move);
	i = 0;
	while (ft_strcmp(moves[i], "\0"))
	{
		if (!ft_strcmp(moves[i], "PA"))
			push(sa, sb);
		if (!ft_strcmp(moves[i], "PB"))
			push(sb, sa);
		else if (!ft_strcmp(moves[i], "RA"))
			rotate(sa, 1);
		else if (!ft_strcmp(moves[i], "RB"))
			rotate(sb, 1);
		else if (!ft_strcmp(moves[i], "RRA"))
			reverse_rotate(sa, 1);
		else if (!ft_strcmp(moves[i], "RRB"))
			reverse_rotate(sb, 1);
		else
			do_double_move(sa, sb, moves[i]);
		i++;
	}
	free(moves);
}

void	first_step(t_stack *sa, t_stack *sb)
{
	push(sa, sb);
	push(sa, sb);
	if (sb->array[0] < sb->array[1])
		swap(sb, 1);
}

void	begin_algorithm(t_stack *sa, t_stack *sb)
{
	first_step(sa, sb);
	while (sa->size > 5)
		next_step(sa, sb, sa->array[easiest_to_move(sa, sb)]);
	sort_small(sa, sb);
	push_back_all(sa, sb);
	sort_array(sa);
}
