/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:40:48 by dsanchez          #+#    #+#             */
/*   Updated: 2021/09/28 21:33:30 by dsanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int	width;
	int	just_left;
	int	prec;
}					t_flags;

int	ft_putchar(char c, t_flags *flags);
int	ft_putstr(char *c, t_flags *flags);
int	ft_putnbr(int nbr, t_flags *flags);
int	ft_putnbr_p(int n, t_flags *flags);
int	ft_putnbr_x(int n, t_flags *flags);
int	ft_putnbr_X(int n, t_flags *flags);
int	ft_printf(const char *format, ...);

#endif
