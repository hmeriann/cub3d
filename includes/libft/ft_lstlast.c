/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:18:48 by hmeriann          #+#    #+#             */
/*   Updated: 2022/03/05 16:21:13 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* передвигает начало списка вниз по списку и находит последний элемент списка*/

t_llist	*ft_lstlast(t_llist *lst)
{
	t_llist	*tmp;

	if (lst == NULL)
		return (NULL);
	tmp = lst;
	while (tmp -> next)
		tmp = tmp -> next;
	return (tmp);
}
