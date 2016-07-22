/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 13:11:31 by atoulous          #+#    #+#             */
/*   Updated: 2016/05/18 19:00:45 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	size;

	if (!*little)
		return ((char *)big);
	size = ft_strlen(little);
	while (*big && len)
	{
		if (len < size)
			return (NULL);
		if (!(ft_strncmp(big, little, size)))
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
