/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:09:42 by dsanchez          #+#    #+#             */
/*   Updated: 2021/09/27 21:41:49 by dsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>


int	conversion_format(const char *format, va_list a_list, t_flags *flags)
{
	int	i;

	if (*format == 'c')
		i = ft_putchar(va_arg(a_list, int), flags);
	else if (*format == 's')
		i = ft_putstr(va_arg(a_list, char*), flags);
	else
		i = 0;
	return (i);
}

int	num_len(int n)
{
	int	c;

	c = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

int	get_flags(const char *format, t_flags *flags)
{
	int	i;

	i = 0;
	while (!ft_strchr("cs", format[i]))
	{
		printf("\nc : %c\n", format[i]);
		if (format[i] == '-')
		{
			flags->just_left = 1;
			i++;
		}
		if (ft_atoi(&format[i]) >= 0)
		{
			flags->width = ft_atoi(&format[i]);
			i += num_len(flags->width);
		}
		if (format[i] == '.')
		{
			flags->prec = ft_atoi(&format[++i]);
			i += num_len(flags->prec);
		}
	}
	return (i);
}

void	init_flags(t_flags *flags)
{
	flags->width = -1;
	flags->prec = -1;
	flags->just_left = 0;
}

int ft_printf(const char *format, ...)
{
	va_list	a_list;
	t_flags	*flags;
	int		i;
	int		c;

	va_start(a_list, format);
	i = 0;
	c = 0;
	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (0);
	while (format[i])
	{
		if (format[i] == '%')
		{
			init_flags(flags);
			printf("i : %d", i);
			i += get_flags(&format[i + 1], flags);
			printf("i : %d", i);
			c += conversion_format(&format[i + 1], a_list, flags);
			i++;
		}else
			c += write(1, &format[i], 1);
		i++;
	}
	free(flags);
	va_end(a_list);
	return (c);
}

