/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:52:19 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/07 14:53:20 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_ray(t_data *img, t_vector vray)
{
	t_dot	dot;
	t_dot	dot_row;
	t_dot	dot_col;
	int		max_cross;

	ft_init_dots(img, &vray, &dot_row, &dot_col);
	max_cross = 256;
	while (--max_cross && img->plr->cnt_s < 200)
	{
		if (ft_dist(dot_row.x - img->plr->x, dot_row.y - img->plr->y)
			< ft_dist(dot_col.x - img->plr->x, dot_col.y - img->plr->y))
		{
			ft_next_cross(&vray, &dot, &dot_row, 1);
			if (ft_sell_x(img, &vray, &dot, &img->plr->cnt_s))
				break ;
		}
		else
		{
			ft_next_cross(&vray, &dot, &dot_col, 0);
			if (ft_cell_y(img, &vray, &dot, &img->plr->cnt_s))
				break ;
		}
	}
}

void	ft_init_dots(t_data *img, t_vector *vray,
		t_dot *dot_row, t_dot *dot_col)
{
	img->plr->cnt_s = 0;
	dot_row->x = (int)img->plr->x + (vray->cx > 0);
	dot_row->y = img->plr->y + (dot_row->x - img->plr->x)
		* vray->cy * vray->cx;
	dot_col->y = (int)img->plr->y + (vray->ry > 0);
	dot_col->x = img->plr->x + (dot_col->y - img->plr->y)
		* vray->rx * vray->ry;
}

void	ft_next_cross(t_vector *vray, t_dot *dot, t_dot *d, int is_row)
{
	dot->y = d->y;
	dot->x = d->x;
	if (is_row)
	{
		d->x = (int)dot->x + vray->cx;
		d->y = dot->y + (d->x - dot->x) * vray->cy * vray->cx;
	}
	else
	{
		d->y = (int)dot->y + vray->ry;
		d->x = dot->x + (d->y - dot->y) * vray->rx * vray->ry;
	}
}
