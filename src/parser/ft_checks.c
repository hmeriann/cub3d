/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:31:45 by zu                #+#    #+#             */
/*   Updated: 2022/03/06 22:48:11 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_check_map_line(t_p *p, char *line)
{
	int	i;

	if ((int)ft_strlen(line) > p->map_width)
		p->map_width = ft_strlen(line);
	i = 0;
	while (line[i])
	{
		if (!ft_strchr("01 NWSE", line[i]))
			ft_print_error("Unknown key in the map\n");
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

void	ft_get_walls(t_p *p, char *line)
{
	if (!ft_strncmp(line, "NO ", 3) && !p->xpm[2])
		p->xpm[2] = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "SO ", 3) && !p->xpm[3])
		p->xpm[3] = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "WE ", 3) && !p->xpm[0])
		p->xpm[0] = ft_strdup(line + 3);
	else if (!ft_strncmp(line, "EA ", 3) && !p->xpm[1])
		p->xpm[1] = ft_strdup(line + 3);
	else
		ft_print_error("The texture is already set\n");
}

void	ft_parse_line(t_p *p, char *line)
{
	while (*line == '\t' || *line == ' ')
		line++;
	if (!ft_strncmp(line, "F ", 2) || !ft_strncmp(line, "C ", 2))
		ft_get_fc(p, line + 2, !ft_strncmp(line, "F ", 2));
	else if (!(ft_strncmp(line, "NO ", 3) && ft_strncmp(line, "SO ", 3) \
			&& ft_strncmp(line, "WE ", 3) && ft_strncmp(line, "EA ", 3)))
		ft_get_walls(p, line);
	else
		ft_print_error("Invalid settings for the wall testure\n");
	p->got_sets = (p->ceiling >= 0 && p->floor >= 0 \
		&& p->xpm[0] && p->xpm[1] && p->xpm[2] && p->xpm[3]);
}