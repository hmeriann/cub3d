/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:19:20 by hmeriann          #+#    #+#             */
/*   Updated: 2022/03/06 23:13:03 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_lst
{
	char	**str;
	int		char_count;
}t_lst;

int	ft_word_counter(char const *s, char c)
{
	int	i;
	int	word_counter;

	i = 0;
	word_counter = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == c)
				i++;
			else
			{
				word_counter++;
				while (s[i] && s[i] != c)
					i++;
			}
		}
		return (word_counter);
	}
	return (0);
}

char	*ft_mem_for_str_j(t_lst *list, int j)
{
	list->str[j] = (char *)malloc(list->char_count + 1);
	if (list->str[j] == NULL)
	{
		j--;
		while (j >= 0)
		{
			free(list->str[j]);
			j--;
		}
		free(list->str);
		return (NULL);
	}
	return (list->str[j]);
}

char	*str_j_filling(t_lst *list, int j, char const *s, int i)
{	
	int	k;

	k = 0;
	while (list->char_count > 0)
	{
		list->str[j][k] = s[i - list->char_count];
		list->char_count--;
		k++;
	}
	list->str[j][k] = '\0';
	k = 0;
	return (list->str[j]);
}

char	**ft_str_filling(char const *s, int i, char c, t_lst *list)
{
	int	j;

	list->char_count = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
			{
				list->char_count++;
				i++;
			}
			list->str[j] = ft_mem_for_str_j(list, j);
			list->str[j] = str_j_filling(list, j, s, i);
			j++;
			list->char_count = 0;
		}
	}
	list->str[j] = NULL;
	return (list->str);
}

char	**ft_split(char const *s, char c)
{
	t_lst	list;
	int		i;
	int		word_count;

	word_count = 0;
	list.str = NULL;
	i = 0;
	if (s)
	{
		word_count = ft_word_counter(s, c);
		if (word_count)
		{
			list.str = (char **)malloc(sizeof(char *) * (word_count + 1));
			if (list.str == NULL)
				return (NULL);
			list.str = ft_str_filling(s, i, c, &list);
			return (list.str);
		}
	}
	return (NULL);
}
