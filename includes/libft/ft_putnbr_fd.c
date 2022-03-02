/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:46:06 by jbasmati          #+#    #+#             */
/*   Updated: 2021/09/05 16:46:07 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		razr;
	int		numb;
	char	res;

	if (n == 2147483647)
		ft_putstr_fd("2147483647", fd);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
		}
		razr = ft_razr_counter(n);
		while (razr > 0)
		{
			numb = n / ft_pow(razr);
			n = n - numb * ft_pow(razr);
			res = numb + '0';
			write(fd, &res, 1);
			razr--;
		}
	}
}
