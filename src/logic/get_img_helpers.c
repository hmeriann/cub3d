/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:37:04 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/07 14:37:05 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_put_pixel(t_data *img, int row, int col, int color)
{
	char	*dst;

	dst = img->addr + (row * img->llen + col * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_put_row(t_data *img, int row, int color)
{
	unsigned int	*dst;
	int				i;

	i = 0;
	dst = (unsigned int *)(img->addr + row * img->llen);
	while (i < img->p->res_x)
		dst[i++] = color;
}

int	ft_get_pixel(t_texture *xpm, int row_sp, float diff)
{
	int	*color;

	color = (int *)(xpm->addr + xpm->llen * row_sp
			+ (xpm->bpp / 8) * (int)(xpm->w * diff));
	return (*color);
}
