/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:18:57 by hmeriann          #+#    #+#             */
/*   Updated: 2021/05/12 17:19:46 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*добавляет элемент в конец списка*/

t_list	*ft_lstnew(void *content)
{
	t_list	*lstnew_element;

	lstnew_element = (t_list *)malloc(sizeof(t_list));
	if (lstnew_element == NULL)
		return (NULL);
	lstnew_element -> content = content;
	lstnew_element -> next = NULL;
	return (lstnew_element);
}
