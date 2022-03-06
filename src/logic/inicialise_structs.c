#include "include/cub3d.h"

/*
**	@brief	inicialise the button's structure
**	
**	@param	btn		the button's structure
*/
void	inicialise_buttons(t_button *btn)
{
	btn->w = false;
	btn->a = false;
	btn->s = false;
	btn->d = false;
	btn->q = false;
	btn->e = false;
}

/*
**	@brief	inicialises the player's structure
**	
**	@param	img		the mlx instance
**	@param	p		the structure of parameters
**	@param	plr		the player's structure
*/
void	initialise_player(t_data *img, t_p *p, t_player *plr)
{
	img->plr = plr;
	plr->x = p->pers_x + 0.5;
	plr->y = p->pers_y + 0.5;
	plr->z = 0;
	plr->rotate_speed = p->cnt_v * PLR_ROTATE_SPEED / 180;
	plr->speed = PLR_SPEED;
	if (p->map[p->pers_y][p->pers_x] == 'E')
		plr->ind_v = 0;
	else if (p->map[p->pers_y][p->pers_x] == 'S')
		plr->ind_v = p->cnt_v / 4;
	else if (p->map[p->pers_y][p->pers_x] == 'W')
		plr->ind_v = p->cnt_v / 2;
	else
		plr->ind_v = p->cnt_v * 3 / 4;
	plr->vx = img->v[plr->ind_v].x;
	plr->vy = img->v[plr->ind_v].y;
	if (DEBUG)
		printf("Start pos x=%f, y=%f, rotate_speed=%d\n ind=%d\n",
			plr->vx, plr->vy, plr->rotate_speed, plr->ind_v);
}
