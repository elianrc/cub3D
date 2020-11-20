/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 23:36:18 by erc               #+#    #+#             */
/*   Updated: 2020/11/19 20:25:09 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>

/*
**--------------- PART 1 - LIBC FUNCTIONS ---------------
**
**--- Memory Functions ---
*/
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				ft_swap(int *a, int *b);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t size);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_memdel(void **ptr);
/*
**--- String Manipulation && Examination Functions ---
*/
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(char *s1, char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strncmprev(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *big, const char *little,
		size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strdup(const char *s);
/*
**--- Other functions ---
*/
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isascii(int c);
int					ft_numdig(int n, int base);
/*
**--------------- PART 2 - ADDITIONAL FUNCTIONS ---------------
**
**--- String Manipulation && Examination Functions ---
*/
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_strnew(size_t size);
char				**ft_split(char const *s, char c);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/*
**--- Other Functions ---
*/
int					ft_isspace(int c);
int					ft_atoi(const char *nptr);
int					ft_atoi_base(const char *str, int base);
int					ft_putnchar(char c, int n);
int					ft_putstr(char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(int n, int base);
char				*ft_utoa(unsigned int n);
size_t				ft_wordcounter(char const *s, char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
/*
**-------------- BONUS PART - LINKED LIST FUNCTIONS -------------
*/
typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
			void (*del)(void *));
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));

#endif