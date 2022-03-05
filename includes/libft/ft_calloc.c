/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:44:54 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/05 16:21:51 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)malloc(nmemb * size);
	if (res == NULL)
		return (res);
	while (i < nmemb * size)
	{
		res[i] = '\0';
		i++;
	}
	return ((void *)res);
}
