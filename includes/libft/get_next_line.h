/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbasmati <jbasmati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:46:54 by jbasmati          #+#    #+#             */
/*   Updated: 2021/11/18 19:42:19 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		get_next_line(int fd, char **line);
char	*ft_strdup_gnl(const char *s);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		substr_mem_counter(unsigned int len_s, size_t len, unsigned int start);
int		super_func(char **remainder, char **line, int fd, char **buf);
void	*ft_free(char *str);
char	*remainder_joiner(int chr_count, char *buf, char *remainder);
int		chr_checker(int chr_count, char **remainder, char **line, char **buf);
int		remainder_creator(char **remainder, char **line, char *buf);
#endif
