/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_wolf3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 18:35:25 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/22 19:38:52 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	fill_image(t_var *var, int x, int y, int color)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = color >> 0;
	g = color >> 8;
	b = color >> 16;
	if (x >= 0 && x < WIDTH_WIN && y >= 0 && y < HEIGHT_WIN)
	{
		DATA[y * SIZELINE + x * (BPP / 8)] = r;
		DATA[y * SIZELINE + x * (BPP / 8) + 1] = g;
		DATA[y * SIZELINE + x * (BPP / 8) + 2] = b;
		if (C & (1 << 7))
			DATA[y * SIZELINE + x * (BPP / 8) + 3] = 150;
		else
			DATA[y * SIZELINE + x * (BPP / 8) + 3] = 0;
	}
}

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
	int		i;
	int		j;

	i = -1;
	while (++i < TEXTX)
	{
		j = -1;
		while (++j < TEXTX)
		{
			PX = j * TEXTSIZELINE + i * (BPP / 8);
			COLOR = RADARDATA[PX] + RADARDATA[PX + 1] * 256 +
				RADARDATA[PX + 2] * 65536;
			if (COLOR != 0x000000)
				fill_image(var, i, j, COLOR);
		}
	}
}

void	draw_skybox(t_var *var, int x)
{
	int		px;

	Y1 = -1;
	while (++Y1 < DRAWSTART)
	{
		px = Y1 * SKYSIZELINE + x * (BPP / 8);
		if (DIR_X < -0.5 && DIR_X < DIR_Y)
			COLOR = SKYFRONTDATA[px] + SKYFRONTDATA[px + 1] * 256
			+ SKYFRONTDATA[px + 2] * 65536;
		else if (DIR_X > 0.5)
			COLOR = SKYBACKDATA[px] + SKYBACKDATA[px + 1] * 256
			+ SKYBACKDATA[px + 2] * 65536;
		else if (DIR_Y < 0.5 && DIR_Y < DIR_X)
			COLOR = SKYLEFTDATA[px] + SKYLEFTDATA[px + 1] * 256
			+ SKYLEFTDATA[px + 2] * 65536;
		else if (DIR_Y > 0.5 && DIR_Y > DIR_X)
			COLOR = SKYRIGHTDATA[px] + SKYRIGHTDATA[px + 1] * 256
			+ SKYRIGHTDATA[px + 2] * 65536;
		fill_image(var, x, Y1, COLOR);
	}
}

void	display_menu(t_var *var)
{
	int		px;
	int		x;
	int		y;
	int		color;

	x = -1;
	while (++x < WIDTH_WIN)
	{
		y = -1;
		while (++y < HEIGHT_WIN)
		{
			px = y * SKYSIZELINE + x * (BPP / 8);
			color = MENUDATA[px] + MENUDATA[px + 1] * 256
			+ MENUDATA[px + 2] * 65536;
			fill_image(var, x, y, color);
		}
	}
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
}

int		launch_wolf3d(t_var *var)
{
	int		x;

	if (M == 1)
		display_menu(var);
	else
	{
		x = -1;
		while (++x <= WIDTH_WIN)
		{
			wall_raycasting(var, x);
			draw_skybox(var, x);
			floor_raycasting(var, x);
		}
		draw_cursor(var);
		draw_radar(var);
		draw_weapons(var);
		ft_moves(var);
		mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	}
	FIRE = 0;
	D & (1 << 5) ? D ^= (1 << 5) : 0;
	D & (1 << 4) ? D ^= (1 << 4) : 0;
	return (0);
}
