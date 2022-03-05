/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:46:15 by hmeriann          #+#    #+#             */
/*   Updated: 2021/05/12 17:14:53 by hmeriann         ###   ########.fr       */
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
		tmp_s++, i++;
	}
	return (NULL);
}
