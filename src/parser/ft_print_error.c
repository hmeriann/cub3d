/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 17:19:16 by zu                #+#    #+#             */
/*   Updated: 2022/03/07 13:17:58 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_print_error(char *s)
{
	ft_putstr_fd("Error\n", 2);
	if (s)
		ft_putstr_fd(s, 2);
	else
		perror(NULL);
	exit (1);
}
