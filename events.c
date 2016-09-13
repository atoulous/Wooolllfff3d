/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 19:26:28 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/12 19:27:37 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	restart_wolf3d(t_var *var)
{
	int		i;

	i = -1;
	while (TAB[++i])
		free(TAB[i]);
	free(TAB);
	TAB = ft_strsplit(MAP, '\n');
	POS_X = 8;
	POS_Y = 8;
	DIR_X = -1;
	DIR_Y = 0;
	PLANE_X = 0;
	PLANE_Y = 0.66;
}

int		ft_crossquit(t_var *var)
{
	free_tab(var);
	exit(EXIT_SUCCESS);
}

void	ft_rotates(int keycode, t_var *var)
{
	double	oldDirX;
	double	oldPlaneX;

	if (keycode == 124)
	{
		oldDirX = DIR_X;
		DIR_X = DIR_X * cos(-ROTSPEED) - DIR_Y * sin(-ROTSPEED);
		DIR_Y = oldDirX * sin(-ROTSPEED) + DIR_Y * cos(-ROTSPEED);
		oldPlaneX = PLANE_X;
		PLANE_X = PLANE_X * cos(-ROTSPEED) - PLANE_Y * sin(-ROTSPEED);
		PLANE_Y = oldPlaneX * sin(-ROTSPEED) + PLANE_Y * cos(-ROTSPEED);
	}
	if (keycode == 123)
	{
		oldDirX = DIR_X;
		DIR_X = DIR_X * cos(ROTSPEED) - DIR_Y * sin(ROTSPEED);
		DIR_Y = oldDirX * sin(ROTSPEED) + DIR_Y * cos(ROTSPEED);
		oldPlaneX = PLANE_X;
		PLANE_X = PLANE_X * cos(ROTSPEED) - PLANE_Y * sin(ROTSPEED);
		PLANE_Y = oldPlaneX * sin(ROTSPEED) + PLANE_Y * cos(ROTSPEED);
	}
}

void	ft_moves(int keycode, t_var *var)
{
	if (keycode == 126 || keycode == 17)
	{
		TAB[(int)(POS_X + DIR_X * MOVESPEED)][(int)POS_Y] == '0' ?
			POS_X += DIR_X * MOVESPEED : 0;
		TAB[(int)POS_X][(int)(POS_Y + DIR_Y * MOVESPEED)] == '0' ?
			POS_Y += DIR_Y * MOVESPEED : 0;
	}
	if (keycode == 125 || keycode == 5)
	{
		TAB[(int)(POS_X - DIR_X * MOVESPEED)][(int)POS_Y] == '0' ?
			POS_X -= DIR_X * MOVESPEED : 0;
		TAB[(int)POS_X][(int)(POS_Y - DIR_Y * MOVESPEED)] == '0' ?
			POS_Y -= DIR_Y * MOVESPEED : 0;
	}
	if (keycode == 3)
	{
		TAB[(int)(POS_X - PLANE_X * MOVESPEED)][(int)POS_Y] == '0' ?
			POS_X -= PLANE_X * MOVESPEED : 0;
		TAB[(int)POS_X][(int)(POS_Y - PLANE_Y * MOVESPEED)] == '0' ?
			POS_Y -= PLANE_Y * MOVESPEED : 0;
	}
	if (keycode == 4)
	{
		TAB[(int)(POS_X + PLANE_X * MOVESPEED)][(int)POS_Y] == '0' ?
			POS_X += PLANE_X * MOVESPEED : 0;
		TAB[(int)POS_X][(int)(POS_Y + PLANE_Y * MOVESPEED)] == '0' ?
			POS_Y += PLANE_Y * MOVESPEED : 0;
	}
}
int		minecraft(int keycode, t_var *var)
{
	if (TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] != '0')
		TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] = '0';
	else
		TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] = '9';
	return (0);
}

int		ft_key(int keycode, t_var *var)
{
	int		i;
	i = -1;
	KEYCODE = keycode;
	if (keycode == 53)
	{
		free_tab(var);
		exit(EXIT_SUCCESS);
	}
	refresh_image(var);
	ft_moves(keycode, var);
	ft_rotates(keycode, var);
	ft_putchar(TAB[(int)(POS_X + DIR_X * MOVESPEED)][(int)POS_Y]);
	keycode == 49 ? minecraft(keycode, var) : 0;
	keycode == 51 ? restart_wolf3d(var) : 0;
	keycode == 69 && MOVESPEED < 4 ? MOVESPEED *= 1.4 : 0;
	keycode == 78 && MOVESPEED > 0 ? MOVESPEED *= -1.4 : 0;
	keycode == 0 ? PLANE_Y += 0.3 : 0;
	keycode == 1 ? PLANE_Y -= 0.3 : 0;
	ft_putnbr(keycode);
	ft_putstr("\nPOS_X==");
	ft_putnbr(POS_X);
	ft_putstr("\nPOS_Y==");
	ft_putnbr(POS_Y);
	ft_putstr("\nDIR_X==");
	ft_putnbr(DIR_X);
	ft_putstr("\nDIR_Y==");
	ft_putnbr(DIR_Y);
	ft_putstr("\n");
	while (TAB[++i])
		ft_putendl(TAB[i]);
	printf("DIR_X==%lf\n", DIR_X);
	printf("DIR_Y==%lf\n", DIR_Y);
	return (0);
}
