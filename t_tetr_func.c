/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tetr_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:28:21 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/12/30 19:28:06 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr 		*ft_newtetr(int b, char c)
{
	t_tetr	*ptr;
	int		i;

	if ((ptr = (t_tetr*)malloc(sizeof(t_tetr))) == NULL)
		return (NULL);
	if ((ptr->line = (byte*)malloc(sizeof(byte) * 4)) == NULL)
		return (NULL);
	if ((ptr->tetromin = (byte*)malloc(sizeof(byte) * 16)) == NULL)
		return (NULL);
	ptr->tetromin = ft_null_tetramin(ptr->tetromin);
	i = 0;
	while (i < 4)
	{
		ptr->line[i] = (b & (0xf000 >> (i * 4))) << (i * 4);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		ptr->tetromin[i] = ptr->line[i];
		i++;
	}
	ptr->c = c;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

int			ft_listlen(t_tetr *ptr)
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

t_tetr		*ft_shift_tetr(t_tetr *tmp, int direction, int quantity, int len)
{
	int		i;

	i = 0;
	if (direction == 1)
	{
		while (i < len)
		{
			tmp->tetromin[i] = tmp->tetromin[i] >> quantity;
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			tmp->tetromin[i] = tmp->tetromin[i] << quantity;
			i++;
		}
	}
	return (tmp);
}

byte		*ft_null_tetramin(byte *tetramin)
{
	int i;

	i = 0;
	while (i < 16)
	{
		tetramin[i] = 0;
		i++;
	}
	return (tetramin);
}