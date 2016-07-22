/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 11:34:04 by atoulous          #+#    #+#             */
/*   Updated: 2016/07/20 15:39:02 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_refresh_image(t_var *var)
{
	int		x;
	int		y;

	x = -1;
	while (++x < WIDTH_WIN)
	{
		y = -1;
		while (++y < HEIGHT_WIN)
			fill_image(var, x, y, 0x0);
	}
}

int		get_xmax(char *line)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] != ' ' && line[i])
		{
			c++;
			while (line[i] != ' ' && line[i])
				i++;
		}
	}
	return (c);
}

void	parse_map(t_var *var, int fd)
{
	char	*line;

	YMAX = 0;
	MAP = ft_strnew(BUFF_SIZE);
	while (get_next_line(fd, &line))
	{
		!XMAX ? XMAX = get_xmax(line) : 0;
		if (XMAX != get_xmax(line) || !XMAX)
			return (ft_exit(1));
		MAP = ft_strjoinfree(MAP, line);
		MAP = ft_strjoinfree(MAP, "\n");
		free(line);
		YMAX++;
	}
	TAB = ft_strsplit(MAP, '\n');
	free(MAP);
}

void	free_tab(t_var *var)
{
	int		i;

	i = -1;
	while (TAB[++i])
		free(TAB[i]);
	free(TAB);
	mlx_destroy_image(MLX, IMG);
	MLX = NULL;
	WIN = NULL;
	IMG = NULL;
	free(var->ray);
	free(var);
}
