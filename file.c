/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:31:16 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/07 19:30:55 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#define SIZE	16
#define SIZE_R	20
#define COORD	8
typedef struct		s_tetr
{
	int				*coordinates;
	int				*line;
	struct s_tetr	*next;
	struct s_tetr	*prev;
}					t_tetr;

t_tetr 	*ft_newtetr(int len, int crds)
{
	t_tetr *ptr;

	ptr = (t_tetr*)malloc(sizeof(t_tetr));
	if (ptr == NULL)
		return (NULL);
	ptr->line = (int*)malloc(sizeof(int) * len);
	if (ptr->line == NULL)
		{
			free(ptr);
			return (NULL);
		}
	ptr->coordinates = (int*)malloc(sizeof(int) * crds);
	if (ptr->coordinates == NULL)
	{
		free(ptr->line);
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

int		ft_newstrdel(char **s)
{
	if (s == NULL)
		return (0);
	free(*s);
	*s = NULL;
	return (-1);
}

int		ft_validsquare(char *tetr)
{
	int		i;
	
	i = 0;
	while (i < SIZE)
	{
		if (*(tetr++) == '\n' && i % 4 == 0)
			continue ;
		if (*(tetr - 1) != '.' && *(tetr - 1) != '#')
			return (-1);
		i++;
	}
	return (1);
}

int		ft_binarysquare(char *tetr, t_tetr **ptr)
{
	int	i;
	int	j;

	if (*ptr == NULL)
		return (-1);
	i = 0;
	while (i < SIZE / 4)
	{
		j = 0;
		while (j < SIZE / 4)
		{
			(*ptr)->line[i * SIZE / 4 + j] = (*tetr == '.') ? 0 : 1;
			if (*tetr == '#')
			{	
				*((*ptr)->coordinates++) = j;
				*(*ptr)->coordinates = i;
			}
			tetr = (*(tetr + 1) == '\n') ? tetr + 2: tetr + 1;
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_definition(t_tetr **ptr, int fd)
{
	char	*c;
	char	r;
	int		num;

	c = ft_strnew(SIZE_R);
	if (read(fd, c, SIZE_R) < 0)
		return (ft_newstrdel(&c));
	c[SIZE_R] = 0;
	if (ft_validsquare(c) == -1)
		return (ft_newstrdel(&c));
	num = read(fd, &r, 1);
	if (r != '\n')
		return (ft_newstrdel(&c));
	if (ft_binarysquare(c, ptr) == -1)
		return (ft_newstrdel(&c));
	ft_newstrdel(&c);
	return (num);
}

void	ft_putnubrs(int *mas, int len)
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

	ptr = ft_newtetr(SIZE, COORD);
	ptr->next = ft_newtetr(SIZE, COORD);
	ft_putnbr(ft_definition(&ptr, fd));
	ft_putchar('\n');
	ft_putnubrs(ptr->line, SIZE);
	ft_putchar('\n');
	ft_putnubrs(ptr->coordinates, SIZE / 2);
	// ft_putnbr(ft_definition(&ptr->next, fd));
	// ft_putchar('\n');
	// ft_putnubrs(ptr->next->line, SIZE);
	// ft_putchar('\n');
	// ft_putnubrs(ptr->next->coordinates, SIZE);
	// close(fd);
	return (1);
}