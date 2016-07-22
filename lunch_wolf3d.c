/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_wolf3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 18:35:25 by atoulous          #+#    #+#             */
/*   Updated: 2016/07/21 20:34:57 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_raycasting(t_var *var)
{
	POS_X = 2;
	POS_Y = 2;
	DIR_X = -1;
	DIR_Y = 0;
	PLANE_X = 0;
	PLANE_Y = 0.66;
	TIME = 0;
	OLDTIME = 0;
	HEIGHT_CAM = HEIGHT_WALL / 2;
	HIT = 0;
}

void	calc_step(t_var *var)
{
	if (RAYDIR_X < 0)
	{
		STEP_X = -1;
		SIDEDIST_X = (RAYPOS_X - MAP_X) * DELTADIST_X;
	}
	else
	{
		STEP_X = 1;
		SIDEDIST_X = (RAYPOS_X + 1.0 - RAYPOS_X) * DELTADIST_X;
	}
	if (RAYDIR_Y < 0)
	{
		STEP_Y = -1;
		SIDEDIST_Y = (RAYPOS_Y - MAP_Y) * DELTADIST_Y;
	}
	else
	{
		STEP_Y = 1;
		SIDEDIST_Y = (MAP_Y + 1.0 - RAYPOS_Y) * DELTADIST_Y;
	}
}

void	perform_dda(t_var *var)
{
	while (HIT == 0)
	{
		if (SIDEDIST_X < SIDEDIST_Y)
		{
			SIDEDIST_X += DELTADIST_X;
			MAP_X += STEP_X;
			SIDE = 0;
		}
		else
		{
			SIDEDIST_Y += DELTADIST_Y;
			MAP_Y += STEP_Y;
			SIDE = 1;
		}
		if (TAB[MAP_X][MAP_Y] > 0)
			HIT = 1;
	}
}

void	wall_color(t_var *var)
{
	if (TAB[MAP_X][MAP_Y])
		COLOR = 0xFFFFFF;
	if (SIDE == 1)
		COLOR = 0xFF0000;
	fill_image(var, DRAWSTART, DRAWEND, COLOR);
}

int		launch_wolf3d(t_var *var)
{
	int		x;
	double	w;

	init_raycasting(var);
	x = -1;
	w = WIDTH_WIN;
	while (++x < w)
	{
		CAM_X = 2 * x / (w - 1);
		RAYPOS_X = POS_X;
		RAYPOS_Y = POS_Y;
		RAYDIR_X = DIR_X + PLANE_X * CAM_X;
		RAYDIR_Y = DIR_Y + PLANE_Y * CAM_X;
		MAP_X = (int)RAYPOS_X;
		MAP_Y = (int)RAYPOS_Y;
		DELTADIST_X = sqrt(1 + (RAYDIR_Y *RAYDIR_Y) / (RAYDIR_X * RAYDIR_X));
		DELTADIST_Y = sqrt(1 + (RAYDIR_X *RAYDIR_X) / (RAYDIR_Y * RAYDIR_Y));
		calc_step(var);
		perform_dda(var);
		if (SIDE == 0)
			PERPWALLDIST = (MAP_X - RAYPOS_X + (1 - STEP_X) / 2) / RAYPOS_X;
		else
			PERPWALLDIST = (MAP_Y - RAYPOS_Y + (1 - STEP_Y) / 2) / RAYDIR_Y;
		LINEHEIGHT = (int)(H / PERPWALLDIST);
		DRAWSTART = -LINEHEIGHT / 2 + H / 2;
		if (DRAWSTART < 0)
			DRAWSTART = 0;
		DRAWEND = LINEHEIGHT / 2 + H / 2;
		if (DRAWEND >= H)
			DRAWEND = H - 1;
		wall_color(var);
	}
	OLDTIME = TIME;
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	//mlx_destroy_image(MLX, IMG);
	return (0);
}
