/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:47:46 by atoulous          #+#    #+#             */
/*   Updated: 2016/03/14 17:06:33 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*restrict dst, const char *restrict src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	a;
	size_t	b;

	i = ft_strlen(src);
	j = ft_strlen(dst);
	a = 0;
	b = 0;
	if (size < j)
		return (i + size);
	a = j;
	while (src[b] && a + 1 < size)
	{
		dst[a] = src[b];
		a++;
		b++;
	}
	dst[a] = '\0';
	return (i + j);
}
