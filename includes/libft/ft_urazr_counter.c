/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_urazr_counter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:46:43 by jbasmati          #+#    #+#             */
/*   Updated: 2021/09/05 16:46:44 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_urazr_counter(unsigned int n)
{
	long long int	t;
	int				razr;

	t = 1;
	razr = 0;
	if (n < 0)
		n *= -1;
	if (n == 0)
		razr = 1;
	while (n / t >= 1)
	{		
		t = t * 10;
		razr++;
	}
	return (razr);
}
