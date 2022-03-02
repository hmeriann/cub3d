/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:45:32 by jbasmati          #+#    #+#             */
/*   Updated: 2021/09/05 16:45:33 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*buf_arr;
	unsigned char	buf_c;

	i = 0;
	buf_arr = (unsigned char *)arr;
	buf_c = (unsigned char)c;
	while (i < n)
	{
		if (buf_arr[i] == buf_c)
			return (&buf_arr[i]);
		i++;
	}
	return (NULL);
}
