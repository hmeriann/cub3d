/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:46:50 by jbasmati          #+#    #+#             */
/*   Updated: 2021/11/11 21:08:47 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	ft_end_of_func(char **line, char **remainder, char *buf, int chr_count)
{	
	if (chr_count == 0 && *remainder)
	{
		*line = ft_strdup(*remainder);
		buf = ft_free(buf);
		*remainder = ft_free(*remainder);
		return (0);
	}
	return (chr_checker(chr_count, &*remainder, line, &buf));
}

char	*remainder_joiner(int chr_count, char *buf, char *remainder)
{
	char	*tmp;
	char	*rem_pntr;

	tmp = "";
	rem_pntr = NULL;
	buf[chr_count] = '\0';
	tmp = remainder;
	remainder = ft_strjoin_gnl(remainder, buf);
	tmp = ft_free(tmp);
	buf = ft_free(buf);
	return (remainder);
}

int	chr_checker(int chr_count, char **remainder, char **line, char **buf)
{	
	buf = ft_free(*buf);
	if (chr_count == 0 && !*remainder)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (chr_count < 0)
	{
		*remainder = ft_free(*remainder);
		*line = ft_free(*line);
		return (-1);
	}
	return (1);
}

int	remainder_creator(char **remainder, char **line, char *buf)
{
	int		i;
	int		rem_len;
	char	*tmp;
	char	*rem_pntr;

	i = 0;
	rem_len = 0;
	tmp = NULL;
	rem_pntr = NULL;
	buf = ft_free(buf);
	while ((*remainder)[i] != '\n')
		i++;
	while ((*remainder)[rem_len])
		rem_len++;
	(*remainder)[i] = '\0';
	*line = ft_strdup(*remainder);
	tmp = ft_substr(*remainder + i + 1, 0, rem_len - i + 1);
	*remainder = ft_free(*remainder);
	rem_pntr = *remainder;
	*remainder = ft_strdup(tmp);
	tmp = ft_free(tmp);
	rem_pntr = ft_free(rem_pntr);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*remainder = NULL;
	int			chr_count;
	char		*buf;
	char		**tmp;

	if (BUFFER_SIZE <= 0 || fd < 0 || line == 0 || (read(fd, 0, 0) < 0))
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	if (remainder && ft_strchr_gnl(remainder, '\n'))
		return (remainder_creator(&remainder, line, buf));
	if (!remainder)
		remainder = ft_strdup_gnl("");
	tmp = line;
	*line = ft_strdup_gnl(remainder);
	tmp = ft_free(*tmp);
	chr_count = read(fd, buf, BUFFER_SIZE);
	if (chr_count)
	{		
		remainder = remainder_joiner(chr_count, buf, remainder);
		return (get_next_line(fd, line));
	}
	return (ft_end_of_func(line, &remainder, buf, chr_count));
}
