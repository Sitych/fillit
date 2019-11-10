/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tetr_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:28:21 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/10 20:28:46 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr 	*ft_newtetr(int len, int crds)
{
	t_tetr	*ptr;

	ptr = (t_tetr*)malloc(sizeof(t_tetr));
	if (ptr == NULL)
		return (NULL);
	ptr->line = (int*)malloc(sizeof(int) * len);
	if (ptr->line == NULL)
		{
			free(ptr);
			return (NULL);
		}
	ptr->coordinates = (int*)malloc(sizeof(int) * crds);
	if (ptr->coordinates == NULL)
	{
		free(ptr->line);
		free(ptr);
		return (NULL);
	}
	return (ptr);
}