/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:31:11 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/09/18 23:50:41 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*str;
	size_t	len;

	len = ft_strlen(haystack);
	str = (char *)haystack;
	if (*needle == 0)
		return (str);
	else if (n == 0 || len < ft_strlen(needle))
		return (NULL);
	while (n != 0 && *str)
	{
		if (n < ft_strlen(needle))
			break ;
		if (!ft_strncmp(str, needle, ft_strlen(needle))
		|| ft_strncmp(str, needle, ft_strlen(needle)) == needle[0])
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
