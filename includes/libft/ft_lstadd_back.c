/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:18:21 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/16 17:28:05 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* получает указатель на указатель на начало списка
и указатель на новый элемент, добавляет его в конец списка */

void	ft_lstadd_back(t_llist **lst, t_llist *new)
{
	t_llist	*last;

	if (new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last -> next = new;
		new->prev = last;
	}
}
