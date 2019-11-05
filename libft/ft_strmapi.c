/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:16:56 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/09/18 23:50:41 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str_new;

	if (s == NULL)
		return (NULL);
	str_new = NULL;
	i = 0;
	str_new = (char*)malloc(ft_strlen(s) + 1);
	if (str_new == NULL)
		return (NULL);
	while (s[i])
	{
		str_new[i] = (*f)(i, s[i]);
		i++;
	}
	str_new[i] = 0;
	return (str_new);
}
