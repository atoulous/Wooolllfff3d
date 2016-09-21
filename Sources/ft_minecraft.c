/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minecraft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:29:02 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/21 00:20:22 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	automate_on(t_var *var)
{
	int		i;
	int		y;

	TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] = 'U';
	i = -1;
	while (++i < YMAX)
	{
		y = -1;
		while (++y < XMAX)
			if (TAB[i][y] == 'I')
				TAB[i][y] = 'M';
	}
}

void	automate_off(t_var *var)
{
	int		i;
	int		y;

	TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] = 'A';
	i = -1;
	while (++i < YMAX)
	{
		y = -1;
		while (++y < XMAX)
			if (TAB[i][y] == 'M')
				TAB[i][y] = 'I';
	}
}

void	telep_to_b(t_var *var)
{
	POS_Y = 9.5;
	POS_X = 3.5;
}

void	telep_to_a(t_var *var)
{
	POS_Y = 67.5;
	POS_X = 3.5;
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
		automate_on(var);
	else if (TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] == 'U')
		automate_off(var);
	else if (TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] == 'T'
			&& POS_Y > 15)
		telep_to_b(var);
	else if (TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] == 'T'
			&& POS_Y < 15)
		telep_to_a(var);
	else if (TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] == '1')
			TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] = '2';
	else if (TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] == '2')
			TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] = '1';
	else if (TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] == 'F')
			TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] = 'f';
	else if (TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] == 'f')
			TAB[(int)(POS_X + DIR_X)][(int)(POS_Y + DIR_Y)] = 'F';
	return (0);
}
