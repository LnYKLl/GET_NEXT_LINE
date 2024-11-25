/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:05:21 by lkiloul           #+#    #+#             */
/*   Updated: 2024/11/25 16:45:34 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *get_next_line(int fd)
{
    char *buffer;
    int bytes_read;

    buffer = malloc(sizeof(char *) * BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (!bytes_read)
        return (NULL);
    while (!ft_strchr(buffer, '\n'))
        ft_putstr(buffer);
    return ("test");
}
