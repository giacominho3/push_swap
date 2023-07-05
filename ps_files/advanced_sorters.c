/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_sorters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:39:25 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/10 17:36:46 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_lib.h"

float	middle_point_index(t_stack *stack)
{
	float	middle;

	middle = (stack->size / 2) - 0.5;
	return (middle);
}

int	steps_from_head(int index, float middle, t_stack *stack)
{
	float	f_index;

	f_index = (float)index;
	if (f_index == middle)
		return ((int)middle);
	else if (f_index < middle)
		return (index);
	else
		return (stack->size - index);
}

int	steps_to_push_help(int num, t_stack *sb, int i)
{
	if (sb->array[i] > sb->array[i - 1])
	{
		if ((num > sb->array[i]) || (num < sb->array[i - 1]))
		{
			if ((float)i > middle_point_index(sb))
				return (sb->size - i);
			else
				return (i);
		}
	}
	return (0);
}

int	steps_to_push(int num, t_stack *sb)
{
	int	i;

	i = 1;
	if ((num > sb->array[0]) && (sb->array[0] > sb->array[sb->size - 1]))
		return (0);
	while (i < sb->size)
	{
		if ((num > sb->array[i]) && (num < sb->array[i - 1]))
		{
			if ((float)i > middle_point_index(sb))
				return (sb->size - i);
			else
				return (i);
		}
		else if (((num > sb->array[i]) && (num > sb->array[i - 1]))
			|| ((num < sb->array[i]) && (num < sb->array[i - 1])))
		{
			if (steps_to_push_help(num, sb, i))
				return (steps_to_push_help(num, sb, i));
		}
		i++;
	}
	return (0);
}

int	easiest_to_move(t_stack *sa, t_stack *sb)
{
	int	smallest;
	int	i;
	int	sfh;
	int	stp;
	int	index;

	smallest = 2147483647;
	i = 0;
	index = 0;
	while (i < sa->size)
	{
		sfh = steps_from_head(i, middle_point_index(sa), sa);
		stp = steps_to_push(sa->array[i], sb);
		if (sfh + stp <= smallest)
		{
			smallest = sfh + stp;
			index = i;
		}
		i++;
	}
	return (index);
}
