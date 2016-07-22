/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:11:31 by atoulous          #+#    #+#             */
/*   Updated: 2016/03/22 14:13:33 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	size;

	if (!(*little) || !little)
		return ((char *)big);
	size = ft_strlen(little);
	while (*big)
	{
		if (!(ft_strncmp(big, little, size)))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
