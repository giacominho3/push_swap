/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:28:26 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/06 15:53:57 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

int	already_ordered(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i + 1] < array[i])
			return (0);
		i++;
	}
	return (1);
}

void	sort_two(t_stack *stack)
{
	int	temp;

	temp = 0;
	if (stack->array[0] > stack->array[1])
	{
		temp = stack->array[0];
		stack->array[0] = stack->array[1];
		stack->array[1] = temp;
	}
}

void	sort_three(t_stack *stack)
{
	if (stack->array[0] > stack->array[1])
	{
		if (stack->array[1] < stack->array[2])
		{
			if (stack->array[0] > stack->array[2])
				rotate(stack, 1);
			else
				swap(stack, 1);
		}
		else
		{
			swap(stack, 1);
			reverse_rotate(stack, 1);
		}
	}
	else if (!already_ordered(stack->array, stack->size))
	{
		if (stack->array[0] > stack->array[2])
			reverse_rotate(stack, 1);
		else
		{
			swap(stack, 1);
			rotate(stack, 1);
		}
	}
}

void	sort_two_three(t_stack *stack)
{
	if (stack->size == 2)
		sort_two(stack);
	else if (stack->size == 3)
		sort_three(stack);
}
