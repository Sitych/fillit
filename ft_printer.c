/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rretta <rretta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 01:06:08 by rretta            #+#    #+#             */
/*   Updated: 2019/12/25 22:34:15 by rretta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char    **ft_charmap(int len)
{   
    char    **map;
	int		i;

	if ((map = (char**)malloc(sizeof(char*) * len)) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if ((map[i] = (char*)malloc(sizeof(char) * len)) == NULL)
			return (NULL);
		i++;
	}

    int j = 0;
    int v = 0;
    while (j < len)
    {
        while (v < len)
        {
            map[j][v] = '.';
            v++;
        }
        v = 0;
        j++;
    }
	return (map);
}

void     ft_printer(t_tetr *tetr, int len, char **map)
{
    byte mask;
    int i;
    int j;
    int u = 0;
    int v = 0;
    int count;

    mask = 0b1000000000000000;
    i = 0;
    j = 0;
    count = 0;
    while (tetr != NULL)
    {
        tetr->c = 'A' + count;;
        while (i < len)
        {
            while (j < len)
            {
                if ((tetr->tetromin[i] & mask) == 0)
                {
                    mask = mask >> 1;
                    j++;
                }
                else
                {
                    map[i][j] = tetr->c;
                    mask = mask >> 1;
                    j++;
                }    
            }
            mask = mask << j;
            j = 0;
            i++;
        }
        i = 0;
        tetr = tetr->next;  
        count++;
    } 
    while (u < len)
    {
        printf("%s\n", map[u]);
        u++;
    }
}