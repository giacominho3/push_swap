/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:56:21 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/12 16:42:52 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

//----------------stack structure
typedef struct stack
{
	int		*array;
	int		size;
	char	id;
	int		moves;
}		t_stack;

//----------------args structure
typedef struct args
{
	int		len;
	char	**args;
}		t_args;

//----------------sorters.c
int		already_ordered(int *array, int size);
void	sort_two(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_two_three(t_stack *stack);

//----------------operations.c
void	swap(t_stack *stack, int status);
void	rotate(t_stack *stack, int status);
void	reverse_rotate(t_stack *stack, int status);

//----------------binary_operations.c
void	push(t_stack *first, t_stack *second);
void	swap_both(t_stack *sa, t_stack *sb);
void	rotate_both(t_stack *sa, t_stack *sb);
void	reverse_rotate_both(t_stack *sa, t_stack *sb);

//----------------utils.c
void	print_stack(int *array, int len, char s_id);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
int		index_of(int num, t_stack *stack);
int		strarrlen(char **str_arr);

//----------------checkers.c
void	init_stack(char **argv, t_stack *stack);
void	check_params(char **argv, int argc);
void	check_duplicates(t_stack *stack);
int		is_num(char *str);
int		is_int(char *str);

//----------------printf.c & co
int		ft_get_type(char c, va_list args);
int		ft_printf(const char *s, ...);
int		ft_printer(char c);
int		lenght(int nb, int base);
char	*ft_itoa(int nb);
int		ft_putnbr(int n);
int		ft_ptr_len(uintptr_t n);
void	ft_print_ptr(uintptr_t n);
int		ft_putptr(unsigned long long n);
int		ft_putunsigned(unsigned int nb);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_hex_len(unsigned int n);
void	ft_print_hex(unsigned int n, char letter);
int		ft_puthex(unsigned int n, char letter);

//----------------split.c
char	**ft_split(const char *s, char c);
int		get_word(const char *s, char c);
char	*ft_substr(const char *s, int start, int len);
char	*ft_strdup(const char *s);
int		has_spaces(char *str);

//----------------ft_strcmp.c
int		ft_strcmp(char *strg1, char *strg2);

#endif
