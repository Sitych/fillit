/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 11:42:53 by qjosmyn           #+#    #+#             */
/*   Updated: 2019/09/18 23:50:41 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int nbr;

	if (n < 0)
	{
		nbr = (-1) * n;
		ft_putchar('-');
	}
	else
		nbr = n;
	if (nbr == 2147483648)
	{
		ft_putchar('2');
		ft_putnbr(147483648);
		return ;
	}
	else
	{
		if (nbr >= 10)
			ft_putnbr(nbr / 10);
		ft_putchar(nbr % 10 + 48);
	}
	return ;
}
