/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:09:42 by dsanchez          #+#    #+#             */
/*   Updated: 2021/09/26 21:08:34 by dsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "printf.h"
#include <stdio.h>


int	conversion_format(const char *format, va_list a_list, t_flags *flags)
{
	int	i;

	if (*format == 'c')
		i = ft_putchar(va_arg(a_list, int));
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
	while (!ft_strnstr("cs", &format[i], 2))
	{
		if (format[i] == '-')
		{
			flags->just_left = 1;
			i++;
		}
		if (ft_atoi(&format[i]))
		{
			flags->width = ft_atoi(&format[i]);
			i += num_len(flags->width);
		}
	}
	return (i);
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
			i += get_flags(&format[i + 1], flags);
			c += conversion_format(&format[i + 1], a_list, flags);
			i++;
		}else
			write(1, &format[i], 1);
		i++;
	}
	va_end(a_list);
	return (c);
}

int	main()
{
	//char	*p = "hola";

	//printf("hola %12s %3253172s", "M");
	//ft_printf("Hola %c%c%c%c%c\n", 'M', 'u', 'n', 'd', 'o');
	ft_printf("Hola %13s\n", "Mundo");
	ft_printf("Hola %3s\n", "Mundo");
	return (0);
}
