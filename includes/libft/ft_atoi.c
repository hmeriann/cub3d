/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:44:38 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/05 16:21:58 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int	ft_atoi(const char *str)
{
	int			i;
	long long	res;	
	int			minus;

	i = 0;
	res = 0;
	minus = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' || str[i] == '\f' \
			|| str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = 1;
		i++;
	}	
	while (str[i] >= '0' && str[i] <= '9')
	{		
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (minus)
		res = res * (-1);
	return (res);
}
