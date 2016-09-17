/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 19:26:28 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/17 20:16:15 by atoulous         ###   ########.fr       */
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
	init_raycasting(var);
}

int		ft_crossquit(t_var *var)
{
	free_tab(var);
	exit(EXIT_SUCCESS);
}

int		minecraft(t_var *var)
{
	if (TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] == 'D')
		TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] = 'p';
	else if (TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] == 'B')
		TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] = '0';
	else if (TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] == 'p')
		TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] = 'D';
	else if ((TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] == '0')
		&& (((int)(POS_X + DIR_X) != POS_X) && (int)(POS_Y + DIR_Y) != POS_Y))
		TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] = 'B';
	else if (TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] == 'A')
	{
		TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] = 'T';
		for (int i = 0; i < YMAX; i++)
			for (int y = 0; y < XMAX; y++)
				if (TAB[i][y] == 'p')
					TAB[i][y] = 'R';
	}
	return (0);
}

int		rotateright(t_var *var)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = DIR_X;
	DIR_X = DIR_X * cos(-ROTSPEED) - DIR_Y * sin(-ROTSPEED);
	DIR_Y = oldDirX * sin(-ROTSPEED) + DIR_Y * cos(-ROTSPEED);
	oldPlaneX = PLANE_X;
	PLANE_X = PLANE_X * cos(-ROTSPEED) - PLANE_Y * sin(-ROTSPEED);
	PLANE_Y = oldPlaneX * sin(-ROTSPEED) + PLANE_Y * cos(-ROTSPEED);
	return (0);
}

int		rotateleft(t_var *var)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = DIR_X;
	DIR_X = DIR_X * cos(ROTSPEED) - DIR_Y * sin(ROTSPEED);
	DIR_Y = oldDirX * sin(ROTSPEED) + DIR_Y * cos(ROTSPEED);
	oldPlaneX = PLANE_X;
	PLANE_X = PLANE_X * cos(ROTSPEED) - PLANE_Y * sin(ROTSPEED);
	PLANE_Y = oldPlaneX * sin(ROTSPEED) + PLANE_Y * cos(ROTSPEED);
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
}

int		ft_mouse(int button, int x, int y, t_var *var)
{
	if (button == 1 || button == 4)
	{
		ft_putendl("FIRE");
	}
	if (button == 2 || button == 6)
	{
		ft_putendl("JUMP");
	}
	return (0);
}

int		ft_motion_mouse(int x, int y, t_var *var)
{
	!y ? y = x : 0;
	printf("x=%f\n",((double)x - WIDTH_WIN / 4));
	printf("y=%f\n",((double)y - WIDTH_WIN / 4));
	/*if ((double)x - WIDTH_WIN / 4 < ((double)y - WIDTH_WIN / 4))
		C |= (1 << 5);
	else if ((double)x - WIDTH_WIN / 4 > ((double)y - WIDTH_WIN / 4))
		C ^= (1 << 5);
	if ((double)x - WIDTH_WIN / 4 > ((double)y - WIDTH_WIN / 4))
		C |= (1 << 4);
	else if ((double)x - WIDTH_WIN / 4 < ((double)y - WIDTH_WIN / 4))
		C ^= (1 << 4);
	*/
	return (0);
}

int		ft_key(int keycode, t_var *var)
{
	int		i;

	i = -1;
	if (keycode == 53)
	{
		free_tab(var);
		exit(EXIT_SUCCESS);
	}
	ft_press(keycode, var);
	ft_putchar(TAB[(int)(POS_X + DIR_X * MOVESPEED)][(int)POS_Y]);
	keycode == 49 ? minecraft(var) : 0;
	keycode == 51 ? restart_wolf3d(var) : 0;
	ft_putnbr(keycode);
	ft_putstr("\nPOS_X==");
	ft_putnbr(POS_X);
	ft_putstr("\nPOS_Y==");
	ft_putnbr(POS_Y);
	ft_putstr("\n");
	while (TAB[++i])
		ft_putendl(TAB[i]);
	printf("DIR_X==%lf\n", DIR_X);
	printf("DIR_Y==%lf\n", DIR_Y);
	return (0);
}
