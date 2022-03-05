/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:45:44 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/05 16:20:47 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*buf_dest;
	char	*buf_src;
	size_t	i;

	buf_dest = (char *)dest;
	buf_src = (char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (buf_src > buf_dest)
	{
		while (i < n)
		{
			buf_dest[i] = buf_src[i];
			i++;
		}					
	}
	else
	{
		while (n-- > 0)
			buf_dest[n] = buf_src[n];
	}	
	return (buf_dest);
}
