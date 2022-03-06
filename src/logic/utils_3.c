/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:42:33 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/06 22:50:33 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_resol_check(t_p *p, t_data *img)
{
	// int	x;
	// int	y;

	// if (!p->save)
	// {
		// mlx_get_screen_size(&x, &y);
		// p->res_x = ft_min(x, p->res_x);
		// p->res_y = ft_min(y, p->res_y);
	// }	
	img->win = mlx_new_window(img->mlx, p->res_x, p->res_y, "Cub3D");
	if (!img->win)
		ft_print_error("Cannot create game windows\n");
	img->img = mlx_new_image(img->mlx, p->res_x, p->res_y);
	if (!img->img)
		ft_print_error("Cannot create new mlx_img\n");
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->llen, &img->end);
}

void	ft_vector_feel(t_data *img, double cos_step, \
						double sin_step, t_p *p)
{
	int		i;
	double	copy_x;

	i = 1;
	while (i < p->cnt_v * 1.2)
	{
		img->v[i].x = img->v[i - 1].x;
		img->v[i].y = img->v[i - 1].y;
		copy_x = img->v[i].x;
		img->v[i].x = copy_x * cos_step - img->v[i].y * sin_step;
		img->v[i].y = copy_x * sin_step + img->v[i].y * cos_step;
		img->v[i].cx = 1 - 2 * (img->v[i].x < 0);
		img->v[i].cy = img->v[i].y / img->v[i].x * img->v[i].cx;
		img->v[i].ry = 1 - 2 * (img->v[i].y < 0);
		img->v[i].rx = img->v[i].x / img->v[i].y * img->v[i].ry;
		i++;
	}
}

void	ft_vectors_make(t_data *img, t_p *p)
{
	int		i;
	double	sin_step;
	double	cos_step;

	i = 0;
	p->cnt_v = ft_max(360, p->res_x * 6);
	sin_step = sin(M_PI * 2 / p->cnt_v);
	cos_step = cos(M_PI * 2 / p->cnt_v);
	img->v = malloc(sizeof(*img->v) * p->cnt_v * 1.21);
	if (!img->v)
		ft_print_error("Allocation error\n");
	img->v[i].x = 1;
	img->v[i].y = 0;
	ft_vector_feel(img, cos_step, sin_step, p);
}

void	ft_textures_1(t_data *img, t_p *p)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < i)
		{
			if (!ft_strncmp(p->xpm[i], p->xpm[j], ft_strlen(p->xpm[i]) + 1))
			{
				img->xpm[i] = img->xpm[j];
				continue ;
			}
		}
		if (!ft_strncmp(p->xpm[i] + ft_strlen(p->xpm[i]) - 4, ".png", 4))
			ft_print_error("png textures not supported\n");
		img->xpm[i].img = mlx_xpm_file_to_image(img->mlx, p->xpm[i],
				&img->xpm[i].w, &img->xpm[i].h);
		if (!img->xpm[i].img)
			ft_print_error("Cannot read texture file\n");
		img->xpm[i].addr = mlx_get_data_addr(img->xpm[i].img, &img->xpm[i].bpp,
				&img->xpm[i].llen, &img->xpm[i].end);
	}
}
