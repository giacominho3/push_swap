/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:12:05 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/06 15:42:21 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

void	swap(t_stack *stack, int status)
{
	int	temp;

	temp = stack->array[0];
	stack->array[0] = stack->array[1];
	stack->array[1] = temp;
	if (status)
	{
		ft_printf("s%c\n", stack->id);
		stack->moves++;
	}
}

void	rotate(t_stack *stack, int status)
{
	int	temp;
	int	i;

	i = 1;
	temp = stack->array[0];
	while (i < stack->size)
	{
		stack->array[i - 1] = stack->array[i];
		i++;
	}
	stack->array[stack->size - 1] = temp;
	if (status)
	{
		ft_printf("r%c\n", stack->id);
		stack->moves++;
	}
}

void	reverse_rotate(t_stack *stack, int status)
{
	int	temp;
	int	i;

	i = stack->size - 1;
	temp = stack->array[stack->size - 1];
	while (i)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = temp;
	if (status)
	{
		ft_printf("rr%c\n", stack->id);
		stack->moves++;
	}
}
