/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:08:32 by zu                #+#    #+#             */
/*   Updated: 2022/03/07 13:17:58 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_create_map(t_p *p)
{
	int		i;
	t_list	*l_item;

	p->map_width += 2;
	p->map_height += 2;
	p->map = malloc(sizeof(*p->map) * p->map_height);
	if (!p->map)
		ft_print_error("Malloc error\n");
	i = 0;
	l_item = p->lst_map;
	while (i < p->map_height)
	{
		p->map[i] = ft_calloc(p->map_width, sizeof(**p->map));
		if (!p->map[i])
			ft_print_error("Malloc error\n");
		if (i != 0 && i != (p->map_height - 1))
		{
			ft_strlcpy(p->map[i] + 1, l_item->content, p->map_width);
			l_item = l_item->next;
		}
		i++;
	}
	ft_lstclear(&p->lst_map, free);
	if (!p->pers_x)
		ft_print_error("Personage start position is not set\n");
}

static int	is_hole(char **map, int i, int j)
{
	return ((!map[i + 1][j] || map[i + 1][j] == ' ' \
		|| !map[i - 1][j] || map[i - 1][j] == ' ' || !map[i][j + 1] \
		|| map[i][j + 1] == ' ' || !map[i][j - 1] || \
		map[i][j - 1] == ' ' || !map[i + 1][j + 1] || \
		map[i + 1][j + 1] == ' ' || !map[i + 1][j - 1] \
		|| map[i + 1][j - 1] == ' ' || !map[i - 1][j + 1] \
		|| map[i - 1][j + 1] == ' ' || !map[i - 1][j - 1] \
		|| map[i - 1][j - 1] == ' '));
}

void	ft_check_holes(t_p *p)
{
	int	i;
	int	j;

	i = 1;
	while (i < p->map_height)
	{
		j = 1;
		while (j < p->map_width)
		{
			if (mini_strchr("0WENS", p->map[i][j]) && is_hole(p->map, i, j))
				ft_print_error("There is hole in the map\n");
			j++;
		}
		i++;
	}
}
