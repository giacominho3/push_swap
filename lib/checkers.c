/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:07:01 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/11 16:32:18 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

void	init_stack(char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	while (*argv)
	{
		stack->array[i] = ft_atoi(*argv);
		argv++;
		i++;
	}
}

int	is_num(char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
			return (0);
	}
	return (1);
}

int	is_int(char *str)
{
	int	temp;

	if (ft_strlen(str) > 11)
		return (0);
	temp = ft_atoi(str);
	if (temp == -1 && ft_strlen(str) > 2)
		return (0);
	return (1);
}

void	check_params(char **argv, int argc)
{
	int	*array;
	int	i;

	i = 0;
	if (argc <= 1)
		exit(0);
	array = malloc((argc - 1) * sizeof(int));
	while (*argv)
	{
		if (is_num(*argv) && is_int(*argv))
		{
			array[i] = ft_atoi(*argv);
			i++;
			argv++;
		}
		else
		{
			write(2, "Error\n", 6);
			free(array);
			exit(0);
		}
	}
	free(array);
}

void	check_duplicates(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = 0;
		while (j < i)
		{
			if (stack->array[i] == stack->array[j])
			{
				write(2, "Error\n", 6);
				free(stack->array);
				exit(0);
			}
			j++;
		}
		i++;
	}
}
