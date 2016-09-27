/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 19:26:28 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/26 15:39:32 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		rotateright(t_var *var)
{
	double	olddirx;
	double	oldplanex;

	olddirx = DIR_X;
	DIR_X = DIR_X * cos(-ROTSPEED) - DIR_Y * sin(-ROTSPEED);
	DIR_Y = olddirx * sin(-ROTSPEED) + DIR_Y * cos(-ROTSPEED);
	oldplanex = PLANE_X;
	PLANE_X = PLANE_X * cos(-ROTSPEED) - PLANE_Y * sin(-ROTSPEED);
	PLANE_Y = oldplanex * sin(-ROTSPEED) + PLANE_Y * cos(-ROTSPEED);
	D & (1 << 4) ? D ^= (1 << 4) : 0;
	ROTSPEED = 0.1;
	return (0);
}

int		rotateleft(t_var *var)
{
	double	olddirx;
	double	oldplanex;

	olddirx = DIR_X;
	DIR_X = DIR_X * cos(ROTSPEED) - DIR_Y * sin(ROTSPEED);
	DIR_Y = olddirx * sin(ROTSPEED) + DIR_Y * cos(ROTSPEED);
	oldplanex = PLANE_X;
	PLANE_X = PLANE_X * cos(ROTSPEED) - PLANE_Y * sin(ROTSPEED);
	PLANE_Y = oldplanex * sin(ROTSPEED) + PLANE_Y * cos(ROTSPEED);
	D & (1 << 5) ? D ^= (1 << 5) : 0;
	ROTSPEED = 0.1;
	return (0);
}

int		ft_release(int keycode, t_var *var)
{
	keycode == 17 || keycode == 126 ? C ^= (1 << 0) : 0;
	keycode == 5 || keycode == 125 ? C ^= (1 << 1) : 0;
	keycode == 3 ? C ^= (1 << 2) : 0;
	keycode == 4 ? C ^= (1 << 3) : 0;
	keycode == 124 ? C ^= (1 << 4) : 0;
	keycode == 123 ? C ^= (1 << 5) : 0;
	keycode == 8 ? C ^= (1 << 6) : 0;
	keycode == 1 ? C ^= (1 << 7) : 0;
	keycode == 38 ? D ^= (1 << 0) : 0;
	keycode == 7 ? D ^= (1 << 1) : 0;
	return (0);
}

void	ft_press(int keycode, t_var *var)
{
	keycode == 17 || keycode == 126 ? C |= (1 << 0) : 0;
	keycode == 5 || keycode == 125 ? C |= (1 << 1) : 0;
	keycode == 3 ? C |= (1 << 2) : 0;
	keycode == 4 ? C |= (1 << 3) : 0;
	keycode == 124 ? C |= (1 << 4) : 0;
	keycode == 123 ? C |= (1 << 5) : 0;
	keycode == 8 ? C |= (1 << 6) : 0;
	keycode == 1 ? C |= (1 << 7) : 0;
	keycode == 38 ? D |= (1 << 0) : 0;
	keycode == 7 ? D |= (1 << 1) : 0;
}

int		ft_key(int keycode, t_var *var)
{
	if (keycode == 53)
	{
		free_all(var);
		exit(EXIT_SUCCESS);
	}
	ft_press(keycode, var);
	if ((keycode == 36 || keycode == 76) && M == 1)
		M = 0;
	else if ((keycode == 36 || keycode == 76) && M == 0)
		M = 1;
	keycode == 49 ? minecraft(var) : 0;
	keycode == 51 ? restart_wolf3d(var) : 0;
	keycode == 18 ? WEAPON = 1 : 0;
	keycode == 19 ? WEAPON = 2 : 0;
	keycode == 20 ? WEAPON = 3 : 0;
	keycode == 21 ? WEAPON = 4 : 0;
	keycode == 23 ? WEAPON = 5 : 0;
	return (0);
}
