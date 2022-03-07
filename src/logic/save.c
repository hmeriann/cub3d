/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:28:07 by hmeriann          #+#    #+#             */
/*   Updated: 2022/03/07 13:28:08 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d.h"

/*
**	@brief	Get the pixel img object
**
**	@param	img		the mlx instance
**	@param	row		the row index
**	@param	col		the column index
**	@return	int		color im TRGB format
*/
int	get_pixel_img(t_data *img, int row, int col)
{
	int	*color;

	color = (int *)(img->addr + img->llen * row
			+ (img->bpp / 8) * col);
	return (*color);
}

/*
**	@brief	put img to bmp file
**
**	@param	img		the mlx instance
**	@param	fd		the bmp file descriptor
*/
void	ft_bmp_put_pixels(t_data *img, int fd)
{
	int	row;
	int	col;
	int	color;

	row = img->p->res_y;
	while (row--)
	{
		col = -1;
		while (++col < img->p->res_x)
		{
			color = get_pixel_img(img, row, col);
			write(fd, &color, 3);
		}
		write(fd, "\0\0\0", col % 4);
	}
}
