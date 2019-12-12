/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 01:06:08 by rretta            #+#    #+#             */
/*   Updated: 2019/12/12 07:12:22 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h" 

int		ft_kost(void)
{
	static int	l;

	l = -1;
	l++;
	return (l);
}

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
		// ft_printmap(map, len);
		// printf("\n");
	if (ptr == NULL)
		return (1);
	int		row;
	int		c;

	
	row = 0;
	c = 0;
	while (row < len)
	{
		ft_printmap(map, len);
		printf("\n");
		if (ft_place(&map, ptr, len, row) == 0)
		{
			row++;
			printf("%d\n", row);
		}
		else
			if (ft_solver(ptr->next, map, len) == 1)
				return (1);
	}
	return (0);
}

int		ft_place(byte **map, t_tetr *ptr, int len, int row)
{
    int		i;
	int		j;
	int		k;
	t_tetr	*tmp;
	byte	*old_map;

	tmp = ptr;
	old_map = ft_mapdup(*map, len);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < 4)
		{
			// // printf("row + j =\n");
			// ft_print((*map)[row + j], 0);
			// printf("\n");
			(*map)[row + j] =  (*map)[row + j] ^ tmp->line[j];
			j++;
		}
		// ft_printmap(*map, len);
		// printf("\n");
		if (ft_mapcheck(old_map, *map, len) == 1)
			return (1);
		k = 0;
		while (k < len)
		{
			(*map)[k] = old_map[k];
			k++;
		}
		j = 0;
			printf("tetr\n");
		while (j < 4)
		{
			tmp->line[j] = tmp->line[j] >> 1;
			// ft_print(tmp->line[j], 0);
			// ft_putchar('\n');
			j++;
		}
		i++;
	}
	/*ft_freemap(new_map);*/
	return (0);
}

int     ft_mapcheck(byte *old_map, byte *new_map, int len)
{
    int		i;
    int		s;

    i = 0;
    s = 0;
    while (i < len)
    {
    	/*if (((old_map[i] << i) >> len) == ((new_map[i] << i) >> len))*/
		if ((old_map[i] & new_map[i]) == old_map[i])
			s++;
		i++;
    }
	if (s == len)
		return (1);
	return (0);
}