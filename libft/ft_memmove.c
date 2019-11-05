/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:09:17 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/09/18 23:50:41 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *str;
	char *str1;

	str = (char*)dest;
	str1 = (char*)src;
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	else
	{
		str = str + n;
		str1 = str1 + n;
		while (n-- != 0)
			*(--str) = *(--str1);
	}
	return (dest);
}
