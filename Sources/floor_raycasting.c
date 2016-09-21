/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 13:09:02 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/20 15:46:50 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	calc_directions(t_var *var)
{
	if (SIDE == 0 && RAYDIR_X > 0)
	{
		FLO->floorwallx = MAP_X;
		FLO->floorwally = MAP_Y + WALLX;
	}
	else if (SIDE == 0 && RAYDIR_X < 0)
	{
		FLO->floorwallx = MAP_X + 1.0;
		FLO->floorwally = MAP_Y + WALLX;
	}
	else if (SIDE == 1 && RAYDIR_Y > 0)
	{
		FLO->floorwallx = MAP_X + WALLX;
		FLO->floorwally = MAP_Y;
	}
	else
	{
		FLO->floorwallx = MAP_X + WALLX;
		FLO->floorwally = MAP_Y + 1.0;
	}
	FLO->distwall = PERPWALLDIST;
	FLO->distplayer = 0.0;
	if (DRAWEND < 0)
		DRAWEND = HEIGHT_WIN;
}

void	calc_floortex(t_var *var)
{
	FLO->currentdist = HEIGHT_WIN / (2.0 * DRAWEND - HEIGHT_WIN);
	FLO->weight = (FLO->currentdist - FLO->distplayer) / (FLO->distwall -
			FLO->distplayer);
	FLO->currentfloorx = FLO->weight * FLO->floorwallx + (1.0 - FLO->weight)
		* POS_X;
	FLO->currentfloory = FLO->weight * FLO->floorwally + (1.0 - FLO->weight)
		* POS_Y;
	FLO->floortexx = (int)(FLO->currentfloorx * ROADX) % ROADX;
	FLO->floortexy = (int)(FLO->currentfloory * ROADX) % ROADX;
}

void	draw_ceil(t_var *var, int x)
{
	if (TAB[(int)FLO->currentfloorx][(int)FLO->currentfloory] == 'P'
			|| TAB[(int)FLO->currentfloorx][(int)FLO->currentfloory] == 'p'
			|| TAB[(int)FLO->currentfloorx][(int)FLO->currentfloory] == 'u')
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
	if (TAB[(int)FLO->currentfloorx][(int)FLO->currentfloory] == 'R')
		COLOR = ROADDATA[PX] + ROADDATA[PX + 1] * 256 + ROADDATA[PX + 2]
			* 65536;
	if (TAB[(int)FLO->currentfloorx][(int)FLO->currentfloory] == 'r')
		COLOR = ROADHDATA[PX] + ROADHDATA[PX + 1] * 256 + ROADHDATA[PX + 2]
			* 65536;
	if (TAB[(int)FLO->currentfloorx][(int)FLO->currentfloory] == 'a')
		COLOR = ROADADATA[PX] + ROADADATA[PX + 1] * 256 + ROADADATA[PX + 2]
			* 65536;
	if (TAB[(int)FLO->currentfloorx][(int)FLO->currentfloory] == 'q')
		COLOR = ROADBDATA[PX] + ROADBDATA[PX + 1] * 256 + ROADBDATA[PX + 2]
			* 65536;
	if (TAB[(int)FLO->currentfloorx][(int)FLO->currentfloory] == '0')
		COLOR = SANDDATA[PX] + SANDDATA[PX + 1] * 256 + SANDDATA[PX + 2]
			* 65536;
}

void	floor_raycasting(t_var *var, int x)
{
	calc_directions(var);
	while (++DRAWEND < HEIGHT_WIN)
	{
		calc_floortex(var);
		PX = FLO->floortexy * ROADSIZELINE + FLO->floortexx * (BPP / 8);
		draw_floor(var, x);
		fill_image(var, x, DRAWEND, COLOR);
		draw_ceil(var, x);
	}
}
