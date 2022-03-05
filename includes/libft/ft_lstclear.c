/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:18:34 by hmeriann          #+#    #+#             */
/*   Updated: 2022/03/05 16:21:23 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*удаляет указанный элемент и всех его последователей,
пока не станет указывать на NULL*/

void	ft_lstclear(t_llist **lst, void (*del)(void *))
{
	t_llist	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)-> next;
			ft_lstdelone(*lst, del);
			(*lst) = tmp;
		}
	}
}
