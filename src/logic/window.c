/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:55:57 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/07 14:55:58 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_win_close(t_data *img)
{
	if (img->win)
		mlx_destroy_window(img->mlx, img->win);
	exit (0);
}
