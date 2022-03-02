/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:46:32 by jbasmati          #+#    #+#             */
/*   Updated: 2022/02/24 23:48:10 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	min_len;

	min_len = len;
	if (ft_strlen(haystack) < len)
		min_len = ft_strlen(haystack);
	if ((ft_strlen(needle) > min_len) || haystack == NULL || needle == NULL)
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (i <= min_len - ft_strlen(needle))
	{
		j = 0;
		while (haystack[i + j] == needle[j] && j < len)
		{
			j++;
			if (j == ft_strlen(needle))
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
