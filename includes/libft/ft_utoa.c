/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:46:46 by jbasmati          #+#    #+#             */
/*   Updated: 2021/09/05 16:46:47 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ustr_filling(char *str, int start_symb, int razr, long int n)
{
	long int	numb;

	if (start_symb == 1)
	{
		str[0] = '-';
		n *= -1;
	}
	while (razr > 0)
	{
		numb = n / ft_pow(razr);
		n = n - numb * ft_pow(razr);
		str[start_symb] = numb + '0';
		start_symb++;
		razr--;
	}
	str[start_symb] = '\0';
	return (str);
}

char	*n_uint_max_checker(char *res, unsigned int n)
{
	res = (char *)malloc(sizeof(char) * (10 + 1));
	if (res == 0)
		return (NULL);
	res = ustr_filling(res, 0, 10, n);
	return (res);
}

char	*ft_utoa(unsigned int n)
{
	char	*res;

	res = "";
	if (n == 4294967295)
		res = n_uint_max_checker(res, n);
	else
	{
		if (n < 0)
			res = ft_itoa(4294967295 - n);
		else
		{
			res = (char *)malloc(sizeof(char) * (ft_urazr_counter(n) + 1));
			if (res == 0)
				return (NULL);
			res = ustr_filling(res, 0, ft_urazr_counter(n), n);
		}
	}
	return (res);
}
