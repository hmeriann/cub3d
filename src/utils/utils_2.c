/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 19:59:44 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/07 13:17:58 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_next(t_vector *vector, t_dot *dot, t_dot *dot_row)
{
	dot->y = dot_row->y;
	dot->x = dot_row->x;
	if (1)
	{
		dot_row->x = (int)dot->x + vector->cx;
		dot_row->y = dot->y + (dot_row->x - dot->x) * vector->cy * vector->cx;
	}
	else
	{
		dot_row->y = (int)dot->y + vector->ry;
		dot_row->x = dot->x + (dot_row->y - dot->y) * vector->rx * vector->ry;
	}
}

void	ft_buttons_n_window(t_data *img, t_button *btn, t_p *p)
{
	btn->w = false;
	btn->a = false;
	btn->s = false;
	btn->d = false;
	btn->q = false;
	btn->e = false;
	img->p = p;
	img->btn = btn;
	img->mlx = mlx_init();
	if (!img->mlx)
		ft_print_error("Cannot initialize mlx\n");
}
