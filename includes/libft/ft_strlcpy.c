/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:46:25 by jbasmati          #+#    #+#             */
/*   Updated: 2021/09/05 16:46:26 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	i;
	unsigned int	n;

	if (src == 0)
		return (0);
	i = 0;
	n = 0;
	while (src[n])
		n++;
	if (dstsize > 0)
	{
		dstsize--;
		while (i < dstsize && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (n);
}
