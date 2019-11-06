/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:31:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/06 20:02:52 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#define SIZE 16
#define SIZE_R 21
typedef struct	s_tetr
{
	int				*line;
	int				x;
	int				y;
	struct s_tetr	*next;
}				t_tetr;

t_tetr 	*ft_newter(int len)
{
	t_tetr *ptr;

	if ((ptr = (t_tetr*)malloc(sizeof(t_tetr))) == NULL)
		return (NULL);
	if ((ptr->line = (int*)malloc(sizeof(int) * len)) == NULL)
		{
			free(ptr);
			return (NULL);
		}
	return (ptr);
}

int		ft_definition(t_tetr **ptr, int fd)
{
	int		i;
	char	*c;
	char	r;
	int		num;

	c = ft_strnew(SIZE_R);
	if ((*ptr = ft_newter(SIZE)) == NULL)
		return (-1);
	if (read(fd, c, SIZE_R) < 0)
		return (-1);
	c[SIZE_R] = 0;
	i = 0;
	while (i < SIZE)
	{
		if (*c == '\n' && i % 4 == 0)
		{
			c++;
			continue ;
		}
		if (*c != '.' && *c != '#')
			return (-1);
		(*ptr)->line[i] = (*c == '.') ? 0 : 1;
		i++;
		c++;
 	}
	num = read(fd, &r, 1);
	if (r != '\n' && i < SIZE - 1)
		return (-1);
	return (num);
}

void	ft_putint(int *mas, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i++ < len)
		ft_putnbr(*(mas++));
}

int main(int ac, char **av)
{
	ac = 1;
	int fd = open(av[1], O_RDONLY);
	t_tetr *ptr = NULL;

	ft_putnbr(ft_definition(&ptr, fd));
	ft_putchar('\n');
	ft_putint(ptr->line, SIZE);
	close(fd);
	return (1);
}