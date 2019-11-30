/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:31:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/30 09:01:41 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "t_tetr_func.c"
#include "valid_func.c"
#include "map_func.c"
#include "solv_func.c"
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
	t_tetr	*ptr;
	t_tetr	*tmp;
	t_tetr	*start;
	int		num;
	char	c;
	int		fd;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || ft_definition(&num, fd) == -1)
		return (0);
	c = 'A';
	ptr = ft_newtetr(num, c++);
	start = ptr;
	while (ft_definition(&num, fd) > 0)
	{
		tmp = ptr;
		ptr->next = ft_newtetr(num,c++);
		ptr = ptr->next;
		ptr->prev = tmp;
	}
	ptr->next = ft_newtetr(num,c++);
	ptr = ptr->next;
	ptr = ft_tostart(ptr);
	ft_solve(start, 2 * ft_sqrt(ft_listlen(start)));
	// num = 1;
	// while (1)
	// {
	// 	ft_print(ptr->line, 0);
	// 	ft_putchar('\n');
	// 	printf("valid tetr = %c \n", ptr->c);
	// 	if (ptr->prev == NULL)
	// 		break ;
	// 	ptr = ptr->prev;
	// 	num++;
	// }
	// printf("len = %d\n", ft_listlen(ptr));

	// ft_putnbr(num);
	// int b;
	// b = 0b1000100010001000;  // Или любое другое
	// ft_putchar('\n');
	// ft_print(b);
	
	close(fd);
	return (1);
}
