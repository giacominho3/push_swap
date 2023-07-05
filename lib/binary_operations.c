/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:49:38 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/06 15:41:11 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

void	push(t_stack *first, t_stack *second)
{
	if (first->size == 0)
		return ;
	second->size++;
	if (second->size > 0)
		reverse_rotate(second, 0);
	second->array[0] = first->array[0];
	rotate(first, 0);
	first->size--;
	ft_printf("p%c\n", second->id);
	first->moves++;
}

void	swap_both(t_stack *sa, t_stack *sb)
{
	swap(sa, 0);
	swap(sb, 0);
	ft_printf("ss\n");
}

void	rotate_both(t_stack *sa, t_stack *sb)
{
	rotate(sa, 0);
	rotate(sb, 0);
	ft_printf("rr\n");
}

void	reverse_rotate_both(t_stack *sa, t_stack *sb)
{
	reverse_rotate(sa, 0);
	reverse_rotate(sb, 0);
	ft_printf("rrr\n");
}
