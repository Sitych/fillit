/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tetr_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:28:21 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/30 09:17:34 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr 	*ft_newtetr(int b, char c)
{
	t_tetr	*ptr;
	int		i;

	if ((ptr = (t_tetr*)malloc(sizeof(t_tetr))) == NULL)
		return (NULL);
	i = 0;
	if ((ptr->line = (byte*)malloc(sizeof(byte) * 4)) == NULL)
			return (NULL);
	while (i < 4)
	{
		ptr->line[i] = (b & (0xf000 >> (i * 4))) << (i * 4);
		i++;
	}
	ptr->c = c;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

int		ft_listlen(t_tetr *ptr)
{
	int	len;

	len = 0;
	while (ptr != NULL)
	{
		len++;
		ptr = ptr->next;
	}
	return (len);
}

t_tetr    *ft_tostart(t_tetr *list)
{
	while (list->prev != NULL)
		list = list->prev;
	return (list);
}