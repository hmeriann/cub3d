/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:45:21 by jbasmati          #+#    #+#             */
/*   Updated: 2022/02/20 13:01:09 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*str_filling(char *str, int start_symb, int razr, long int n)
{
	long long int	numb;

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

char	*n_int_max_checker(char *res, int n)
{
	res = (char *)malloc(sizeof(char) * (10 + 1));
	if (res == 0)
		return (NULL);
	res = str_filling(res, 0, 10, n);
	return (res);
}

char	*n_int_min_checker(char *res, int n)
{
	res = (char *)malloc(sizeof(char) * (10 + 1));
	if (res == 0)
		return (NULL);
	res = str_filling(res, 1, 10, n);
	return (res);
}

char	*ft_itoa(long long int n)
{
	char	*res;

	res = "";
	if (n == 2147483647)
		res = n_int_max_checker(res, n);
	else if (n == -2147483647 - 1)
		res = n_int_min_checker(res, n);
	else
	{
		if (n < 0)
		{
			res = (char *)malloc(sizeof(char) * (ft_razr_counter(n) + 1 + 1));
			if (res == 0)
				return (NULL);
			res = str_filling(res, 1, ft_razr_counter(n), n);
		}
		else
		{
			res = (char *)malloc(sizeof(char) * (ft_razr_counter(n) + 1));
			if (res == 0)
				return (NULL);
			res = str_filling(res, 0, ft_razr_counter(n), n);
		}
	}
	return (res);
}
