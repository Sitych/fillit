/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:54:20 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/09/18 23:45:25 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	str1 = (unsigned char*)dest;
	str2 = (unsigned char*)src;
	while (n-- != 0)
	{
		if ((*str1 = *str2) == (unsigned char)c)
			return (str1 + 1);
		str1++;
		str2++;
	}
	return (NULL);
}
