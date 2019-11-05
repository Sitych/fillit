/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:16:31 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/09/18 23:50:41 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	size_t	ft_intlen(int n)
{
	unsigned int	nbr;
	size_t			i;

	nbr = n;
	i = 1;
	if (n < 0)
		nbr = -n;
	while (nbr > 9)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static	char	*ft_revers_str(char *str)
{
	size_t	i;
	size_t	len;
	char	buf;

	len = ft_strlen(str) - 1;
	i = 0;
	while (i <= len / 2)
	{
		buf = str[i];
		str[i] = str[len - i];
		str[len - i] = buf;
		i++;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	size_t			len;
	size_t			i;
	char			*str;
	unsigned int	nbr;

	i = 0;
	len = ft_intlen(n);
	if (n >= 0)
		nbr = n;
	else
		nbr = -n;
	str = (char*)ft_memalloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		*str++ = '0' + nbr % 10;
		nbr = nbr / 10;
		i++;
	}
	*str = n >= 0 ? *str : '-';
	str = str - len;
	return (ft_revers_str(str));
}
