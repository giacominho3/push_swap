/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:33:09 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/12 16:44:16 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_lib.h"

void	init_args(int argc, char **argv, t_args *a)
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

void	push_swap(t_stack *sa, t_stack *sb)
{
	int	i;

	i = 0;
	if (already_ordered(sa->array, sa->size))
		return ;
	if (sa->size <= 5)
	{
		sort_small(sa, sb);
		return ;
	}
	else
		begin_algorithm(sa, sb);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_args	*a;

	a = malloc(sizeof(struct args));
	init_args(argc, argv, a);
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
	push_swap(stack_a, stack_b);
	free(stack_a->array);
	free(stack_b->array);
	free(stack_a);
	free(stack_b);
	free(a);
}
