/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/17 12:02:20 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/26 15:39:40 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		moveback(t_var *var)
{
	TAB[(int)(POS_X + DIR_X * MOVESPEED)][(int)POS_Y] == '0' ||
	TAB[(int)(POS_X + DIR_X * MOVESPEED)][(int)POS_Y] == 'R' ||
	TAB[(int)(POS_X + DIR_X * MOVESPEED)][(int)POS_Y] == 'r' ||
	TAB[(int)(POS_X + DIR_X * MOVESPEED)][(int)POS_Y] == 'a' ||
	TAB[(int)(POS_X + DIR_X * MOVESPEED)][(int)POS_Y] == 'P' ||
	TAB[(int)(POS_X + DIR_X * MOVESPEED)][(int)POS_Y] == 'p' ||
	TAB[(int)(POS_X + DIR_X * MOVESPEED)][(int)POS_Y] == 'u' ||
	TAB[(int)(POS_X + DIR_X * MOVESPEED)][(int)POS_Y] == 'q' ?
		POS_X += DIR_X * MOVESPEED : 0;
	TAB[(int)POS_X][(int)(POS_Y + DIR_Y * MOVESPEED)] == '0' ||
	TAB[(int)POS_X][(int)(POS_Y + DIR_Y * MOVESPEED)] == 'R' ||
	TAB[(int)POS_X][(int)(POS_Y + DIR_Y * MOVESPEED)] == 'r' ||
	TAB[(int)POS_X][(int)(POS_Y + DIR_Y * MOVESPEED)] == 'a' ||
	TAB[(int)POS_X][(int)(POS_Y + DIR_Y * MOVESPEED)] == 'P' ||
	TAB[(int)POS_X][(int)(POS_Y + DIR_Y * MOVESPEED)] == 'p' ||
	TAB[(int)POS_X][(int)(POS_Y + DIR_Y * MOVESPEED)] == 'u' ||
	TAB[(int)POS_X][(int)(POS_Y + DIR_Y * MOVESPEED)] == 'q' ?
		POS_Y += DIR_Y * MOVESPEED : 0;
	return (0);
}

int		movefront(t_var *var)
{
	TAB[(int)(POS_X - DIR_X * MOVESPEED)][(int)POS_Y] == '0' ||
	TAB[(int)(POS_X - DIR_X * MOVESPEED)][(int)POS_Y] == 'R' ||
	TAB[(int)(POS_X - DIR_X * MOVESPEED)][(int)POS_Y] == 'r' ||
	TAB[(int)(POS_X - DIR_X * MOVESPEED)][(int)POS_Y] == 'a' ||
	TAB[(int)(POS_X - DIR_X * MOVESPEED)][(int)POS_Y] == 'P' ||
	TAB[(int)(POS_X - DIR_X * MOVESPEED)][(int)POS_Y] == 'p' ||
	TAB[(int)(POS_X - DIR_X * MOVESPEED)][(int)POS_Y] == 'u' ||
	TAB[(int)(POS_X - DIR_X * MOVESPEED)][(int)POS_Y] == 'q' ?
		POS_X -= DIR_X * MOVESPEED : 0;
	TAB[(int)POS_X][(int)(POS_Y - DIR_Y * MOVESPEED)] == '0' ||
	TAB[(int)POS_X][(int)(POS_Y - DIR_Y * MOVESPEED)] == 'R' ||
	TAB[(int)POS_X][(int)(POS_Y - DIR_Y * MOVESPEED)] == 'r' ||
	TAB[(int)POS_X][(int)(POS_Y - DIR_Y * MOVESPEED)] == 'a' ||
	TAB[(int)POS_X][(int)(POS_Y - DIR_Y * MOVESPEED)] == 'P' ||
	TAB[(int)POS_X][(int)(POS_Y - DIR_Y * MOVESPEED)] == 'p' ||
	TAB[(int)POS_X][(int)(POS_Y - DIR_Y * MOVESPEED)] == 'u' ||
	TAB[(int)POS_X][(int)(POS_Y - DIR_Y * MOVESPEED)] == 'q' ?
		POS_Y -= DIR_Y * MOVESPEED : 0;
	return (0);
}

