/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:44:27 by atoulous          #+#    #+#             */
/*   Updated: 2016/09/20 23:49:43 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(int what)
{
	if (what == 1)
		ft_putendl("error on parsing");
	if (what == 2)
		ft_putendl("Not a valid name");
	if (what == 3)
		ft_putendl("No respawn found");
	exit(0);
}
