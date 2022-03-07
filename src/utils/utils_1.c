/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:57:31 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/07 13:27:10 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
