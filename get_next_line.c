/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:27:31 by lkiloul           #+#    #+#             */
/*   Updated: 2024/12/04 02:23:21 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **str)
{
	char	*line;
	char	*tmp;
	size_t	i;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
	{
		line = ft_substr(*str, 0, i + 1);
		tmp = ft_strdup(*str + i + 1);
		free(*str);
		*str = tmp;
		if (**str == '\0')
		{
			free(*str);
			*str = NULL;
		}
	}
	else
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		if (!str)
			str = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(str, buffer);
			str = tmp;
		}
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (bytes_read < 0)
		return (NULL);
	if (bytes_read == 0 && (!str || *str == '\0'))
		return (NULL);
	return (get_line(&str));
}
