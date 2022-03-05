/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 21:43:53 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/05 16:20:06 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	int				i;
	int				j;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	j = dst_len;
	while ((src[i] != '\0') && (dst_len + 1) < dstsize)
	{
		dst[j] = src[i];
		dstsize--;
		i++;
		j++;
	}	
	if (dstsize != 0 || dst_len > dstsize)
		dst[j] = '\0';
	if (dst_len > dstsize)
		return (dstsize + src_len);
	return (dst_len + src_len);
}
