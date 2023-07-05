/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsequence.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 17:13:12 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/06 16:18:31 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_lib.h"

int	subsq_len(int *array, int size)
{
	int	len;
	int	biggest;

	len = 0;
	biggest = -2147483648;
	while (size)
	{
		if (*array >= biggest)
		{
			len++;
			biggest = *array;
		}
		array++;
		size--;
	}
	return (len);
}

int	*get_subsq(int *array, int size, int dim)
{
	int	*subsq;
	int	biggest;
	int	i;

	biggest = -2147483648;
	i = 0;
	subsq = malloc(dim * sizeof(int));
	while (size)
	{
		if (*array >= biggest)
		{
			biggest = *array;
			subsq[i] = *array;
			i++;
		}
		array++;
		size--;
	}
	return (subsq);
}

t_stack	longest_subsq(int *array, int size)
{
	t_stack	stack;
	int		*subsq;
	int		max_len;
	int		temp;

	max_len = 0;
	while (size)
	{
		temp = subsq_len(array, size);
		if (max_len < temp)
		{
			subsq = get_subsq(array, size, temp);
			max_len = temp;
		}
		array++;
		size--;
	}
	stack.array = subsq;
	stack.size = max_len;
	free(subsq);
	return (stack);
}

int	is_in_subsq(int n, t_stack *temp)
{
	int	i;

	i = 0;
	while (i < temp->size)
	{
		if (n == temp->array[i])
			return (1);
		i++;
	}
	return (0);
}
