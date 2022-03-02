/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:19:01 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/09 18:05:27 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* считает количество элементов в листе. получает
указатель на голову и возврашает количество элементов*/

int	ft_lstsize(t_llist *lst)
{
	int		counter;
	t_llist	*tmp;

	counter = 0;
	if (lst == NULL)
		return (0);
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp -> next;
		counter++;
	}
	return (counter);
}
