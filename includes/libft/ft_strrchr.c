/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:46:35 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/05 16:19:47 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				j;
	char			*buf_s;
	unsigned char	buf_c;

	i = 0;
	j = 0;
	buf_s = (char *)s;
	buf_c = (unsigned char)c;
	while (buf_s[j])
	{
		j++;
	}	
	if (buf_c == '\0')
		return (&buf_s[j]);
	while (j >= 0)
	{
		if (buf_s[j] == buf_c)
			return (&buf_s[j]);
		j--;
	}
	return (NULL);
}
