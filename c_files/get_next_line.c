/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:50:46 by gifulvi           #+#    #+#             */
/*   Updated: 2022/10/06 16:46:45 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/c_lib.h"

char	*ft_get_line(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		s[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		s[i] = save[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_save(char *save)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!s)
		return (0);
	i++;
	j = 0;
	while (save[i])
		s[j++] = save[i++];
	s[j] = '\0';
	free(save);
	return (s);
}

char	*ft_read_and_save(int fd, char *save)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char));
	if (!buffer)
		return (0);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, 1);
		if (read_bytes == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[read_bytes] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*first_line;
	static char	*save;

	if (fd < 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (0);
	first_line = ft_get_line(save);
	save = ft_save(save);
	return (first_line);
}
