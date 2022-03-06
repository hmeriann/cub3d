/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:57:31 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/05 19:59:36 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_col_feel(t_data *img, int fd, int row)
{
	int	col;
	int	color;

	col = 0;
	while (row)
	{
		while (col < img->p->res_x)
		{
			color = get_pixel_img(img, row, col);
			write(fd, &color, 3);
			col++;
		}
		write(fd, "\0\0\0", col % 4);
		row--;
	}		
	close(fd);
	exit(0);
}

void	ft_bmp_create(t_data *img)
{
	int				fd;
	int				size;
	unsigned char	header[54];
	int				row;

	size = 54 + (img->p->res_x + (img->p->res_x + 1) % 4) * img->p->res_y * 3;
	fd = open("screenshot.bmp", O_WRONLY | O_CREAT
			| O_TRUNC, S_IRWXU);
	if (!fd)
		ft_raise_error("Can't create screenshot file\n");
	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	ft_put_int(header + 2, size);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	ft_put_int(header + 18, img->p->res_x);
	ft_put_int(header + 22, img->p->res_y);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	write(fd, header, 54);
	row = img->p->res_y;
	ft_col_feel(img, fd, row);
}
