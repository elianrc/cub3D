/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 20:51:08 by erc               #+#    #+#             */
/*   Updated: 2020/06/28 20:51:09 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# ifndef FD_SIZE
#  define FD_SIZE 65535
# endif

# include <stdlib.h>
# include <unistd.h>

int			get_next_line(const int fd, char **line);
int			ft_memdel(void **ptr);
char		*ft_strnew(size_t size);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_substr(const char *s, unsigned int beg, size_t len);
void		*ft_calloc(size_t size);
void		*ft_memset(void *s, int c, size_t n);
size_t		ft_strlen(const char *s);

#endif
