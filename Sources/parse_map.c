/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:15:54 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/26 15:39:13 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
				!POS_X ? POS_X = j + 0.5 : 0;
				!POS_Y ? POS_Y = i + 0.5 : 0;
				TAB[j][i] = 'P';
			}
	}
	!POS_X || !POS_Y ? ft_exit(3) : 0;
}

int		get_xmax(char *line)
{
	int		i;

	i = 0;
	while (*line++)
		i++;
	return (i);
}

void	parse_map(t_var *var, int fd)
{
	char	*line;

	YMAX = 0;
	MAP = ft_strnew(BUFF_SIZE);
	while (get_next_line(fd, &line))
	{
		if (XMAX < get_xmax(line))
			XMAX = get_xmax(line);
		MAP = ft_strjoinfree(MAP, line);
		MAP = ft_strjoinfree(MAP, "\n");
		free(line);
		YMAX++;
	}
	!XMAX ? ft_exit(1) : 0;
	TAB = ft_strsplit(MAP, '\n');
}
