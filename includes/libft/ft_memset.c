/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:30:05 by hmeriann          #+#    #+#             */
/*   Updated: 2021/05/12 16:42:09 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*end;

	tmp = (unsigned char *)s;
	end = (unsigned char *)(s + n);
	while (tmp < end)
	{
		*tmp = c;
		tmp++;
	}
	return (s);
}
