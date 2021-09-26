/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 18:35:43 by dsanchez          #+#    #+#             */
/*   Updated: 2021/09/26 21:11:45 by dsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str, t_flags *flags)
{
	size_t	i;
	int		c;
	int		s;

	i = 0;
	s = 0;
	c = 0;
	if (flags->width > ft_strlen(str))
		s = flags->width - ft_strlen(str);
	while (s > c)
	{
		write(1, " ", 1);
		c++;
	}
	while (str[i] && i < c)
		i += write(1, &str[i], 1);
	return (i);
}
