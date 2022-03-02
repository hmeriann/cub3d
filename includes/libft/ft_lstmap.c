/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:18:52 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/09 18:05:07 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*шагает по листу и применяет функцию f к каждому элементу списка.
Из результата применения функции создает новый список.
Применяет функцию del, если необходимо*/

t_llist	*ft_lstmap(t_llist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_llist	*first_element;
	t_llist	*new_lst;

	if (!f)
		return (NULL);
	first_element = NULL;
	while (lst)
	{
		new_lst = ft_lstnew((*f)(lst -> content));
		if (!(new_lst))
		{
			while (first_element)
			{
				new_lst = first_element -> next;
				(*del)(first_element -> content);
				free(first_element);
				first_element = new_lst;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first_element, new_lst);
		lst = lst -> next;
	}
	return (first_element);
}
