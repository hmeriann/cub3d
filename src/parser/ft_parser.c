/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:22:24 by zu                #+#    #+#             */
/*   Updated: 2022/03/06 15:53:31 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

static int	validate_args(int argc, char **argv)
{
	int	fd;
	int	len;

	if (argc != 2)
		ft_print_error("Cub3D accepts one map as an argument\n");
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp(argv[1] + (len - 4), ".cub", 5))
		ft_print_error("Filename doesnt end with .cub\n");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_print_error(NULL);
	return(fd);
}

static void	init_settings(t_p *p)
{
	int	i;

	p->res_x = 0;
	p->res_y = 0;
	p->floor = -1;
	p->ceiling = -1;
	p->got_sets = false;
	p->end_map = 0;
	p->map_height = 0;
	p->map_width = 0;
	p->lst_map = NULL;
	p->pers_x = 0;
	p->pers_y = 0;
	i = -1;
	while (++i < 5)
		p->tex[i] = NULL;
}

static void	save_settings(t_p *p, int fd)
{
	char	*line;
	int		res;

	line = NULL;
	res = 1;
	while (res)
	{
		res = get_next_line(fd, &line);
		if (res < 0)
			ft_print_error(NULL);
		if ((ft_strlen(line) == 0) && p->map_height && !p->end_map)
			p->end_map = true;
		if (ft_strlen(line) > 0)
		{
			if (p->end_map)
				ft_print_error("Free space inside the map\n");
			if (p->got_sets)
				ft_check_map_line(p, line);
			else
				ft_parse_line(p, line);
		}
		free(line);
	}
}

int	ft_parser(t_p *p, int argc, char **argv)
{
	int	fd;

	fd = validate_args(argc, argv);
	init_settings(p);
	save_settings(p, fd);
	if (!p->got_sets || !p->map_height)
		ft_print_error("There is no color or texture settings or no map\n");
	ft_create_map(p);
	ft_check_holes(p);
	close(fd);
	return(0);
}