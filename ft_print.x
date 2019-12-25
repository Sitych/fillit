/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 00:08:26 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/12/25 22:11:21 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_print_tetr(t_tetr *ptr, int len)
{
	char	**map;
	int		i;
	int		j;
	int		k;
	int		l;

	map = ft_charmapcreate(len);
	while (ptr != NULL)
	{
		i = 0;
		k = 0;
		while (ptr->tetromin[i] & 0xffff == 0)
			i++;
		while ((ptr->tetromin[0] & 0x8000 == 0) || (ptr->tetromin[1] & 0x8000 == 0) \
		|| (ptr->tetromin[2] & 0x8000 == 0) || (ptr->tetromin[3] & 0x8000 == 0))
		{
			l = 0;
			while (l < 4)
			{
				ptr->tetromin[l] = ptr->tetromin[l] << 1;
				l++;
			}
		}
		j = 0;
		while (j < 4)
		{
			while (ptr->tetromin[j] << k == 0x80)
			{
				char[i][l + k] = ptr->c;
				k++;
			}
			j++;
		}
		ptr = ptr->next;
	}
	j = 0;
	while (j < len)
	{
		ft_putstr(map[j]);
		ft_putchar('\n');
	}
}

char		**ft_charmapcreate(int len)
{
	char	**map;
	int		i;

	if ((map = (char**)malloc(sizeof(char*) * len)) == NULL)
		return (NULL);
	i = 0;
	while (i < 16)
	{
		if ((map[i] = (char*)malloc(sizeof(char) * len)) == NULL)
			return (NULL);
		i++;
	}
	return (map);
}