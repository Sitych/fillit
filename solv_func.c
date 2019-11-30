/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:26:38 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/30 08:15:12 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_solve(t_tetr *ptr)
{
	byte	*map;
	byte	**tetromino;
	int		len;
	int 	i;
	int		j;
	
	i = 0;
	len = 2 * ft_sqrt(ft_listlen(ptr));
	map = ft_mapcreate(len);
	tetromino = ft_bytemaskcreate(ptr);
	while (i < ft_listlen(ptr))
	{
		j = 0;
		while (j < 4)
		{
			ft_print(tetromino[i][j], 0);
			j++;
			ft_putchar('\n');
		}
		i++;
	}
	
	i = 0;
	while (i <= len)
	{
		ft_print(map[i], 0);
		ft_putchar('\n');
		i++;
	}
	return (0);
}