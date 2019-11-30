/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:26:38 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/30 09:15:47 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_solve(t_tetr *ptr, int len)
{
	byte	*map;
	
	map = ft_mapcreate(len);
	

	int 	k;
	int		j;
	k = 0;
	while (ptr != NULL)
	{
		j = 0;
		while (j < 4)
		{
			ft_print(ptr->line[j], 0);
			j++;
			ft_putchar('\n');
		}
		ptr = ptr->next;
	}
	
	k = 0;
	while (i <= len)
	{
		ft_print(map[k], 0);
		ft_putchar('\n');
		k++;
	}
	return (0);
}