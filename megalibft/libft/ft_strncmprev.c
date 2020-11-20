/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmprev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:24:10 by erc               #+#    #+#             */
/*   Updated: 2020/11/19 20:10:59 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmprev(const char *s1, const char *s2, size_t n)
{
	int	len1;
	int len2;

	if (n == 0)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (s1[len1] == s2[len2] && *s1 && *s2 && n--)
	{
		len1--;
		len2--;
	}
	return ((unsigned char)s1[len1] - (unsigned char)s2[len2]);	
}
