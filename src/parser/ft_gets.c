/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:54:46 by zu                #+#    #+#             */
/*   Updated: 2022/03/06 22:48:11 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_rgb(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!ft_digits(arr[i]))
			return (0);
		i++;
	}
	i = 0;
	while (arr[i])
	{
		if (ft_strlen(arr[i]) > 3 || ft_strlen(arr[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	rec_color(int transpar, int red, int green, int black)
{
	return (transpar << 24 | red << 16 | green << 8 | black);
}

static void	save_fc(t_p *p, int *color, bool is_floor)
{
	if (is_floor)
	{
		if (p->floor != -1)
			ft_print_error("Floor color is already set\n");
		p->floor = rec_color(0, color[0], color[1], color[2]);
	}
	else
	{
		if (p->ceiling !=-1)
			ft_print_error("Ceiling color is already set\n");
		p->ceiling = rec_color(0, color[0], color[1], color[2]);
	}
}

void	ft_get_fc(t_p *p, char *line, bool is_floor)
{
	char	**arr;
	char	*cutted;
	int		i;
	int		color[3];

	cutted = ft_strtrim(line, " ");
	arr = ft_split(cutted, ',');
	i = 0;
	while (arr[i])
		i++;
	if(i != 3 || !is_rgb(arr) || ft_count_chars(line, ",") != 2)
		ft_print_error("Invalid setting for the floor or the ceiling\n");
	i = -1;
	while (++i < 3)
		color[i] = ft_atoi(arr[i]);
	if (color[0] > 255 || color[1] > 255 || color[2] > 255)
		ft_print_error("Color code should be between 0 and 255\n");
	save_fc(p, color, is_floor);
	free(cutted);
	ft_free_split(arr);
}