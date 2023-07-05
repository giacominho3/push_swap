/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:09:06 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/06 15:42:11 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

int	ft_ptr_len(uintptr_t n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_print_ptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_print_ptr((n / 16));
		ft_print_ptr((n % 16));
	}
	else
	{
		if (n > 9)
			ft_putchar(n - 10 + 'a');
		else
			ft_putchar(n + 48);
	}
}

int	ft_putptr(unsigned long long n)
{
	int	count;

	count = 0;
	count += write (1, "0x", 2);
	if (n == 0)
		count += write (1, "0", 1);
	else
	{
		ft_print_ptr(n);
		count += ft_ptr_len(n);
	}
	return (count);
}
