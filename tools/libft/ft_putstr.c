/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:30:32 by erc               #+#    #+#             */
/*   Updated: 2020/11/05 11:28:42 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int    ft_putstr(char *str)
{
    int total_written;

    total_written = 0;
    if (!str)
		return (0);
    while (*str)
	{
		ft_putchar_fd(*str, 1);
		str++;
        total_written++;
	}
    return (total_written);
}