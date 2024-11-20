/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkiloul <lkiloul@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:05:21 by lkiloul           #+#    #+#             */
/*   Updated: 2024/11/20 14:19:22 by lkiloul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 8

char *get_next_line(int fd)
{
    char *str;
    int bytes_read;

    str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!str)
        return (NULL);


    bytes_read = read(fd, str, BUFFER_SIZE);
    if (bytes_read <= 0)
    {
        free(str);
        return (NULL); 
    }


    str[bytes_read] = '\0';
    return (str);
}

void ft_putstr(char *str)
{
    if (!str)
        return;
    while (*str)
    {
        write(1, str, 1);
        str++;
    }
}

int main(void)
{
    char *line;

    line = get_next_line(0); 
    if (line)
    {
        ft_putstr(line);
        free(line);      
    }
    return (0);
}
