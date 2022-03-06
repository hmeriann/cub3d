/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:54:57 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/05 19:57:04 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_player_init(t_data *img, t_param *p, t_player *plr)
{
	img->plr = plr;
	plr->x = p->plr_x + 0.5;
	plr->y = p->plr_y + 0.5;
	plr->z = 0;
	plr->rotate_speed = p->cnt_v * PLR_ROTATE_SPEED / 180;
	plr->speed = PLR_SPEED;
	if (p->map[p->plr_y][p->plr_x] == 'E')
		plr->ind_v = 0;
	else if (p->map[p->plr_y][p->plr_x] == 'S')
		plr->ind_v = p->cnt_v / 4;
	else if (p->map[p->plr_y][p->plr_x] == 'W')
		plr->ind_v = p->cnt_v / 2;
	else
		plr->ind_v = p->cnt_v * 3 / 4;
	plr->vx = img->v[plr->ind_v].x;
	plr->vy = img->v[plr->ind_v].y;
	if (DEBUG)
		printf("Start pos x=%f, y=%f, rotate_speed=%d\n ind=%d\n",
			plr->vx, plr->vy, plr->rotate_speed, plr->ind_v);
}

void	ft_rotate(t_data *img, double sin_step, double cos_step, int i)
{
	double	copy_x;

	img->v[i].x = img->v[i - 1].x;
	img->v[i].y = img->v[i - 1].y;
	copy_x = img->v[i].x;
	img->v[i].x = copy_x * cos_step - img->v[i].y * sin_step;
	img->v[i].y = copy_x * sin_step + img->v[i].y * cos_step;
	img->v[i].cx = 1 - 2 * (img->v[i].x < 0);
	img->v[i].cy = img->v[i].y / img->v[i].x * img->v[i].cx;
	img->v[i].ry = 1 - 2 * (img->v[i].y < 0);
	img->v[i].rx = img->v[i].x / img->v[i].y * img->v[i].ry;
}

void	ft_vector_make(t_data *img, t_param *p)
{
	int		i;
	double	sin_step;
	double	cos_step;

	p->cnt_v = ft_max(360, p->res_x * 6);
	sin_step = sin(M_PI * 2 / p->cnt_v);
	cos_step = cos(M_PI * 2 / p->cnt_v);
	img->v = malloc(sizeof(*img->v) * p->cnt_v * 1.21);
	if (!img->v)
		ft_raise_error("Allocation error\n");
	i = 0;
	img->v[i].x = 1;
	img->v[i].y = 0;
	while (i < p->cnt_v * 1.2)
	{
		ft_rotate(img, sin_step, cos_step, i);
		i++;
	}
}

void	ft_textures(t_data *img, t_texture *xpm, t_param *p, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (!ft_strncmp(p->xpm[i], p->xpm[j], ft_strlen(p->xpm[i]) + 1))
		{
			xpm[i] = xpm[j];
			continue ;
		}
		j++;
	}
	if (!ft_strncmp(p->xpm[i] + ft_strlen(p->xpm[i]) - 4, ".png", 4))
		ft_raise_error("png textures not supported\n");
	xpm[i].img = mlx_xpm_file_to_image(img->mlx, p->xpm[i],
			&xpm[i].w, &xpm[i].h);
	if (!xpm[i].img)
		ft_raise_error("Cannot read texture file\n");
	xpm[i].addr = mlx_get_data_addr(xpm[i].img, &xpm[i].bpp,
			&xpm[i].llen, &xpm[i].end);
}

void	ft_init_n_textures(t_data *img, t_param *p)
{
	int	i;

	i = 0;
	img->p = p;
	img->mlx = mlx_init();
	if (!img->mlx)
		ft_raise_error("Cannot initialize mlx\n");
	img->llen = p->res_x * 4;
	img->bpp = 32;
	img->addr = malloc(img->llen * p->res_y);
	if (!img->addr)
		ft_raise_error("Cannot allocate memory for img instance\n");
	while (i < 5)
	{
		ft_textures(img, img->xpm, p, i);
		i++;
	}
}
