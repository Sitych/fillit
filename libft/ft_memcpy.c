/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 13:38:59 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/11/05 18:26:50 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *str;
	char *src1;

	if (dst == src)
		return (dst);
	str = (char*)dst;
	src1 = (char*)src;
	while (n-- != 0)
		*str++ = *src1++;
	return (dst);
}
