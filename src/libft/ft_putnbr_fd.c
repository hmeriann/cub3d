/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 14:24:30 by hmeriann          #+#    #+#             */
/*   Updated: 2021/04/28 14:58:37 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;

	i = n;
	if (i == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (i < 0 && i > -2147483648)
		{
			ft_putchar_fd('-', fd);
			i *= -1;
		}
		if (i > 9)
			ft_putnbr_fd(i / 10, fd);
		ft_putchar_fd(i % 10 + '0', fd);
	}
}
