/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 01:06:08 by rretta            #+#    #+#             */
/*   Updated: 2019/12/30 20:06:20 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h" 

void	ft_printmap(byte *map, int len)
{
	int k;
		
	k = 0;
	while (k <= len)
	{
		ft_print(map[k], 0);
		ft_putchar('\n');
		k++;
	}
}

int     ft_solver(t_tetr *ptr, byte *map, int len)
{
	if (ptr == NULL)
		return (1);

	int		row;
	int		col;
	byte	tmp;
	int		i;

	row = 0;
	col = 0;
	while (row < len)
	{
		col = 0;
		while (col < len)
		{
			if (ft_mapcheck(map, ptr, len) == 1)
			{
				map = ft_xormap(map, ptr, len);
				if (ft_solver(ptr->next, map, len))
					return (1);
				map = ft_xormap(map, ptr, len);
			}
			ptr = ft_shift_tetr(ptr, 1, 1, len);
			col++;
			printf("\nshift right\n");
			ft_printmap(ptr->tetromin, len);
			ft_putchar('\n');
		}
		ptr = ft_shift_tetr(ptr, -1, len, len);
		i = len;
		while (i >= 1)
		{
			ptr->tetromin[i] = ptr->tetromin[i - 1];
			i--;
		}
		ptr->tetromin[i] = 0;
		row++;
		printf("\nshift down\n");
		ft_printmap(ptr->tetromin, len);
		ft_putchar('\n');
	}
	ptr->tetromin = ft_null_tetramin(ptr->tetromin);
	i = 0;
	while (i < 4)
	{
		ptr->tetromin[i] = ptr->line[i];
		i++;
	}
	return (0);
}

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	while (i < 2147483647)
	{
		if ((i * i) < nb)
			i++;
		else if ((i * i) >= nb)
			return (i);
	}
	return (0);
}