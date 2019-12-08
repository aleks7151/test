/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:49:23 by acarlett          #+#    #+#             */
/*   Updated: 2019/09/18 18:40:43 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	char	a;
	int		b;

	if (nb < 0)
	{
		ft_putchar('-');
		if (nb < -2000000000)
		{
			ft_putchar('2');
			nb = nb + 2000000000;
		}
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	b = nb % 10;
	a = '0' + b;
	ft_putchar(a);
}
