/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_analyse_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:34:56 by erc               #+#    #+#             */
/*   Updated: 2020/11/25 09:59:37 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TODO
// c3_analyze_texture();

// static int	c3_analyze_map(t_all *all, char *line)
// {
		
// }

static int	c3_analyze_resolution(t_all *all, char *line)
{
	line += ft_spaceskip(line);
	all->map.window_height = ft_atoi(line);
	while(ft_isdigit(*line))
		line++;
	line += ft_spaceskip(line);
	all->map.window_width = ft_atoi(line);
	return (0);
}

static int	c3_analyze_line(t_all *all, char *line)
{
	line += ft_spaceskip(line);
	if (*line == 'R')
		c3_analyze_resolution(all, ++line);
	return (0);
}

int	ft_analyze_map(t_all *all, char **argv)
{
	int fd;
	char *line;
	int rt;
	
	if ((fd = open(*argv, O_RDONLY)) == -1)
		return (-1);
	while ((rt = get_next_line(fd, &line)) > 0)
	{
		c3_analyze_line(all, line);
		free(line);
	}
	c3_analyze_line(all, line);
	ft_printf("Resolution X: %d\n", all->map.window_height);
	ft_printf("Resolution Y: %d\n", all->map.window_width);
	close(fd);
	return (0);
}