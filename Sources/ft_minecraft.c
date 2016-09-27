/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minecraft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:29:02 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/26 15:55:53 by atoulous         ###   ########.fr       */
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
	if (VIEW == 'D')
		VIEW = 'p';
	else if (VIEW == 'p')
		VIEW = 'D';
	else if (VIEW == 'B')
		VIEW = '0';
	else if (VIEW == '0' && VIEW != POS_Y)
		VIEW = 'B';
	else if (VIEW == 'A')
		automate_on(var);
	else if (VIEW == 'U')
		automate_off(var);
	else if (VIEW == 'T' && POS_Y > 15)
		telep_to_b(var);
	else if (VIEW == 'T' && POS_Y < 15)
		telep_to_a(var);
	else if (VIEW == '1')
		VIEW = '2';
	else if (VIEW == '2')
		VIEW = '1';
	else if (VIEW == 'F')
		VIEW = 'f';
	else if (VIEW == 'f')
		VIEW = 'F';
	return (0);
}
