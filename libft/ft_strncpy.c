/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 22:21:01 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/09/18 23:45:25 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *str;
	char *src1;

	if (dst == src)
		return (dst);
	str = (char*)dst;
	src1 = (char*)src;
	while (n != 0 && *src1)
	{
		*str++ = *src1++;
		n--;
	}
	while (n-- != 0)
		*str++ = 0;
	return (dst);
}
