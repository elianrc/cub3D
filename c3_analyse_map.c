/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_analyse_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erc <erc@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:34:56 by erc               #+#    #+#             */
/*   Updated: 2020/11/24 21:18:25 by erc              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TODO
// c3_analyze_texture();
// c3_analyze_map();

static int	c3_analyze_resolution(t_all *all, char *line)
{
	ft_spaceskip(line);
	ft_printf("loc_1: |%c|\n", *line);
	// ft_printf("loc_12: |%c|\n", *line++);
	all->map.window_height = ft_atoi(line);
	ft_printf("loc_2: |%c|\n", *line);
	while(ft_isdigit(*line))
		line++;
	ft_printf("loc_22: |%c|\n", *line);
	ft_spaceskip(line);
	ft_printf("loc_3: |%c|\n", *line);
	all->map.window_width = ft_atoi(line);
	ft_printf("loc_4: |%c|\n", *line);
	return (0);
}

static int	c3_analyze_line(t_all *all, char *line)
{
	ft_spaceskip(line);
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