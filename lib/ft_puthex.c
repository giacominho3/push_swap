/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:29:37 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/06 15:42:03 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

int	ft_hex_len(unsigned int n)
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

void	ft_print_hex(unsigned int n, char letter)
{
	if (n >= 16)
	{
		ft_print_hex((n / 16), letter);
		ft_print_hex((n % 16), letter);
	}
	else
	{
		if (n > 9)
		{
			if (letter == 'x')
				ft_putchar(n - 10 + 'a');
			else
				ft_putchar(n - 10 + 'A');
		}
		else
			ft_putchar(n + 48);
	}
}

int	ft_puthex(unsigned int n, char letter)
{
	if (n == 0)
		return (write (1, "0", 1));
	ft_print_hex(n, letter);
	return (ft_hex_len(n));
}
