/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:39:44 by jbasmati          #+#    #+#             */
/*   Updated: 2021/04/18 20:11:02 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*buf_dest;
	unsigned char	*buf_src;
	unsigned char	buf_c;
	unsigned char	*res;

	i = 0;
	buf_dest = (unsigned char *)dest;
	buf_src = (unsigned char *)src;
	buf_c = (unsigned char)c;
	while (i < n)
	{
		buf_dest[i] = buf_src[i];
		if (buf_src[i] == buf_c)
		{
			res = &buf_dest[i + 1];
			return (res);
		}
		i++;
	}
	return (NULL);
}
