/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:35:05 by atoulous          #+#    #+#             */
/*   Updated: 2016/03/22 15:06:07 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new;
	size_t	i;

	if (!(new = (void *)malloc(sizeof(char) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
		((char *)new)[i] = '\0';
	return (new);
}
