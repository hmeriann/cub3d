/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:12:35 by zu                #+#    #+#             */
/*   Updated: 2022/03/06 21:34:39 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

int	ft_digits(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_count_chars(const char *line, char *chars)
{
	int		i;
	int		count;

	count = 0;
	while (*line)
	{
		i = 0;
		while (chars[i])
		{
			if (*line == chars[i++])
			{
				count++;
				break ;
			}
		}
		line++;
	}
	return (count);
}

void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	mini_strchr(char *str, char c)
{
	while (*str)
		if (*str++ == c)
			return (1);
	return (0);
}