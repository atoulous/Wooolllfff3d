/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 15:50:26 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/16 16:54:46 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_baise_itoa(char *str, int base, long int nb, int i)
{
	char	*tab;

	tab = ft_strdup("0123456789ABCDEF");
	while (nb)
	{
		str[--i] = tab[nb % base];
		nb /= base;
	}
	return (str);
}

char		*ft_itoa_base(int value, int base)
{
	int			i;
	long int	nb;
	char		*str;

	nb = value;
	i = 0;
	while (value)
	{
		value /= base;
		i++;
	}
	if (nb == 0 || (nb < 0 && base == 10))
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		if (base == 10)
			str[0] = '-';
		nb *= -1;
	}
	return (ft_baise_itoa(str, base, nb, i));
}
