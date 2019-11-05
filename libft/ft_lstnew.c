/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:48:51 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/09/18 23:50:41 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;

	ptr = NULL;
	ptr = (t_list*)malloc(sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	if (content == NULL)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
		ptr->next = NULL;
		return (ptr);
	}
	ptr->content = malloc(content_size);
	if (ptr->content == NULL)
	{
		free(ptr);
		return (NULL);
	}
	ft_memmove(ptr->content, content, content_size);
	ptr->content_size = content_size;
	ptr->next = NULL;
	return (ptr);
}
