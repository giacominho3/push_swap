/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:25:50 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/11 11:42:03 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

void	print_stack(int *array, int len, char s_id)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("stack_%c[%d]: %d\n", s_id, i, array[i]);
		i++;
	}
	ft_printf("\n");
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	value;

	value = 0;
	sign = 1;
	while (*str == ' ' || (*str <= 13 && *str >= 9))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		value *= 10;
		value += *str - '0';
		str++;
	}
	value *= sign;
	if (value < -2147483648 || value > 2147483647)
		return (-1);
	return ((int)value);
}

int	index_of(int num, t_stack *stack)
{
	int	i;
	int	index;

	i = 0;
	index = -1;
	while (i < stack->size)
	{
		if (stack->array[i] == num)
		{
			index = i;
			break ;
		}
		i++;
	}
	return (index);
}

int	strarrlen(char **str_arr)
{
	int	len;

	len = 0;
	if (str_arr == NULL)
		return (0);
	while (str_arr[len] != NULL)
		len++;
	return (len);
}
