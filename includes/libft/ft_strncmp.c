/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:44:02 by jbasmati          #+#    #+#             */
/*   Updated: 2021/04/21 19:48:00 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long	i;
	int				res;
	unsigned char	*buf_s1;
	unsigned char	*buf_s2;

	i = 0;
	buf_s1 = (unsigned char *)s1;
	buf_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if (buf_s1[i] != buf_s2[i] || buf_s1[i] == '\0' || buf_s2[i] == '\0')
		{					
			res = buf_s1[i] - buf_s2[i];
			return (res);
		}
		i++;
	}
	return (0);
}
