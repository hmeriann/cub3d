#include "../../include/cub3d.h"

/*
**	@brief	registration game's hooks
**
**	@param	img		the mlx instance
*/
void	run_game(t_data *img)
{
	mlx_hook(img->win, 2, 1L << 0, ft_button, img);
	mlx_hook(img->win, 3, 1L << 1, ft_release_button, img);
	mlx_hook(img->win, 17, 1L << 1, ft_win_close, img);
	mlx_loop_hook(img->mlx, main_game, img);
	mlx_loop(img->mlx);
}

/*
**	@brief	main loop game. change view and position player. then draw screen
**
**	@param	img		the mlx instance
**	@return	int		0 if no error
*/
int	main_game(t_data *img)
{
	ft_view(img->p, img->plr, img->btn);
	ft_pos(img->p->map, img->plr, img->btn, img->v);
	draw_floor_and_cel(img->p, img);
	ft_draw_walls(img->p, img);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	mlx_do_sync(img->mlx);
	return (0);
}

