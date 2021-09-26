/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsanchez <dsanchez@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 19:40:48 by dsanchez          #+#    #+#             */
/*   Updated: 2021/09/26 20:55:30 by dsanchez         ###   ########.fr       */
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
	size_t	width;
	int		just_left;
}					t_flags;

int	ft_putchar(char c);
int	ft_putstr(char *c, t_flags *flags);
int	ft_printf(const char *format, ...);

#endif
