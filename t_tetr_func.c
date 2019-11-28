/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tetr_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 20:28:21 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/25 18:36:22 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// t_tetr 	*ft_newtetr(int len, int crds)
// {
// 	t_tetr	*ptr;

// 	ptr = (t_tetr*)malloc(sizeof(t_tetr));
// 	if (ptr == NULL)
// 		return (NULL);
// 	ptr->line = (int*)malloc(sizeof(int) * len);
// 	if (ptr->line == NULL)
// 		{
// 			free(ptr);
// 			return (NULL);
// 		}
// 	ptr->coords = (int*)malloc(sizeof(int) * crds);
// 	if (ptr->coords == NULL)
// 	{
// 		free(ptr->line);
// 		free(ptr);
// 		return (NULL);
// 	}
// 	ptr->next = NULL;
// 	ptr->prev = NULL;
// 	return (ptr);
// }

t_tetr 	*ft_newtetr()
{
	t_tetr	*ptr;

	ptr = (t_tetr*)malloc(sizeof(t_tetr));
	if (ptr == NULL)
		return (NULL);
	ptr->line = 0;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}