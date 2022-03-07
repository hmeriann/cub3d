/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 16:50:54 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/07 14:36:53 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_line_make_1(t_data *img, t_dot *dot_row, t_dot *dot_col, \
						t_vector *vect)
{
	int		max_cross;
	t_dot	dot;

	max_cross = 256;
	while (max_cross && img->plr->cnt_s < 200)
	{
		if (ft_dist(dot_row->x - img->plr->x, dot_row->y - img->plr->y)
			< ft_dist(dot_col->x - img->plr->x, dot_col->y - img->plr->y))
		{
			ft_next(vect, &dot, dot_row);
			if (check_cell_x(img, vect, &dot, &img->plr->cnt_s))
				break ;
		}
		else
		{
			ft_next(vect, &dot, dot_row);
			if (check_cell_y(img, vect, &dot, &img->plr->cnt_s))
				break ;
			max_cross--;
		}
	}
}

void	ft_line_make(t_data *img, t_vector vect, t_p *p)
{
	int		col;
	float	k;
	int		i;
	t_dot	dot_row;
	t_dot	dot_col;

	col = 0;
	img->plr->cnt_s = 0;
	dot_row.x = (int)img->plr->x + (vect.cx > 0);
	dot_row.y = img->plr->y + (dot_row.x - img->plr->x)
		* vect.cy * vect.cx;
	dot_col.y = (int)img->plr->y + (vect.ry > 0);
	dot_col.x = img->plr->x + (dot_col.y - img->plr->y)
		* vect.rx * vect.ry;
	ft_line_make_1(img, &dot_row, &dot_col, &vect);
	k = img->v[ft_abs(p->res_x / 2 - col)].x;
	i = img->plr->cnt_s;
	img->plr->sprite[i - 1].h /= k;
}

void	ft_pixel_make(t_data *img, int row, int col, int color)
{
	char	*dst;

	dst = img->addr + (row * img->llen + col * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	ft_pix_draw(t_data *img, int down, t_texture *xpm, int row_sp)
{
	int	i;
	int	up;
	int	col;
	int	color;

	i = 0;
	up = ft_max(0, down);
	col = 0;
	color = ft_get_pixel(xpm, row_sp, img->plr->sprite[img->plr->cnt_s].diff);
	down = ft_min(img->p->res_y, (img->p->res_y - \
		img->plr->sprite[img->plr->cnt_s].h) / 2
			+ (row_sp + 1) * img->plr->sprite[img->plr->cnt_s].h / xpm->h);
	if (down >= 0 && up < img->p->res_y
		&& (i + 1 == img->plr->cnt_s
			|| img->plr->sprite[img->plr->cnt_s].h / 2 < img->p->res_y)
		&& (color != TRNS))
	{
		while (up < down)
		{
			ft_pixel_make(img, up++, col, color);
			up++;
		}
	}
}
