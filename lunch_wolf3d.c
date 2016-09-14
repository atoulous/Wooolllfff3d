/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch_wolf3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 18:35:25 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/14 21:17:13 by atoulous         ###   ########.fr       */
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
		if (TAB[MAP_X][MAP_Y] != '0')
			HIT = 1;
	}
}

void	drawskybox(t_var *var, int x)
{
	int		px;

	Y1 = 0;
	Y2 = HEIGHT_WIN;
	while (Y1 < Y2)
	{
		px = Y1 * SKYSIZELINE + x * (BPP / 8);
		if ((DIR_X > -1) && (DIR_Y < 0))
			COLOR = SKYFRONTDATA[px] + SKYFRONTDATA[px + 1] * 256
			+ SKYFRONTDATA[px + 2] * 65536;
		if ((DIR_X >= 0) && (DIR_Y > 0))
			COLOR = SKYBACKDATA[px] + SKYBACKDATA[px + 1] * 256
			+ SKYBACKDATA[px + 2] * 65536;
		if ((DIR_X < 0) && (DIR_Y >= 0))
			COLOR = SKYLEFTDATA[px] + SKYLEFTDATA[px + 1] * 256
			+ SKYLEFTDATA[px + 2] * 65536;
		if ((DIR_X > 0) && (DIR_Y >= 0))
			COLOR = SKYRIGHTDATA[px] + SKYRIGHTDATA[px + 1] * 256
			+ SKYRIGHTDATA[px + 2] * 65536;
		fill_image(var, x, Y1++, COLOR);
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
	if (TAB[MAP_X][MAP_Y] == '5')
		COLOR = AUTOMATDATA[px] + AUTOMATDATA[px + 1] * 256 + AUTOMATDATA[px + 2] * 65536;
	//if (TAB[MAP_X][MAP_Y] == '9')
	//	COLOR = OIMDATA[px] + OIMDATA[px + 1] * 256 + OIMDATA[px + 2]
	//		* 65536;
}

void	drawfloor(t_var *var, int x)
{
	double	floorwallx;
	double	floorwally;
	double	distwall;
	double	distplayer;
	double	currentdist;
	double	weight;
	double	currentfloorx;
	double	currentfloory;
	int		floortexx;
	int		floortexy;

	if (SIDE == 0 && RAYDIR_X > 0)
	{
		floorwallx = MAP_X;
		floorwally = MAP_Y + WALLX;
	}
	else if (SIDE == 0 && RAYDIR_X < 0)
	{
		floorwallx = MAP_X + 1.0;
		floorwally = MAP_Y + WALLX;
	}
	else if (SIDE == 1 && RAYDIR_Y > 0)
	{
		floorwallx = MAP_X + WALLX;
		floorwally = MAP_Y;
	}
	else
	{
		floorwallx = MAP_X + WALLX;
		floorwally = MAP_Y + 1.0;
	}
	distwall = PERPWALLDIST;
	distplayer = 0.0;
	if (DRAWEND < 0)
		DRAWEND = HEIGHT_WIN;
	while (++DRAWEND < HEIGHT_WIN)
	{
		currentdist = HEIGHT_WIN / (2.0 * DRAWEND - HEIGHT_WIN);
		weight = (currentdist - distplayer) / (distwall - distplayer);
		currentfloorx = weight * floorwallx + (1.0 - weight) * POS_X;
		currentfloory = weight * floorwally + (1.0 - weight) * POS_Y;
		floortexx = (int)(currentfloorx * ROADX) % ROADX;
		floortexy = (int)(currentfloory * ROADX) % ROADX;
		PX = (ROADX * floortexy + floortexx);
		COLOR = ROADDATA[PX] + ROADDATA[PX + 1] * 256 + ROADDATA[PX + 2] * 65536;
		fill_image(var, x, DRAWEND, COLOR);
	}
}

void	drawline(t_var *var, int x)
{
	int				px;
	int				textx;

	Y1 = DRAWSTART;
	Y2 = DRAWEND;
	LINE = Y2 - Y1;
	while (Y1 <= Y2)
	{
		if (SIDE == 0)
			WALLX = RAYPOS_Y + PERPWALLDIST * RAYDIR_Y;
		else
			WALLX = RAYPOS_X + PERPWALLDIST * RAYDIR_X;
		WALLX -= floor(WALLX);
		textx = (int)(WALLX * (double)(TEXTX));
		if ((SIDE == 0 && RAYDIR_X > 0) || (SIDE == 1 && RAYDIR_Y < 0))
			textx = (TEXTX - textx - 1);
		px = ((int)((I++ + (LINEHEIGHT - LINE) / 2) * TEXTX / LINEHEIGHT
						* TEXTSIZELINE) + textx * (BPP / 8));
		color_textures(var, px);
		SIDE == 1 ? COLOR = (COLOR >> 1) & 8355711 : 0;
		fill_image(var, x, Y1++, COLOR);
	}
	drawfloor(var, x);
	/*while (++DRAWEND < HEIGHT_WIN)
	{
		px = DRAWEND * SKYSIZELINE + x * (BPP / 8);
		COLOR = OIMDATA[px] + OIMDATA[px + 1] * 256
			+ OIMDATA[px + 2] * 65536;
		fill_image(var, x, DRAWEND, COLOR);
	}*/
}

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
void	raycasting(t_var *var, int x)
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
	DRAWSTART = HEIGHT_WIN / 2 - LINEHEIGHT / 2;
	DRAWSTART < 0 ? DRAWSTART = 0 : 0;
	DRAWEND = LINEHEIGHT / 2 + HEIGHT_WIN / 2;
	DRAWEND >= HEIGHT_WIN ? DRAWEND = HEIGHT_WIN - 1 : 0;
}

int		launch_wolf3d(t_var *var)
{
	int		x;

	x = -1;
	while (++x <= WIDTH_WIN)
	{
		drawskybox(var, x);
		raycasting(var, x);
		I = 0;
		drawline(var, x);
	}
	drawcursor(var);
	OLDTIME = TIME;
	mlx_put_image_to_window(MLX, WIN, IMG, 0, 0);
	return (0);
}
