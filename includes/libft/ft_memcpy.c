/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:17:11 by jbasmati          #+#    #+#             */
/*   Updated: 2021/04/17 15:29:33 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*buf_dest;
	const char	*buf_src;

	i = 0;
	buf_dest = (char *)dest;
	buf_src = (char *)src;
	if (dest == NULL && src == NULL)
		return (dest);
	while (i < n)
	{
		buf_dest[i] = buf_src[i];
		i++;
	}
	return (dest);
}
