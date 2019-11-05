/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:19:17 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/09/19 10:41:16 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static	void	ft_del(void *cont, size_t cont_size)
{
	size_t	i;
	void	*tmp;

	i = 0;
	while (i < cont_size)
	{
		tmp = cont;
		cont++;
		free(tmp);
		i++;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*tmp;

	ptr = NULL;
	if (lst != NULL)
		ptr = ft_lstnew(lst->content, lst->content_size);
	if (ptr == NULL || lst == NULL)
		return (NULL);
	ptr = (*f)(ptr);
	tmp = ptr;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = (*f)(ft_lstnew(lst->content, lst->content_size));
		if (tmp->next == NULL)
		{
			ft_lstdel(&ptr, ft_del);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (ptr);
}
