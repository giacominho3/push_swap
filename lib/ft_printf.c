/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:51:17 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/06 15:41:55 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

int	ft_get_type(char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	if (c == 's')
		count += ft_putstr(va_arg(args, char *));
	if (c == 'p')
		count += ft_putptr(va_arg(args, unsigned long long));
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(args, int));
	if (c == 'u')
		count += ft_putunsigned(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		count += ft_puthex(va_arg(args, unsigned int), c);
	if (c == '%')
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			count += ft_get_type(s[i + 1], args);
			i++;
		}
		else
			count += ft_putchar(s[i]);
		i++;
	}
	va_end(args);
	return (count);
}
