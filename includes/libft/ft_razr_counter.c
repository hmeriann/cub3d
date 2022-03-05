/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_razr_counter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:46:11 by jbasmati          #+#    #+#             */
/*   Updated: 2021/09/05 16:46:12 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_razr_counter(long long int n)
{
	long long int	t;
	int				razr;
	long long int	n1;

	n1 = n;
	t = 1;
	razr = 0;
	if (n1 < 0)
		n1 *= -1;
	if (n1 == 0)
		razr = 1;
	while (n1 / t >= 1)
	{
		t = t * 10;
		razr++;
	}
	return (razr);
}
