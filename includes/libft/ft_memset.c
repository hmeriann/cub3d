/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:50:00 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/05 16:20:45 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
