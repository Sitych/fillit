/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:26:04 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/25 18:26:24 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_shift(int *mas)
{
	int i;
	int x_min;
	int y_min;

	i = 0;
	x_min = mas[0];
	y_min = mas[1];
	while (i < COORD)
	{
		if (i % 2 == 0)
			x_min = (x_min < mas[i]) ? x_min : mas[i];
		else
			y_min = (y_min < mas[i]) ? y_min : mas[i];
		i++;
	}
	i = -1;
	while (i++ < COORD)
	{
		if (i % 2 == 0)
			mas[i] = mas[i] - x_min;
		else
			mas[i] = mas[i] - y_min;
	}
	return (mas);
}

int             ft_validsquare(char *tetr)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (i < SIZE)
	{
		if (*(tetr++) == '\n' && i % 4 == 0)
				continue ;
		if (*(tetr - 1) != '.' && *(tetr - 1) != '#')
				return (-1);
		if (*(tetr - 1) == '#')
			k++;
		i++;
	}
	if (k != 4)
		return (-1);
	return (1);
}