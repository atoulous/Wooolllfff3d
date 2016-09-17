/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:15:54 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/17 17:41:17 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		get_xmax(char *line)
{
	int		i;

	i = 0;
	while (*line++)
		i++;
	return (i);
}

void	find_start(t_var *var)
{
	int		i;
	int		j;

	POS_X = 0;
	POS_Y = 0;
	j = -1;
	while (++j < YMAX)
	{
		i = -1;
		while (++i < XMAX)
			if (TAB[j][i] == 'S')
			{
				!POS_X ? POS_X = j : 0;
				!POS_Y ? POS_Y = i : 0;
				TAB[j][i] = 'P';
			}
	}
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
}

void	free_tab(t_var *var)
{
	int		i;

	i = -1;
	while (TAB[++i])
		free(TAB[i]);
	free(TAB);
	free(MAP);
	mlx_destroy_image(MLX, IMG);
	MLX = NULL;
	WIN = NULL;
	IMG = NULL;
	free(var->ray);
	free(var);
}
