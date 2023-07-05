/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:42:07 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/12 16:42:19 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

int	ft_strcmp(char *strg1, char *strg2)
{
	while ((*strg1 != '\0' && *strg2 != '\0' ) && *strg1 == *strg2)
	{
		strg1++;
		strg2++;
	}
	if (*strg1 == *strg2)
		return (0);
	else
		return (*strg1 - *strg2);
}
