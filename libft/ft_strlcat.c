/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:51:19 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/09/18 23:50:41 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	char	*buf;
	size_t	len;
	size_t	len1;

	buf = dest;
	len = ft_strlen(buf);
	len1 = ft_strlen(src);
	buf = buf + len;
	if (len >= n)
		return (n + ft_strlen(src));
	n = n - len - 1;
	while (*src && n != 0)
	{
		ft_memset(buf, *src, 1);
		buf++;
		src++;
		n--;
	}
	*buf = 0;
	return (len + len1);
}
