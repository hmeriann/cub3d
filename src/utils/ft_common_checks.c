/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:12:35 by zu                #+#    #+#             */
/*   Updated: 2022/03/06 15:50:12 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

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
	char	*tmp_line;

	count = 0;
	tmp_line = ft_strdup(line);
	while (tmp_line)
	{
		i = 0;
		while (chars[i])
		{
			if (*tmp_line == chars[i])
			{
				count++;
				break ;
			}
			i++;
		}
		line++;
	}
	free(tmp_line);
	tmp_line = NULL;
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