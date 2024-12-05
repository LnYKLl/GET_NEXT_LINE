/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 01:27:31 by lkiloul           #+#    #+#             */
/*   Updated: 2024/12/05 05:00:53 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char **s)
{
	if (!*s)
		return ;
	free(*s);
	*s = NULL;
}

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
			ft_free(str);
	}
	else
	{
		line = ft_strdup(*str);
		ft_free(str);
	}
	return (line);
}

static char	*add_line(char *str, char *buffer, ssize_t bytes_read)
{
	char	*tmp;

	buffer[bytes_read] = '\0';
	if (str == NULL)
	{
		str = ft_strdup(buffer);
	}
	else
	{
		tmp = ft_strjoin(str, buffer);
		free(str);
		str = tmp;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		str = add_line(str, buffer, bytes_read);
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (bytes_read <= 0 && (!str || *str == '\0'))
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	return (get_line(&str));
}
