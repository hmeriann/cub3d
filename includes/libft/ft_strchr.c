/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 22:18:29 by jbasmati          #+#    #+#             */
/*   Updated: 2022/02/04 19:38:42 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *s, int c)
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
