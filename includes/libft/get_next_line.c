/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:12:58 by zu                #+#    #+#             */
/*   Updated: 2021/11/09 15:32:18 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

int	get_reminder(char **remainder, char **line, char **nl_ptr)
{
	*nl_ptr = ft_strchr(*remainder, '\n');
	**nl_ptr = '\0';
	*line = ft_strdup(*remainder);
	if (*line == NULL)
		return (-1);
	if (ft_strcpy(*remainder, ++(*nl_ptr)))
		return (0);
	else
		return (-1);
}

char	*find_pointer(char **remainder, char **line, char **nl_ptr)
{
	*nl_ptr = NULL;
	if (*remainder)
	{
		if (ft_strchr(*remainder, '\n'))
		{
			if ((get_reminder(remainder, line, nl_ptr)) == -1)
				return (NULL);
		}
		else
		{
			*line = ft_strdup(*remainder);
			if (*line == NULL)
				return (NULL);
			free(*remainder);
			*remainder = NULL;
		}
	}
	else
	{
		*line = ft_strdup("");
		if (*line == NULL)
			return (NULL);
	}
	return (*nl_ptr);
}

int	make_line(char **nl_ptr, char *buf, char **remainder, char **line)
{
	char	*temp;

	*nl_ptr = ft_strchr(buf, '\n');
	if (*nl_ptr)
	{
		**nl_ptr = '\0';
		(*nl_ptr)++;
		*remainder = ft_strdup(*nl_ptr);
		if (!remainder)
		{
			free(remainder);
			return (-1);
		}
	}
	temp = *line;
	*line = ft_strjoin(*line, buf);
	free(temp);
	if (!*line)
	{
		free(*line);
		return (-1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*buf;
	char		*nl_ptr;
	int			read_res;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (read(fd, 0, 0) != 0))
		return (-1);
	nl_ptr = find_pointer(&remainder, line, &nl_ptr);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (-1);
	read_res = 1;
	while (!nl_ptr && read_res > 0)
	{
		read_res = read(fd, buf, BUFFER_SIZE);
		if (read_res == -1)
			return (-1);
		buf[read_res] = '\0';
		if ((make_line(&nl_ptr, buf, &remainder, line)) == -1)
			return (-1);
	}
	free(buf);
	if (read_res != 0)
		return (1);
	return (0);
}
