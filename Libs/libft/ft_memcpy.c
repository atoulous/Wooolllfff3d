/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 11:54:38 by atoulous          #+#    #+#             */
/*   Updated: 2016/03/21 16:03:51 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char *s;

	s = (unsigned char *)dst;
	while (n-- > 0)
	{
		*s = *((unsigned char *)src);
		src++;
		s++;
	}
	return (dst);
}
