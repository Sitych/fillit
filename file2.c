/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:31:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/28 20:30:25 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "t_tetr_func.c"
#include "valid_func.c"
#include "map_func.c"
#include <stdio.h>

void	ft_print(int len, int i)
{
	if (len < 2)
	{
		while (i < 15)
		{
			ft_putchar('0');
			i++;
		}
		ft_putchar('0' + len);
		return ;
	}
	i++;
	ft_print(len / 2, i);
	ft_putchar('0' + len % 2);
	return ;
}

int main(int ac, char **av)
{
	printf("%d\n", ft_sqrt(24));
	ac = 1;
	int fd = open(av[1], O_RDONLY);
	
	t_tetr	*ptr;
	t_tetr	*tmp;
	int num;

	num = 1;
	if (fd < 0)
		return (0);
	ptr = ft_newtetr(SIZE, COORD);
	while (ft_definition(&ptr, fd) > 0)
	{
		num++;
		tmp = ptr;
		ptr = ptr->next;
		ptr = ft_newtetr(SIZE, COORD);
		ptr->prev = tmp;
	}
	printf("len = %zu\n", ft_listlen(ptr));
	while (1)
	{
		// printf("tetr = %x %d\n", ptr->line, ptr->line);
		// ft_print(ptr->line, 0);
		// ft_putchar('\n');
		ptr->line = ft_shift(ptr->line);
		// printf("shift byte =");
		// ft_print(ptr->line, 0);
		// ft_putchar('\n');
		// printf("valid tetr = %d \n", adjacency_counter(ptr->line));
		if (ptr->prev == NULL)
			break ;
		ptr = ptr->prev;
	}

	ft_putnbr(num);
	// int b;
	// b = 0b1000100010001000;  // Или любое другое
	// ft_putchar('\n');
	// ft_print(b);
	
	close(fd);
	return (1);
}
