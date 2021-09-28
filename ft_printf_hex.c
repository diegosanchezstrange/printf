/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:19:33 by dsanchez          #+#    #+#             */
/*   Updated: 2021/09/28 21:38:42 by dsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putnbr_x(int n, t_flags *flags)
{
	unsigned int	nbr;
	int				t;
	int				c;
	char			*base;

	nbr = (unsigned int)n;
	c = 0;
	base = "0123456789abcdef";
	if (nbr < 16)
	{
		c += write(1, &base[nbr], 1);
	}
	else
	{
		t = nbr % 16;
		c += ft_putnbr_x(nbr / 16, flags);
		c += write(1, &base[t], 1);
	}
	return (c);
}

int	ft_putnbr_X(int n, t_flags *flags)
{
	unsigned int	nbr;
	int				t;
	int				c;
	char			*base;

	nbr = (unsigned int)n;
	c = 0;
	base = "0123456789ABCDEF";
	if (nbr < 16)
	{
		c += write(1, &base[nbr], 1);
	}
	else
	{
		t = nbr % 16;
		c += ft_putnbr_X(nbr / 16, flags);
		c += write(1, &base[t], 1);
	}
	return (c);
}

int	ft_putnbr_p(int n, t_flags *flags)
{
	write(1, "0x", 2);
	return (ft_putnbr_x(n, flags));
}
