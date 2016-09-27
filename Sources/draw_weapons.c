/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_weapons.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 14:32:07 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/26 14:58:41 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		draw_ak47(t_var *var)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = WIDTH_WIN / 2;
	j = 0;
	while (++x < WIDTH_WIN)
	{
		y = HEIGHT_WIN / 3 * 2;
		i = 0;
		while (++y < HEIGHT_WIN)
		{
			PX = i * WEAPONSIZELINE + j * (BPP / 8);
			FIRE == 0 ? COLOR = AKDATA[PX] + AKDATA[PX + 1] * 256 +
				AKDATA[PX + 2] * 65536 : 0;
			FIRE == 1 ? COLOR = AKFDATA[PX] + AKFDATA[PX + 1] * 256 +
				AKFDATA[PX + 2] * 65536 : 0;
			if (COLOR != 0x000000)
				fill_image(var, x, y, COLOR);
			i++;
		}
		j++;
	}
	return (0);
}

int		draw_usp(t_var *var)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = WIDTH_WIN / 3 * 2;
	j = -1;
	while (++x < WIDTH_WIN && ++j < GUNX)
	{
		y = HEIGHT_WIN / 6 * 4;
		i = -1;
		while (++y < HEIGHT_WIN && ++i < GUNX)
		{
			PX = i * GUNSIZELINE + j * (BPP / 8);
			COLOR = USPDATA[PX] + USPDATA[PX + 1] * 256 +
				USPDATA[PX + 2] * 65536;
			if (COLOR != 0x000000)
				fill_image(var, x, y, COLOR);
		}
	}
	return (0);
}

int		draw_knife(t_var *var)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = WIDTH_WIN / 4;
	j = 0;
	while (++x < WIDTH_WIN / 4 * 3)
	{
		y = HEIGHT_WIN / 3 * 2;
		i = 0;
		while (++y < HEIGHT_WIN)
		{
			PX = i * KNIFESIZELINE + j * (BPP / 8);
			COLOR = KNIFEDATA[PX] + KNIFEDATA[PX + 1] * 256 +
				KNIFEDATA[PX + 2] * 65536;
			if (COLOR != 0x000000)
				fill_image(var, x, y, COLOR);
			i++;
		}
		j++;
	}
	return (0);
}

int		draw_he(t_var *var)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = WIDTH_WIN / 8 * 5;
	j = 0;
	while (++x < WIDTH_WIN || j < KNIFEX)
	{
		y = HEIGHT_WIN / 3 * 2;
		i = 0;
		while (++y < HEIGHT_WIN)
		{
			PX = i * KNIFESIZELINE + j * (BPP / 8);
			COLOR = HEDATA[PX] + HEDATA[PX + 1] * 256 +
				HEDATA[PX + 2] * 65536;
			if (COLOR != 0x000000)
				fill_image(var, x, y, COLOR);
			i++;
		}
		j++;
	}
	return (0);
}

int		draw_c4(t_var *var)
{
	int		x;
	int		y;
	int		i;
	int		j;

	x = WIDTH_WIN / 4;
	j = 0;
	while (++x < WIDTH_WIN / 4 * 3)
	{
		y = HEIGHT_WIN / 3 * 2;
		i = 0;
		while (++y < HEIGHT_WIN)
		{
			PX = i * KNIFESIZELINE + j * (BPP / 8);
			COLOR = C4DATA[PX] + C4DATA[PX + 1] * 256 +
				C4DATA[PX + 2] * 65536;
			if (COLOR != 0x000000)
				fill_image(var, x, y, COLOR);
			i++;
		}
		j++;
	}
	return (0);
}
