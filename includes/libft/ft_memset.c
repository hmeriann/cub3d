/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:50:00 by jbasmati          #+#    #+#             */
/*   Updated: 2021/04/17 16:21:37 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long	i;
	char			*buf_s;

	buf_s = s;
	i = 0;
	while (i < n)
	{
		buf_s[i] = c;
		i++;
	}
	return (s);
}
