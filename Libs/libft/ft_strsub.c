/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 16:14:24 by atoulous          #+#    #+#             */
/*   Updated: 2016/03/22 15:13:51 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;

	if (!(new = ft_strnew(len)))
		return (NULL);
	while (start--)
		s++;
	ft_strncpy(new, s, len);
	new[len] = '\0';
	return (new);
}
