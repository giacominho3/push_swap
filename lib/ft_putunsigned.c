/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:02:13 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/06 15:42:17 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

int	ft_printer(char c)
{
	return (write(1, &c, 1));
}

int	ft_putunsigned(unsigned int nb)
{
	char	c;
	int		count;

	count = 0;
	if (nb <= 9)
	{
		c = nb + '0';
		count += ft_printer(c);
	}
	else
	{
		count += ft_putnbr (nb / 10);
		c = ((nb % 10) + '0');
		count += ft_printer(c);
	}
	return (count);
}
