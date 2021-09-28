/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 19:53:46 by dsanchez          #+#    #+#             */
/*   Updated: 2021/09/28 19:55:27 by dsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c, t_flags *flags)
{
	int	n;

	n = 0;
	while (flags->width > 1 && !flags->just_left)
	{
		n += write(1, " ", 1);
		flags->width--;
	}
	if (flags->width > 0 || flags->width == -1)
	{
		n += write(1, &c, 1);
		flags->width--;
	}
	while (flags->width > 0)
	{
		n += write(1, " ", 1);
		flags->width--;
	}
	return (n);
}

int	ft_putstr(char *str, t_flags *flags)
{
	int	i;
	int	n;
	int	l;

	i = 0;
	n = 0;
	l = (int)ft_strlen(str);
	if (!str)
		return (write(1, "(null)", 6));
	if (flags->width == 0)
		return (0);
	while (flags->width > l && !flags->just_left)
	{
		n += write(1, " ", 1);
		flags->width--;
	}
	while (str[i])
		n += write(1, &str[i++], 1);
	while (flags->width > (int)l && flags->just_left )
	{
		n += write(1, " ", 1);
		flags->width--;
	}
	return (n);
}
