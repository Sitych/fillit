/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:54:34 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/09/18 23:50:41 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	char	*str;

	str = (char*)s;
	new_str = NULL;
	new_str = (char*)malloc(len + 1);
	if (new_str == NULL || (void*)(len + 1) == NULL || s == NULL)
		return (NULL);
	ft_strncpy(new_str, str + start, len);
	*(new_str + len) = 0;
	return (new_str);
}
