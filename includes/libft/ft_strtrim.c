/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:17:42 by hmeriann          #+#    #+#             */
/*   Updated: 2021/05/14 12:53:32 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	first_index(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	left_bound_finder(char const *s1, char const *set, int left)
{
	left = 0;
	while (s1[left] != '\0' && first_index(set, s1[left]) != -1)
		left++;
	return (left);
}

static int	right_bound_finder(char const *s1, char const *set, int right)
{
	right = ft_strlen(s1) - 1;
	while (right > 0 && first_index(set, s1[right]) != -1)
		right--;
	return (right);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		len_substr;
	int		left;
	int		right;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (*set == '\0')
		return (result = ft_strdup(s1));
	left = 0;
	right = 0;
	left = left_bound_finder(s1, set, left);
	right = right_bound_finder(s1, set, right);
	if (left > right)
		return (ft_strdup(""));
	len_substr = right - left + 1;
	result = malloc(sizeof(char) * (len_substr + 1));
	if (result == NULL)
		return (NULL);
	result = ft_substr(s1, left, len_substr);
	return (result);
}
