/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:49:01 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/06 16:18:21 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_lib.h"

char	**alloc_diff_len(int lf, int ls, int move_len, char **stack)
{
	char	**tm;
	int		i;

	tm = malloc((lf + 2) * sizeof(char *));
	i = 0;
	while (i < lf)
	{
		if (i < ls)
		{
			if (move_len == 2)
				tm[i] = "RR";
			else if (move_len == 3)
				tm[i] = "RRR";
		}
		else
		{
			if (stack[i])
				tm[i] = stack[i];
		}
		i++;
	}
	tm[i++] = "PA";
	tm[i] = "\0";
	return (tm);
}

char	**alloc_same_len(int len, int move_len)
{
	int		i;
	char	**tm;

	i = 0;
	tm = malloc((len + 2) * sizeof(char *));
	while (i < len)
	{
		if (move_len == 2)
			tm[i] = "RR";
		else if (move_len == 3)
			tm[i] = "RRR";
		i++;
	}
	tm[i++] = "PA";
	tm[i] = "\0";
	return (tm);
}

int	push_insertion_point(int to_move, t_stack *st)
{
	int	i;

	i = 1;
	if ((to_move > st->array[0]) && (st->array[0] > st->array[st->size - 1]))
		return (0);
	while (i < st->size)
	{
		if ((to_move > st->array[i]) && (to_move < st->array[i - 1]))
			return (i - 1);
		else if (((to_move > st->array[i]) && (to_move > st->array[i - 1]))
			|| ((to_move < st->array[i]) && (to_move < st->array[i - 1])))
		{
			if (st->array[i] > st->array[i - 1])
				return (i - 1);
		}
		i++;
	}
	return (0);
}

int	final_push_ip(int to_move, t_stack *st)
{
	int	i;

	i = 1;
	if ((to_move < st->array[0]) && (st->array[0] < st->array[st->size - 1]))
		return (0);
	while (i < st->size)
	{
		if ((to_move < st->array[i]) && (to_move > st->array[i - 1]))
			return (i);
		else if (((to_move < st->array[i]) && (to_move < st->array[i - 1]))
			|| ((to_move > st->array[i]) && (to_move > st->array[i - 1])))
		{
			if (st->array[i] < st->array[i - 1])
				return (i);
		}
		i++;
	}
	return (0);
}

void	sort_array(t_stack *stack)
{
	int	i;
	int	min;
	int	index;
	int	steps;

	i = 0;
	min = 2147483627;
	while (i < stack->size)
	{
		if (stack->array[i] < min)
			min = stack->array[i];
		i++;
	}
	index = index_of(min, stack);
	steps = steps_from_head(index, middle_point_index(stack), stack);
	if (index < middle_point_index(stack))
	{
		while (steps--)
			rotate(stack, 1);
	}
	else
		while (steps--)
			reverse_rotate(stack, 1);
}
