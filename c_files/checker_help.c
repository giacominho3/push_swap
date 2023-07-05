/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:27:02 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/12 16:41:36 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c_lib.h"

void	init_arguments(int argc, char **argv, t_args *a)
{
	if (has_spaces(argv[1]))
	{
		a->args = ft_split(argv[1], ' ');
		a->len = strarrlen(a->args);
	}
	else
	{
		argv++;
		a->args = argv;
		a->len = argc - 1;
	}
}

char	**read_moves(int size)
{
	char	**moves;
	int		i;
	int		max_moves;

	i = 0;
	max_moves = 5500;
	if (size <= 3)
		max_moves = 3;
	else if (size <= 5)
		max_moves = 12;
	else if (size <= 100)
		max_moves = 700;
	moves = malloc(max_moves * sizeof(char *));
	while (1)
	{
		moves[i] = malloc(4 * sizeof(char));
		moves[i] = get_next_line(0);
		if (moves[i] == NULL)
		{
			free(moves[i]);
			break ;
		}
	i++;
	}
	return (moves);
}
