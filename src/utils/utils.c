/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:28:42 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/07 14:28:43 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_abs(int a)
{
	if (a > 0)
		return (a);
	return (-a);
}

float	ft_dist(float a, float b)
{
	return (sqrt(a * a + b * b));
}

void	ft_rotate_ange(double *x, double *y, double sin_a, double cos_a)
{
	double	copy_x;

	copy_x = *x;
	*x = copy_x * cos_a - *y * sin_a;
	*y = copy_x * sin_a + *y * cos_a;
}
