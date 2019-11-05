/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 08:42:02 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/09/19 09:10:00 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;
	char	*str;

	len = ft_strlen(needle);
	str = (char *)haystack;
	while (*str)
	{
		if (!ft_memcmp(str, needle, len))
			return (str);
		str++;
	}
	if (*str == *needle)
		return (str);
	return (NULL);
}
