/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:56:39 by dsanchez          #+#    #+#             */
/*   Updated: 2021/09/28 20:14:49 by dsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_putc(int c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int nbr, t_flags *flags)
{
	unsigned int	n;
	int				c;

	c = 0;
	if (nbr < 0)
	{
		c += write(1, "-", 1);
		n = (unsigned int) nbr * -1;
	}
	else
		n = (unsigned int) nbr;
	if (n >= 10 )
	{
		c += ft_putnbr (n / 10, flags);
		c += ft_putnbr (n % 10, flags);
	}
	else
		c += ft_putc(n + '0');
	return (c);
}
