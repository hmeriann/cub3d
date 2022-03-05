/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 21:56:43 by jbasmati          #+#    #+#             */
/*   Updated: 2022/03/02 22:56:37 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    parser(void)
{
	
}

t_p *ft_init(t_p *p, int argc, char **argv)
{
	p->argc = argc;
	p->argv = argv;
	return (p);
}

void    s_mode(t_p *p)
{
	if (p)
		;
}

int main(int argc, char **argv)
{
	t_p p;

	p = *ft_init(&p, argc, argv);
	parser();
	// if что-то там....  
	s_mode(&p);

	return (0);
}