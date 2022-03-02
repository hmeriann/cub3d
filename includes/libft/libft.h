/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:46:57 by jbasmati          #+#    #+#             */
/*   Updated: 2022/01/20 10:25:09 by zu               ###   ########.fr       */
/*   Updated: 2022/01/17 19:12:58 by jbasmati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include "get_next_line.h"

typedef struct s_llist
{
	void			*content;
	struct s_llist	*next;
	struct s_llist	*prev;
}					t_llist;

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *arr, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcpy(const char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack, \
							const char *needle, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
long long int	ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(char c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(long long int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_isspace(int c);
int				ft_pow(int t);
int				ft_razr_counter(long long int n);
char			*ft_utoa(unsigned int n);
int				ft_urazr_counter(unsigned int n);
/*libft Linkedlist functions*/
void			ft_lstadd_back(t_llist **lst, t_llist *new);
void			ft_lstadd_front(t_llist **lst, t_llist *new);
void			ft_lstclear(t_llist **lst, void (*del)(void *));
void			ft_lstdelone(t_llist *lst, void (*del)(void *));
void			ft_lstiter(t_llist *lst, void (*f)(void *));
t_llist			*ft_lstlast(t_llist *lst);
t_llist			*ft_lstmap(t_llist *lst, void *(*f)(void *), \
					void (*del)(void *));
t_llist			*ft_lstnew(void *content);
int				ft_lstsize(t_llist *lst);
int				ft_strcmp(const char *s1, const char *s2);

char			*ft_strcat(char *dst, char *src);
#endif
