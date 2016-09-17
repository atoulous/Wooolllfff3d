/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 13:04:43 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/17 20:10:58 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
		SIDEDIST_X = (MAP_X + 1.0 - RAYPOS_X) * DELTADIST_X;
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
	HIT = 0;
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
		if (TAB[MAP_X][MAP_Y] != '0' && TAB[MAP_X][MAP_Y] != 'R'
				&& TAB[MAP_X][MAP_Y] != 'r' && TAB[MAP_X][MAP_Y] != 'a'
				&& TAB[MAP_X][MAP_Y] != 'q' && TAB[MAP_X][MAP_Y] != 'P'
				&& TAB[MAP_X][MAP_Y] != 'p')
			HIT = 1;
	}
}

void	color_textures(t_var *var, int px)
{
	if (TAB[MAP_X][MAP_Y] == '1')
		COLOR = WALLDATA[px] + WALLDATA[px + 1] * 256 + WALLDATA[px + 2]
			* 65536;
	if (TAB[MAP_X][MAP_Y] == 'F')
		COLOR = WINWALLDATA[px] + WINWALLDATA[px + 1] * 256 +
			WINWALLDATA[px + 2] * 65536;
	if (TAB[MAP_X][MAP_Y] == 'D' || TAB[MAP_X][MAP_Y] == 'd')
		COLOR = DOORWALLDATA[px] + DOORWALLDATA[px + 1] * 256 +
			DOORWALLDATA[px + 2] * 65536;
	if (TAB[MAP_X][MAP_Y] == '3')
		COLOR = GLASSDATA[px] + GLASSDATA[px + 1] * 256 +
			GLASSDATA[px + 2] * 65536;
	if (TAB[MAP_X][MAP_Y] == 'B')
		COLOR = BOXDATA[px] + BOXDATA[px + 1] * 256 + BOXDATA[px + 2]
			* 65536;
	if (TAB[MAP_X][MAP_Y] == 'b')
		COLOR = METALBOXDATA[px] + METALBOXDATA[px + 1] * 256 +
			METALBOXDATA[px + 2] * 65536;
	if (TAB[MAP_X][MAP_Y] == 'A' || TAB[MAP_X][MAP_Y] == 'T')
		COLOR = AUTOMATDATA[px] + AUTOMATDATA[px + 1] * 256 +
			AUTOMATDATA[px + 2] * 65536;
	if (TAB[MAP_X][MAP_Y] == 'M')
		COLOR = OIMDATA[px] + OIMDATA[px + 1] * 256 + OIMDATA[px + 2]
			* 65536;
}

void	draw_wall(t_var *var, int x)
{
	int				texx;
	int				texy;
	int				d;

	Y1 = DRAWSTART;
	while (Y1 <= DRAWEND)
	{
		if (SIDE == 0)
			WALLX = RAYPOS_Y + PERPWALLDIST * RAYDIR_Y;
		else
			WALLX = RAYPOS_X + PERPWALLDIST * RAYDIR_X;
		WALLX -= floor(WALLX);
		texx = (int)(WALLX * (double)(TEXTX));
		if ((SIDE == 0 && RAYDIR_X > 0) || (SIDE == 1 && RAYDIR_Y < 0))
			texx = (TEXTX - texx - 1);
		d = Y1 * 256 - HEIGHT_WIN * 128 + LINEHEIGHT * 128;
		texy = ((d * TEXTX) / LINEHEIGHT) / 256;
		PX = (texy * TEXTSIZELINE) + texx * (BPP / 8);
		color_textures(var, PX);
		SIDE == 1 ? COLOR = (COLOR >> 1) & 8355711 : 0;
		fill_image(var, x, Y1++, COLOR);
	}
}

void	wall_raycasting(t_var *var, int x)
{
	CAM_X = 2 * x / (double)WIDTH_WIN - 1;
	RAYPOS_X = POS_X;
	RAYPOS_Y = POS_Y;
	RAYDIR_X = DIR_X + PLANE_X * CAM_X;
	RAYDIR_Y = DIR_Y + PLANE_Y * CAM_X;
	MAP_X = (int)RAYPOS_X;
	MAP_Y = (int)RAYPOS_Y;
	DELTADIST_X = sqrt(1 + (RAYDIR_Y * RAYDIR_Y) / (RAYDIR_X * RAYDIR_X));
	DELTADIST_Y = sqrt(1 + (RAYDIR_X * RAYDIR_X) / (RAYDIR_Y * RAYDIR_Y));
	calc_step(var);
	perform_dda(var);
	if (SIDE == 0)
		PERPWALLDIST = (MAP_X - RAYPOS_X + (1 - STEP_X) / 2) / RAYDIR_X;
	else
		PERPWALLDIST = (MAP_Y - RAYPOS_Y + (1 - STEP_Y) / 2) / RAYDIR_Y;
	LINEHEIGHT = HEIGHT_WIN / PERPWALLDIST;
	DRAWSTART = (HEIGHT_WIN / 2) - (LINEHEIGHT / 2);
	DRAWSTART < 0 ? DRAWSTART = 0 : 0;
	DRAWEND = (HEIGHT_WIN / 2) + (LINEHEIGHT / 2);
	DRAWEND >= HEIGHT_WIN ? DRAWEND = HEIGHT_WIN - 1 : 0;
	draw_wall(var, x);
}
