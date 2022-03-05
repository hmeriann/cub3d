/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:45:37 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/05 16:20:53 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <math.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned long	i;
	int				res;

	i = 0;
	res = 0;
	while (i < n)
	{
		res = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		if (res != 0)
		{
			return (res);
		}
		else
			i++;
	}
	return (res);
}
