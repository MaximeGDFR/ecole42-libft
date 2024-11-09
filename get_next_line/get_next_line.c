/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:09:46 by j                 #+#    #+#             */
/*   Updated: 2024/11/09 12:46:42 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

/* ft_add_to_stash : dupliquer le contenu du buffer de read() et le stocker */
char *ft_add_to_stash(char *stash, const char *readed)
{
    char *new_stash;

    if (!readed)
        return (stash);
    if (!stash)
        return (ft_strdup(readed));
    if (readed[0] == '\0')
        return (stash);
    new_stash = ft_strjoin(stash, readed);
    if (!new_stash)
        return (NULL);
    free(stash);
    return (new_stash);
}


int	ft_line_finded(char *stash)
{
	int	i;

	if (!stash)
		return (-1);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char *ft_extract_line(char **stash)
{
    int     newline_pos;
    char    *line;
    char    *temp;

    if (!*stash || !**stash)
    {
        free(*stash);
        *stash = NULL;
        return NULL;
    }

    newline_pos = ft_line_finded(*stash);
    if (newline_pos >= 0)
    {
        line = ft_substr(*stash, 0, newline_pos + 1);
        temp = ft_strdup(*stash + newline_pos + 1);
    }
    else
    {
        line = ft_strdup(*stash);
        temp = NULL;
    }
    free(*stash);
    *stash = temp;
    return line;
}


char *get_next_line(int fd)
{
    static char *save = NULL;
    char *buf;
    char *line;
    int bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;

    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
    {
        free(save);
        save = NULL;
        return NULL;
    }

    line = NULL;
    bytes_read = 1;

    while (bytes_read > 0 && (!save || !ft_strchr(save, '\n')))
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buf);
            free(save);
            save = NULL;
            return NULL;
        }
        buf[bytes_read] = '\0';
        save = ft_add_to_stash(save, buf);
        if (!save)
        {
            free(buf);
            return NULL;
        }
    }

    free(buf);

    if (bytes_read == 0 && (!save || save[0] == '\0'))
    {
        free(save);
        save = NULL;
        return NULL;
    }

    line = ft_extract_line(&save);
    if (!line)
    {
        free(save);
        save = NULL;
    }
    return line;
}

