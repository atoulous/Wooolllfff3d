/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <atoulous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/04 15:41:11 by atoulous          #+#    #+#             */
/*   Updated: 2016/06/16 17:48:11 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	ft_determine_base(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	ft_recursive_power(int nb, int power)
{
	int		res;

	res = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	else
		return (nb * ft_recursive_power(nb, power - 1));
}

static int	ft_convert_10(char *nbr, char *base_from)
{
	int		i;
	int		j;
	int		res;
	int		base;
	int		len;

	i = 0;
	j = 0;
	res = 0;
	base = ft_determine_base(base_from);
	len = ft_determine_base(nbr);
	while (nbr[i])
	{
		while (nbr[i] != base_from[j])
			j++;
		res = res + (j * ft_recursive_power(base, len - 1));
		len--;
		j = 0;
		i++;
	}
	return (res);
}

static char	*ft_convert_to(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		num;
	int		base;
	char	*res;

	i = 0;
	base = ft_determine_base(base_to);
	num = ft_convert_10(nbr, base_from);
	while (num != 0)
	{
		num = num / base;
		i++;
	}
	num = ft_convert_10(nbr, base_from);
	if (!(res = (char*)malloc(sizeof(*res) * i + 1)))
		return (NULL);
	res[i] = '\0';
	i--;
	while (i >= 0)
	{
		res[i] = base_to[num % base];
		num = num / base;
		i--;
	}
	return (res);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*res;

	num = ft_convert_10(nbr, base_from);
	if (num == 0)
	{
		if (!(res = (char*)malloc(sizeof(*res) * 1 + 1)))
			return (NULL);
		res[0] = base_to[0];
		res[1] = '\0';
	}
	else
		res = ft_convert_to(nbr, base_from, base_to);
	return (res);
}
