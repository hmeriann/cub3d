/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:19:20 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/05 01:46:38 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_mstrfree(char **darr)
{
	int		i;

	i = 0;
	while (darr[i])
	{
		free(darr[i]);
		i++;
	}
	free(darr);
	return (NULL);
}

int	ft_get_str_cnt(char const *s, char c)
{
	int		str_cnt;
	int		i;

	str_cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			str_cnt++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (str_cnt);
}

size_t	ft_get_str(char **nxt_str,	char c)
{
	size_t	nxt_str_len;

	nxt_str_len = 0;
	while (**nxt_str == c && **nxt_str != '\0')
		(*nxt_str)++;
	while (**nxt_str != c && **nxt_str != '\0')
	{
		nxt_str_len += 1;
		(*nxt_str)++;
	}
	return (nxt_str_len);
}

char	**ft_split(char const *s, char c)
{
	char	**darr;
	int		i;
	char	*nxt_str;
	char	*str_buf;

	i = 0;
	nxt_str = (char *)s;
	if (!s)
		return (NULL);
	darr = (char **)malloc(sizeof(char *) * (ft_get_str_cnt(s, c) + 1));
	if (!darr)
		return (NULL);
	while (i < ft_get_str_cnt(s, c) && nxt_str)
	{
		while (*nxt_str == c)
			nxt_str++;
		str_buf = nxt_str;
		darr[i] = ft_substr(nxt_str, 0, ft_get_str(&str_buf, c));
		nxt_str = str_buf;
		if (!darr[i])
			return (ft_mstrfree(darr));
		i++;
	}
	darr[i] = NULL;
	return (darr);
}