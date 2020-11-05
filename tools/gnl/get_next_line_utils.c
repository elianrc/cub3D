/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:29:11 by erc               #+#    #+#             */
/*   Updated: 2020/06/25 10:09:10 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strnew(size_t size)
{
	return (ft_calloc((size + 1) * sizeof(char)));
}

void		*ft_calloc(size_t size)
{
	char	*pt;

	pt = malloc(size);
	if (pt == NULL)
		return (NULL);
	ft_memset(pt, 0, size);
	return (pt);
}

void		*ft_memset(void *s, int c, size_t n)
{
	unsigned	char	*ub;

	ub = (unsigned char *)s;
	while (n > 0)
	{
		*ub = c;
		n--;
		ub++;
	}
	return (s);
}

int			ft_memdel(void **ptr)
{
	if (*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
