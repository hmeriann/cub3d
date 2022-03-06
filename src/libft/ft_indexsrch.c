/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexsrch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 17:48:01 by hmeriann          #+#    #+#             */
/*   Updated: 2022/03/06 23:13:44 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_indexsrch(const char *s, int c)
{
	const char	*tmp;
	int			index;

	tmp = s;
	index = 0;
	while (*tmp != '\0')
	{
		if (tmp[index] == (unsigned char)c)
			return (index);
		index++;
	}
	return (0);
}
