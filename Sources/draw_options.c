/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:48:34 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/26 15:25:15 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_cursor(t_var *var)
{
	int		i;
	int		x;

	x = 0;
	i = WIDTH_WIN / 2 - 12;
	while (++i < WIDTH_WIN / 2 + 12)
	{
		x < 7 || x > 15 ? fill_image(var, i, HEIGHT_WIN / 2, 0xFFFF00) : 0;
		x++;
	}
	x = 0;
	i = HEIGHT_WIN / 2 - 12;
	while (++i < HEIGHT_WIN / 2 + 12)
	{
		x < 7 || x > 15 ? fill_image(var, WIDTH_WIN / 2, i, 0xFFFF00) : 0;
		x++;
	}
}

void	draw_radar(t_var *var)
{
	int		px;
	int		i;
	int		j;

	i = -1;
	while (++i < RADARX)
	{
		j = -1;
		while (++j < RADARX)
		{
			px = j * RADARSIZELINE + i * (BPP / 8);
			COLOR = RADARDATA[px] + RADARDATA[px + 1] * 256 +
				RADARDATA[px + 2] * 65536;
			if (COLOR != 0x000000)
				fill_image(var, i, j, COLOR);
		}
	}
}

void	draw_weapons(t_var *var)
{
	WEAPON == 1 ? draw_ak47(var) : 0;
	WEAPON == 2 ? draw_usp(var) : 0;
	WEAPON == 3 ? draw_knife(var) : 0;
	WEAPON == 4 ? draw_he(var) : 0;
	WEAPON == 5 ? draw_c4(var) : 0;
}

void	draw_options(t_var *var)
{
	draw_cursor(var);
	draw_radar(var);
	draw_weapons(var);
}
