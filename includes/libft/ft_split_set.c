/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:06:13 by zu                #+#    #+#             */
/*   Updated: 2022/03/06 13:06:24 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char ch, char *charset)
{
	while (*charset)
		if (*charset++ == ch)
			return (1);
	return (0);
}

static void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static size_t	ft_count(char *s, char *c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (!is_sep(*s, c) && (is_sep(*(s + 1), c) || !*(s + 1)))
			cnt++;
		s++;
	}
	return (cnt);
}

char	**ft_split_set(char const *s, char *c)
{
	char	**out;
	size_t	i;
	size_t	row;

	row = 0;
	out = (char **)malloc(sizeof(char *) * (ft_count((char *)s, c) + 1));
	if (!out)
		return (NULL);
	while (*s)
	{
		while (is_sep(*s, c))
			s++;
		if (!*s)
			break ;
		i = 0;
		while (s[i] && !is_sep(s[i], c))
			i++;
		out[row] = ft_substr(s, 0, i);
		if (!out[row++])
			ft_free_split(out);
		s += i;
	}
	out[row] = NULL;
	return (out);
}
