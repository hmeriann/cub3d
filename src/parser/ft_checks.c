/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:31:45 by zu                #+#    #+#             */
/*   Updated: 2022/03/05 19:09:59 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_check_map_line(t_p *p, char *line)
{
	int	i;

	if ((int)ft_strlen(line) > p->map_width)
		p->map_width = ft_strlen(line);
	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01 NWSE", line[i]))
			ft_print_error("Wrong character in the map\n");
		if (ft_strchr("NWSE", line[i]))
		{
			if (p->pers_x)
				ft_print_error("Double keys for start position\n");
			p->pers_x = i + 1;
			p->pers_y = p->map_height + 1;
		}
		i++;
	}
	p->map_height++;
	ft_lstadd_back(&p->lst_map, ft_lstnew(ft_strdup(line)));
}

void	ft_parse_line(t_p *p, char *line)
{
	
}