/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:46:38 by jbasmati          #+#    #+#             */
/*   Updated: 2021/09/05 16:46:39 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_s;

	i = 0;
	j = start;
	substr = "";
	if (s == 0)
		return (NULL);
	len_s = ft_strlen(s);
	substr = (char *)malloc(sizeof(*s) * (len + 1));
	if (substr == NULL)
		return (NULL);
	if (start < len_s)
	{
		while (i < len_s && j < len + start)
		{
			substr[i] = s[j];
			i++;
			j++;
		}
	}
	substr[i] = '\0';
	return (substr);
}
