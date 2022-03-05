<<<<<<< HEAD
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:28:01 by hmeriann          #+#    #+#             */
/*   Updated: 2021/05/12 22:18:08 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;

	i = 0;
	while (s1 && s2 && ((unsigned char)s1[i] == (unsigned char)s2[i]) \
	&& i < n && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
||||||| 6a4d3fc
=======
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
>>>>>>> origin/logic
