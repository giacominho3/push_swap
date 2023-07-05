/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:23:58 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/06 16:18:29 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_lib.h"

void	push_back_small(t_stack *sa, t_stack *sb, int status)
{
	int	counter;

	counter = 1 + status;
	while (counter)
	{
		if (sb->array[0] > sa->array[0] && sb->array[0] < sa->array[1])
			rotate(sa, 1);
		else if (sb->array[0] > sa->array[1]
			&& sb->array[0] < sa->array[2])
		{
			if (sa->size == 4)
				reverse_rotate(sa, 1);
			reverse_rotate(sa, 1);
		}
		else if (status)
		{
			if (sb->array[0] > sa->array[2] && sb->array[0] < sa->array[3])
				reverse_rotate(sa, 1);
		}
		push(sb, sa);
		sort_array(sa);
		counter--;
	}
}

void	sort_four(t_stack *sa, t_stack *sb, int status)
{
	push(sa, sb);
	sort_three(sa);
	push_back_small(sa, sb, status);
	return ;
}

void	sort_five(t_stack *sa, t_stack *sb)
{
	push(sa, sb);
	sort_four(sa, sb, 1);
	return ;
}

void	sort_small(t_stack *sa, t_stack *sb)
{
	if (sa->size == 5)
		sort_five(sa, sb);
	else if (sa->size == 4)
		sort_four(sa, sb, 0);
	else if (sa->size <= 3)
		sort_two_three(sa);
	return ;
}
