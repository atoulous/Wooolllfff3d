/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atoulous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 17:20:07 by atoulous          #+#    #+#             */
/*   Updated: 2016/04/21 15:11:22 by atoulous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = malloc(sizeof(new))))
		return (NULL);
	new->next = NULL;
	if (content)
	{
		new->content = ft_memmove(ft_memalloc(content_size), content,
				content_size);
		new->content_size = content_size;
	}
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	return (new);
}
