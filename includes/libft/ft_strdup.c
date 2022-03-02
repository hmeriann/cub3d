/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:46:18 by jbasmati          #+#    #+#             */
/*   Updated: 2022/01/21 00:30:31 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	if (s == NULL)
		len = 0;
	else
		len = ft_strlen(s);
	res = (char *)malloc(sizeof(const char) * (len + 1));
	if (res == NULL)
		return (res);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
