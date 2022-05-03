/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:57:04 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/07 14:57:34 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_game(t_data *img)
{
	ft_view(img->p, img->plr, img->btn);
	ft_pos(img->p->map, img->plr, img->btn, img->v);
	draw_floor_and_cel(img->p, img);
	ft_draw_walls(img->p, img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_do_sync(img->mlx);
	return (0);
}
