/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 14:13:43 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/12 16:41:00 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c_lib.h"

void	exec_double_move(t_stack *sa, t_stack *sb, char *move)
{
	if (!ft_strcmp(move, "ra\n"))
		rotate(sa, 1);
	else if (!ft_strcmp(move, "rb\n"))
		rotate(sb, 1);
	else if (!ft_strcmp(move, "rra\n"))
		reverse_rotate(sa, 1);
	else if (!ft_strcmp(move, "rrb\n"))
		reverse_rotate(sb, 1);
	else if (!ft_strcmp(move, "ss\n"))
		swap_both(sa, sb);
	else if (!ft_strcmp(move, "rr\n"))
		rotate_both(sa, sb);
	else if (!ft_strcmp(move, "rrr\n"))
		reverse_rotate_both(sa, sb);
}

void	execute_instructions(t_stack *sa, t_stack *sb, char **moves)
{
	int	i ;

	i = 0;
	while (i < strarrlen(moves))
	{
		if (!ft_strcmp(moves[i], "pb\n"))
			push(sa, sb);
		else if (!ft_strcmp(moves[i], "pa\n"))
			push(sb, sa);
		else if (!ft_strcmp(moves[i], "sa\n"))
			swap(sa, 1);
		else if (!ft_strcmp(moves[i], "sb\n"))
			swap(sb, 1);
		else
			exec_double_move(sa, sb, moves[i]);
		i++;
	}
	free(moves);
}

void	ft_checker(t_stack *sa, t_stack *sb, char **moves)
{
	execute_instructions(sa, sb, moves);
	if (already_ordered(sa->array, sa->size) && (sb->size == 0))
		write (1, "OK\n", 3);
	else
		write (1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**moves;
	t_args	*a;

	a = malloc(sizeof(struct args));
	init_arguments(argc, argv, a);
	check_params(a->args, a->len);
	stack_a = malloc(sizeof(struct stack));
	stack_a->array = malloc((a->len) * sizeof(int));
	stack_a->size = a->len;
	stack_a->id = 'a';
	stack_a->moves = 0;
	init_stack(a->args, stack_a);
	check_duplicates(stack_a);
	stack_b = malloc(sizeof(struct stack));
	stack_b->array = malloc(a->len * sizeof(int));
	stack_b->id = 'b';
	stack_b->moves = 0;
	moves = read_moves(stack_a->size);
	ft_checker(stack_a, stack_b, moves);
}
