/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create2tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 15:25:37 by atoulous          #+#    #+#             */
/*   Updated: 2016/04/21 15:34:22 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_create2tab(int x, int y)
{
	char	**tab;
	int		i;

	if (!(tab = (char**)malloc(sizeof(char*) * x + 1)))
		return (NULL);
	i = -1;
	while (++i < x)
	{
		tab[i] = ft_strnew(y + 1);
		tab[i][y] = '\n';
	}
	tab[x] = 0;
	return (tab);
}
