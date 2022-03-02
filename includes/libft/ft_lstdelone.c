/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:18:39 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/09 18:04:42 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_llist *lst, void (*del)(void *))
{
	if (NULL == lst)
		return ;
	if (del)
		del(lst -> content);
	free(lst);
}
