/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:44:26 by samsaafi          #+#    #+#             */
/*   Updated: 2023/12/24 19:33:44 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_format(char format, va_list argslst)
{
	int	cnt;

	cnt = 0;
	if (format == '%')
		return (cnt += ft_putchar('%'));
	else if (format == 'c')
		cnt += ft_putchar(va_arg(argslst, int));
	else if (format == 's')
		cnt += ft_putstr(va_arg(argslst, char *));
	else if (format == 'd' || format == 'i')
		cnt += ft_putnbr(va_arg(argslst, int));
	else if (format == 'u')
		cnt += ft_putunbr(va_arg(argslst, unsigned int));
	else if (format == 'x')
		cnt += ft_puthex(va_arg(argslst, unsigned int));
	else if (format == 'X')
		cnt += ft_puthex_upper(va_arg(argslst, unsigned int));
	else if (format == 'p')
	{
		cnt += ft_putstr("0x");
		cnt += ft_puthex((unsigned long long)va_arg(argslst, void *));
	}
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_check_format(format[i + 1], args);
			i++;
		}
		else
		{
			count += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
