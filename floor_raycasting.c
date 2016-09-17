/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 13:09:02 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/17 20:06:39 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	calc_directions(t_var *var)
{
	if (SIDE == 0 && RAYDIR_X > 0)
	{
		var->floor->floorwallx = MAP_X;
		var->floor->floorwally = MAP_Y + WALLX;
	}
	else if (SIDE == 0 && RAYDIR_X < 0)
	{
		var->floor->floorwallx = MAP_X + 1.0;
		var->floor->floorwally = MAP_Y + WALLX;
	}
	else if (SIDE == 1 && RAYDIR_Y > 0)
	{
		var->floor->floorwallx = MAP_X + WALLX;
		var->floor->floorwally = MAP_Y;
	}
	else
	{
		var->floor->floorwallx = MAP_X + WALLX;
		var->floor->floorwally = MAP_Y + 1.0;
	}
	var->floor->distwall = PERPWALLDIST;
	var->floor->distplayer = 0.0;
	if (DRAWEND < 0)
		DRAWEND = HEIGHT_WIN;
}

void	calc_floortex(t_var *var)
{
	flo->currentdist = HEIGHT_WIN / (2.0 * DRAWEND - HEIGHT_WIN);
	flo->weight = (flo->currentdist - flo->distplayer) / (flo->distwall -
			flo->distplayer);
	flo->currentfloorx = flo->weight * flo->floorwallx + (1.0 - flo->weight)
		* POS_X;
	flo->currentfloory = flo->weight * flo->floorwally + (1.0 - flo->weight)
		* POS_Y;
	flo->floortexx = (int)(flo->currentfloorx * ROADX) % ROADX;
	flo->floortexy = (int)(flo->currentfloory * ROADX) % ROADX;
}

void	draw_ceil(t_var *var, int x)
{
	if (TAB[(int)flo->currentfloorx][(int)flo->currentfloory] == 'P'
			|| TAB[(int)flo->currentfloorx][(int)flo->currentfloory] == 'p')
	{
		COLOR = ROADDATA[PX] + ROADDATA[PX + 1] * 256 + ROADDATA[PX + 2]
			* 65536;
		COLOR = (COLOR >> 1) & 8355711;
		fill_image(var, x, DRAWEND, COLOR);
		COLOR = CEILDATA[PX] + CEILDATA[PX + 1] * 256 + CEILDATA[PX + 2]
			* 65536;
		COLOR = (COLOR >> 1) & 8355711;
		fill_image(var, x, HEIGHT_WIN - DRAWEND, COLOR);
	}
}

void	draw_floor(t_var *var, int x)
{
	if (TAB[(int)flo->currentfloorx][(int)flo->currentfloory] == 'R')
		COLOR = ROADDATA[PX] + ROADDATA[PX + 1] * 256 + ROADDATA[PX + 2]
			* 65536;
	if (TAB[(int)flo->currentfloorx][(int)flo->currentfloory] == 'r')
		COLOR = ROADHDATA[PX] + ROADHDATA[PX + 1] * 256 + ROADHDATA[PX + 2]
			* 65536;
	if (TAB[(int)flo->currentfloorx][(int)flo->currentfloory] == 'a')
		COLOR = ROADADATA[PX] + ROADADATA[PX + 1] * 256 + ROADADATA[PX + 2]
			* 65536;
	if (TAB[(int)flo->currentfloorx][(int)flo->currentfloory] == 'q')
		COLOR = ROADBDATA[PX] + ROADBDATA[PX + 1] * 256 + ROADBDATA[PX + 2]
			* 65536;
	if (TAB[(int)flo->currentfloorx][(int)flo->currentfloory] == '0')
		COLOR = SANDDATA[PX] + SANDDATA[PX + 1] * 256 + SANDDATA[PX + 2]
			* 65536;
}

void	floor_raycasting(t_var *var, int x)
{
	calc_directions(var);
	while (++DRAWEND < HEIGHT_WIN)
	{
		calc_floortex(var);
		PX = flo->floortexy * ROADSIZELINE + flo->floortexx * (BPP / 8);
		draw_floor(var, x);
		fill_image(var, x, DRAWEND, COLOR);
		draw_ceil(var, x);
	}
}
