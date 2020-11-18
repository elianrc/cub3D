/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 13:29:15 by erc               #+#    #+#             */
/*   Updated: 2020/06/18 23:39:14 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	ssize_t		rv;
	char		buff[BUFFER_SIZE + (rv = 1)];
	static char	*stastr = NULL;
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	stastr == NULL ? stastr = ft_strnew(0) : NULL;
	while (!ft_strchr(stastr, '\n') && (rv = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[rv] = '\0';
		temp = ft_strjoin(stastr, buff);
		ft_memdel((void **)&stastr);
		stastr = temp;
	}
	if (rv == 0)
		*line = ft_strdup(stastr);
	else if (rv > 0)
		*line = ft_substr(stastr, 0, (ft_strchr(stastr, '\n') - stastr));
	else
		return (-1);
	temp = ft_strdup(stastr + (ft_strlen(*line) + ((rv > 0) ? +1 : +0)));
	ft_memdel((void **)&stastr);
	stastr = temp;
	return (rv == 0 ? 0 * ft_memdel((void **)&stastr) : 1);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	ssize_t	i;

	new = ft_strnew(ft_strlen(s));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		new[i] = s[i];
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != (char)c)
		if (!s[i++])
			return (NULL);
	return ((char *)&s[i]);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL || !(ptr = (char *)malloc(ft_strlen(s1)
					+ ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(const char *s, unsigned int beg, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (*s == '\0' || (long int)len < 0)
		return (NULL);
	if (!(ptr = (char *)malloc(len + 1)))
		return (NULL);
	while (beg < ft_strlen(s) && i < len)
		ptr[i++] = s[beg++];
	ptr[i] = '\0';
	return (ptr);
}
