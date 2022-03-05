/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:18:57 by hmeriann          #+#    #+#             */
/*   Updated: 2022/03/05 16:21:07 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*добавляет элемент в конец списка*/

t_llist	*ft_lstnew(void *content)
{
	t_llist	*lstnew_element;

	lstnew_element = (t_llist *)malloc(sizeof(t_llist));
	if (lstnew_element == NULL)
		return (NULL);
	lstnew_element -> content = content;
	lstnew_element -> next = NULL;
	lstnew_element -> prev = NULL;
	return (lstnew_element);
}
