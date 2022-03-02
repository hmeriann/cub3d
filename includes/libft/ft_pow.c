/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:45:58 by jbasmati          #+#    #+#             */
/*   Updated: 2021/09/05 16:45:59 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_pow(int t)
{
	long int	res;

	res = 1;
	while (t > 0)
	{
		res *= 10;
		t--;
	}
	res = res / 10;
	return (res);
}
