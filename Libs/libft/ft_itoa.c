/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 18:18:10 by atoulous          #+#    #+#             */
/*   Updated: 2016/04/11 13:22:20 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_nbchar(char *nb, int n, int i)
{
	while (n)
	{
		nb[i] = '0' - (n % 10);
		n = n / 10;
		i--;
	}
	return (nb);
}

char		*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*nb;

	i = -1;
	j = n;
	while (j)
	{
		j = j / 10;
		i++;
	}
	if (n <= 0)
		i++;
	if (!(nb = ft_strnew(i + 1)))
		return (NULL);
	if (n < 0)
		nb[0] = '-';
	if (n > 0)
		n = -n;
	if (!n)
		nb[0] = '0';
	return (ft_nbchar(nb, n, i));
}
