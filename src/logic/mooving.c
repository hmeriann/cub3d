/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mooving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:47:28 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/07 14:49:10 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_pos(char **map, t_player *plr, t_button *btn, t_vector *vs)
{
	float	row;
	float	col;

	row = plr->y;
	col = plr->x;
	if (btn->w && !btn->s)
		ft_forward(&vs[plr->ind_v], plr->speed, &row, &col);
	if (btn->s && !btn->w)
		ft_forward(&vs[plr->ind_v], -plr->speed, &row, &col);
	if (btn->a && !btn->d)
		ft_sideway(&vs[plr->ind_v], plr->speed, &row, &col);
	if (btn->d && !btn->a)
		ft_sideway(&vs[plr->ind_v], -plr->speed, &row, &col);
	ft_change(map, plr, row, col);
}

void	ft_view(t_p *p, t_player *plr, t_button *btn)
{
	if (btn->q && !btn->e)
		plr->ind_v -= plr->rotate_speed;
	if (btn->e && !btn->q)
		plr->ind_v += plr->rotate_speed;
	if (plr->ind_v >= p->cnt_v)
		plr->ind_v -= p->cnt_v;
	else if (plr->ind_v < 0)
		plr->ind_v += p->cnt_v;
}

void	ft_forward(t_vector *v, float speed, float *row, float *col)
{
	*row += v->y * speed;
	*col += v->x * speed;
}

void	ft_sideway(t_vector *v, float speed, float *row, float *col)
{
	*row -= v->x * speed;
	*col += v->y * speed;
}

void	ft_change(char **map, t_player *plr, float row, float col)
{
	int	row2;
	int	col2;

	row2 = (int)(plr->y + 2 * (row - plr->y));
	col2 = (int)(plr->x + 2 * (col - plr->x));
	if (map[(int)row][(int)col] != '1' && map[row2][col2] != '1'
		&& map[(int)plr->y][col2] != '1' && map[row2][(int)plr->x] != '1')
	{
		plr->y = row;
		plr->x = col;
	}
	else if (map[(int)row][(int)plr->x] != '1'
			&& map[row2][(int)plr->x] != '1')
		plr->y = row;
	else if (map[(int)plr->y][(int)col] != '1'
			&& map[(int)plr->y][col2] != '1')
		plr->x = col;
}
