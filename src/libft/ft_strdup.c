/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:38:09 by hmeriann          #+#    #+#             */
/*   Updated: 2021/04/27 16:48:52 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	dstsize;
	size_t	i;

	i = 0;
	dstsize = (ft_strlen(s1) + 1) * (sizeof(const char));
	dst = malloc(dstsize);
	if (dst == NULL)
		return (NULL);
	while (i < dstsize)
	{
		dst[i] = s1[i];
		i++;
	}
	return ((char *)dst);
}
