/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:46:36 by jbasmati          #+#    #+#             */
/*   Updated: 2021/09/05 16:48:10 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef struct s_list
{
	int	k;
	int	i;
	int	flag;
	int	j;
	int	len;
}t_list;

int	start_trim_count(char const *s1, char const *set)
{
	t_list	list;

	list.i = 0;
	list.k = 0;
	while (s1[list.i])
	{
		list.flag = 0;
		list.j = 0;
		while (set[list.j])
		{
			if (s1[list.i] == set[list.j])
			{
				list.k++;
				list.flag = 1;
				list.j = ft_strlen(set);
			}
			else
				list.j++;
		}
		if (list.flag == 1)
			list.i++;
		else
			list.i = ft_strlen(s1);
	}
	return (list.k);
}

int	end_trim_count(char const *s1, char const *set)
{
	t_list	list;

	list.len = ft_strlen(s1);
	list.k = 0;
	while (s1[list.len - 1])
	{
		list.flag = 0;
		list.j = 0;
		while (set[list.j])
		{
			if (s1[list.len - 1] == set[list.j])
			{
				list.k++;
				list.flag = 1;
				list.j = ft_strlen(set);
			}				
			else
				list.j++;
		}
		if (list.flag == 1)
			list.len--;
		else
			list.len = ft_strlen(s1) + 1;
	}
	return (list.k);
}

char	*res_eol(char	*res)
{
	res = (char *)malloc(1);
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*res;
	unsigned int	i;
	unsigned int	start_count;
	unsigned int	end_count;
	unsigned int	res_len;

	res = "";
	i = 0;
	if (!s1 || !set)
		return (NULL);
	start_count = start_trim_count(s1, set);
	end_count = end_trim_count(s1, set);
	if (start_count == ft_strlen(s1) || end_count == ft_strlen(s1))
		return (res_eol(res));
	res_len = ft_strlen(s1) - start_count - end_count;
	res = (char *)malloc(res_len + 1);
	if (res == NULL)
		return (NULL);
	while (s1[start_count] && start_count < res_len + start_trim_count(s1, set))
		res[i++] = s1[start_count++];
	res[i] = '\0';
	return (res);
}
