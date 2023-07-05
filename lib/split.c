/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:34:19 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/11 16:37:44 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*temp;
	char	*head;

	temp = (char *)s;
	dup = (char *)malloc(ft_strlen(temp) + 1);
	if (!dup)
		return (0);
	head = dup;
	while (*temp)
	{
		*dup = *temp;
		dup++;
		temp++;
	}
	*dup = '\0';
	return (head);
}

char	*ft_substr(const char *s, int start, int len)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	if ((int) start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	if ((int)len > ft_strlen((char *)s))
		len = ft_strlen((char *)s);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j++] = s[i];
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

int	get_word(const char *s, char c)
{
	int	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			++ret;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (ret);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		i;
	int		len;

	if (!s)
		return (0);
	i = 0;
	ret = malloc(sizeof(char *) * (get_word(s, c) + 1));
	if (!ret)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i++] = ft_substr(s - len, 0, len);
		}
		else
			++s;
	}
	ret[i] = 0;
	return (ret);
}

int	has_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
