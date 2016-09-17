/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_wolf3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 18:35:25 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/17 18:16:21 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	drawcursor(t_var *var)
{
	int		i;

	i = WIDTH_WIN / 2 - 10;
	while (++i < WIDTH_WIN / 2 + 10)
		fill_image(var, i, HEIGHT_WIN / 2, 0xFF0000);
	i = HEIGHT_WIN / 2 - 10;
	while (++i < HEIGHT_WIN / 2 + 10)
		fill_image(var, WIDTH_WIN / 2, i, 0xFF0000);
}

void	draw_skybox(t_var *var, int x)
{
	int		px;

	Y1 = -1;
	while (++Y1 < DRAWSTART)
	{
		px = Y1 * SKYSIZELINE + x * (BPP / 8);
		if (DIR_Y < 0)
			COLOR = SKYFRONTDATA[px] + SKYFRONTDATA[px + 1] * 256
			+ SKYFRONTDATA[px + 2] * 65536;
		if (DIR_Y > 0)
			COLOR = SKYBACKDATA[px] + SKYBACKDATA[px + 1] * 256
			+ SKYBACKDATA[px + 2] * 65536;
		if (DIR_X < 0)
			COLOR = SKYLEFTDATA[px] + SKYLEFTDATA[px + 1] * 256
			+ SKYLEFTDATA[px + 2] * 65536;
		if (DIR_X > 0)
			COLOR = SKYRIGHTDATA[px] + SKYRIGHTDATA[px + 1] * 256
			+ SKYRIGHTDATA[px + 2] * 65536;
		fill_image(var, x, Y1, COLOR);
	}
}

int		launch_wolf3d(t_var *var)
{
	int		x;

	x = -1;
	while (++x <= WIDTH_WIN)
	{
		wall_raycasting(var, x);
		draw_skybox(var, x);
		floor_raycasting(var, x);
	}
	drawcursor(var);
	ft_moves(var);
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}
