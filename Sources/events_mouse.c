/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 14:13:22 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/22 19:22:20 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_mouse(int button, int x, int y, t_var *var)
{
	if (button == 1 || button == 4)
	{
		FIRE == 1 ? FIRE = 0 : (FIRE = 1);
	}
	if (button == 2 || button == 6)
	{
		D && (1 << 0) ? D ^= (1 << 0) : (D |= (1 << 0));
	}
	return (0);
}

int		ft_motion_mouse(int x, int y, t_var *var)
{
	y = 0;
	if (x < var->j)
	{
		D |= (1 << 5);
		D & (1 << 4) ? D ^= (1 << 4) : 0;
	}
	else if (x > var->j)
	{
		D |= (1 << 4);
		D & (1 << 5) ? D ^= (1 << 5) : 0;
	}
	var->j = x;
	return (0);
}
