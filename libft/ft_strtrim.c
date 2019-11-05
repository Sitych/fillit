/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:36:59 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/09/18 23:50:41 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	char	*new_str;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	new_str = NULL;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
			&& len != 0)
		len--;
	if (len == 0)
		i = 0;
	new_str = (char*)ft_memalloc(len - i + 1);
	if (new_str == NULL)
		return (NULL);
	ft_strlcat(new_str, s + i, len - i + 1);
	return (new_str);
}
