/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 13:34:37 by hmeriann          #+#    #+#             */
/*   Updated: 2021/04/28 18:56:40 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * The memmove() function copies len bytes from string src to string dst.
 * The two strings may overlap; the copy is always done
 * in a non-destructive manner.
 **/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp_dst;
	char	*tmp_src;
	size_t	i;

	i = 0;
	if (dst || src)
	{
		tmp_dst = (char *)dst;
		tmp_src = (char *)src;
		if (tmp_src > tmp_dst)
		{
			ft_memcpy(dst, src, len);
		}
		else
		{
			while (len--)
				tmp_dst[len] = tmp_src[len];
		}
	}
	return (dst);
}
