/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:46:48 by jbasmati          #+#    #+#             */
/*   Updated: 2021/11/11 21:08:23 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stddef.h>

void	*ft_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_s;

	i = 0;
	j = start;
	len_s = 0;
	substr = "";
	if (s == 0)
		return (NULL);
	while (s[len_s])
		len_s++;
	substr = (char *)malloc(sizeof(*s) * (len + 1));
	if (substr == NULL)
		return (NULL);
	if (start < len_s)
	{
		while (i < len_s && j < len + start)
			substr[i++] = s[j++];
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int		i;
	char	*buf_s;
	char	buf_c;

	i = 0;
	buf_s = (char *)s;
	buf_c = c;
	while (buf_s[i])
	{
		if (buf_s[i] == buf_c)
			return (&buf_s[i]);
		i++;
	}
	if (c == '\0')
		return (&buf_s[i]);
	return (NULL);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	res = (char *)malloc(sizeof(const char) * (len + 1));
	if (res == NULL)
		return (res);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;	

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	res = (char *)malloc(i + j + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
