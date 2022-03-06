/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 18:50:32 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/06 18:50:44 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_param		p;
	t_data		img;
	t_player	plr;
	t_button	btn;

	parcer(argc, argv, &p);
	if (p.save)
	{	
		ft_init_n_textures(&img, &p);
		ft_vector_make(&img, &p);
		ft_player_init(&img, &p, &plr);
		ft_draw(&p, &img);
		ft_bmp_create(&img);
		exit(0);
	}
	ft_buttons_n_window(&img, &btn, &p);
	ft_textures_1(&img, &p);
	ft_resol_check(&p, &img);
	ft_vectors_make(&img, &p);
	ft_player_init(&img, &p, &plr);
	mlx_hook(img.win, 2, 1L << 0, press_button, &img);
	mlx_hook(img.win, 3, 1L << 1, release_button, &img);
	mlx_hook(img.win, 17, 1L << 1, close_win, &img);
	mlx_loop_hook(img.mlx, main_game, &img);
	mlx_loop(img.mlx);
}
