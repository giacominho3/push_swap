/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:53:03 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/12 16:40:33 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_lib.h"

char	**get_moves_a(t_stack *sa, int mov)
{
	int		n_moves_a;
	char	**moves_a;
	int		i;

	n_moves_a = steps_from_head(index_of(mov, sa), middle_point_index(sa), sa);
	moves_a = malloc((n_moves_a + 1) * sizeof(char **));
	i = 0;
	if (index_of(mov, sa) <= middle_point_index(sa))
	{
		while (i < n_moves_a)
		{
			moves_a[i] = "RA";
			i++;
		}
	}
	else
	{
		while (i < n_moves_a)
		{
			moves_a[i] = "RRA";
			i++;
		}
	}
	moves_a[i] = NULL;
	return (moves_a);
}

char	**get_moves_b(t_stack *sa, t_stack *sb, int to_move)
{
	int		n_moves_b;
	char	**moves_b;
	int		i;

	n_moves_b = steps_to_push(sa->array[index_of(to_move, sa)], sb);
	moves_b = malloc((n_moves_b + 1) * sizeof(char **));
	i = 0;
	if ((float)push_insertion_point(to_move, sb) < middle_point_index(sb))
	{
		while (i < n_moves_b)
		{
			moves_b[i] = "RB";
			i++;
		}
	}
	else
	{
		while (i < n_moves_b)
		{
			moves_b[i] = "RRB";
			i++;
		}
	}
	moves_b[i] = NULL;
	return (moves_b);
}

char	**fill_diff_moves(char **ma, char **mb)
{
	char	**tm;
	int		cont[2];
	int		j;
	int		la;
	int		lb;

	la = strarrlen(ma);
	lb = strarrlen(mb);
	tm = malloc((la + lb + 2) * sizeof(char **));
	cont[0] = 0;
	cont[1] = 0;
	j = 0;
	while ((j < (la + lb)))
	{
		if ((cont[0] < la) && (ft_strcmp(ma[cont[0]], "\0")))
			tm[j++] = ma[cont[0]];
		if ((cont[1] < lb) && (ft_strcmp(mb[cont[1]], "\0")))
			tm[j++] = mb[cont[1]];
		cont[0]++;
		cont[1]++;
	}
	tm[j++] = "PA";
	tm[j] = "\0";
	return (tm);
}

char	**fill_same_moves(char **ma, char **mb)
{
	char	**tm;
	int		i;
	int		la;
	int		lb;

	i = 0;
	la = strarrlen(ma);
	lb = strarrlen(mb);
	if (la > lb)
		tm = alloc_diff_len(la, lb, ft_strlen(ma[0]), ma);
	else if (lb > la)
		tm = alloc_diff_len(lb, la, ft_strlen(mb[0]), mb);
	else
		tm = alloc_same_len(la, ft_strlen(ma[0]));
	return (tm);
}

char	**get_moves(t_stack *sa, t_stack *sb, int to_move)
{
	char	**ma;
	char	**mb;
	char	**tm;

	ma = get_moves_a(sa, to_move);
	mb = get_moves_b(sa, sb, to_move);
	if (ft_strlen(ma[0]) != ft_strlen(mb[0]))
		tm = fill_diff_moves(ma, mb);
	else
		tm = fill_same_moves(ma, mb);
	free(ma);
	free(mb);
	return (tm);
}