int		moveleft(t_var *var)
{
	TAB[(int)(POS_X - PLANE_X * MOVESPEED)][(int)POS_Y] == '0' ||
	TAB[(int)(POS_X - PLANE_X * MOVESPEED)][(int)POS_Y] == 'R' ||
	TAB[(int)(POS_X - PLANE_X * MOVESPEED)][(int)POS_Y] == 'r' ||
	TAB[(int)(POS_X - PLANE_X * MOVESPEED)][(int)POS_Y] == 'a' ||
	TAB[(int)(POS_X - PLANE_X * MOVESPEED)][(int)POS_Y] == 'P' ||
	TAB[(int)(POS_X - PLANE_X * MOVESPEED)][(int)POS_Y] == 'p' ||
	TAB[(int)(POS_X - PLANE_X * MOVESPEED)][(int)POS_Y] == 'u' ||
	TAB[(int)(POS_X - PLANE_X * MOVESPEED)][(int)POS_Y] == 'q' ?
		POS_X -= PLANE_X * MOVESPEED : 0;
	TAB[(int)POS_X][(int)(POS_Y - PLANE_Y * MOVESPEED)] == '0' ||
	TAB[(int)POS_X][(int)(POS_Y - PLANE_Y * MOVESPEED)] == 'R' ||
	TAB[(int)POS_X][(int)(POS_Y - PLANE_Y * MOVESPEED)] == 'r' ||
	TAB[(int)POS_X][(int)(POS_Y - PLANE_Y * MOVESPEED)] == 'a' ||
	TAB[(int)POS_X][(int)(POS_Y - PLANE_Y * MOVESPEED)] == 'P' ||
	TAB[(int)POS_X][(int)(POS_Y - PLANE_Y * MOVESPEED)] == 'p' ||
	TAB[(int)POS_X][(int)(POS_Y - PLANE_Y * MOVESPEED)] == 'u' ||
	TAB[(int)POS_X][(int)(POS_Y - PLANE_Y * MOVESPEED)] == 'q' ?
		POS_Y -= PLANE_Y * MOVESPEED : 0;
	return (0);
}

int		moveright(t_var *var)
{
	TAB[(int)(POS_X + PLANE_X * MOVESPEED)][(int)POS_Y] == '0' ||
	TAB[(int)(POS_X + PLANE_X * MOVESPEED)][(int)POS_Y] == 'R' ||
	TAB[(int)(POS_X + PLANE_X * MOVESPEED)][(int)POS_Y] == 'r' ||
	TAB[(int)(POS_X + PLANE_X * MOVESPEED)][(int)POS_Y] == 'a' ||
	TAB[(int)(POS_X + PLANE_X * MOVESPEED)][(int)POS_Y] == 'P' ||
	TAB[(int)(POS_X + PLANE_X * MOVESPEED)][(int)POS_Y] == 'p' ||
	TAB[(int)(POS_X + PLANE_X * MOVESPEED)][(int)POS_Y] == 'u' ||
	TAB[(int)(POS_X + PLANE_X * MOVESPEED)][(int)POS_Y] == 'q' ?
		POS_X += PLANE_X * MOVESPEED : 0;
	TAB[(int)POS_X][(int)(POS_Y + PLANE_Y * MOVESPEED)] == '0' ||
	TAB[(int)POS_X][(int)(POS_Y + PLANE_Y * MOVESPEED)] == 'R' ||
	TAB[(int)POS_X][(int)(POS_Y + PLANE_Y * MOVESPEED)] == 'r' ||
	TAB[(int)POS_X][(int)(POS_Y + PLANE_Y * MOVESPEED)] == 'a' ||
	TAB[(int)POS_X][(int)(POS_Y + PLANE_Y * MOVESPEED)] == 'P' ||
	TAB[(int)POS_X][(int)(POS_Y + PLANE_Y * MOVESPEED)] == 'p' ||
	TAB[(int)POS_X][(int)(POS_Y + PLANE_Y * MOVESPEED)] == 'u' ||
	TAB[(int)POS_X][(int)(POS_Y + PLANE_Y * MOVESPEED)] == 'q' ?
		POS_Y += PLANE_Y * MOVESPEED : 0;
	return (0);
}

void	ft_moves(t_var *var)
{
	C & (1 << 0) ? moveback(var) : 0;
	C & (1 << 1) ? movefront(var) : 0;
	C & (1 << 2) ? moveleft(var) : 0;
	C & (1 << 3) ? moveright(var) : 0;
	C & (1 << 4) ? rotateright(var) : 0;
	C & (1 << 5) ? rotateleft(var) : 0;
	C & (1 << 6) ? MOVESPEED = 0.2 : 0;
	C & (1 << 6) ? ROTSPEED = 0.05 : 0;
	C & (1 << 7) ? MOVESPEED = 0.8 : 0;
	C & (1 << 7) ? ROTSPEED = 0.2 : 0;
	D & (1 << 5) ? rotateleft(var) : 0;
	D & (1 << 4) ? rotateright(var) : 0;
	!(C & (1 << 6)) && !(C & (1 << 7)) ? MOVESPEED = 0.4 : 0;
	!(C & (1 << 6)) && !(C & (1 << 7)) ? ROTSPEED = 0.1 : 0;
	if (D & (1 << 0))
	{
		DUCK = 3;
		DUCKEND = 3;
	}
	else
	{
		DUCK = 2;
		DUCKEND = 4;
	}
}
