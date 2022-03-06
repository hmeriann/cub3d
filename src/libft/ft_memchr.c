/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:46:15 by hmeriann          #+#    #+#             */
/*   Updated: 2022/03/06 23:13:16 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp_s;
	unsigned char	target;
	size_t			i;

	i = 0;
	tmp_s = (unsigned char *)s;
	target = (unsigned char)c;
	while (i < n)
	{
		if (*tmp_s == (unsigned char)target)
			return (tmp_s);
		tmp_s++;
		i++;
	}
	return (NULL);
}
