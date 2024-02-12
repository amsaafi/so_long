/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:46:48 by samsaafi          #+#    #+#             */
/*   Updated: 2023/12/25 18:46:51 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex_upper(unsigned long n)
{
	int		cnt;
	char	*values;

	cnt = 0;
	values = "0123456789ABCDEF";
	if (n >= 16)
	{
		cnt += ft_puthex_upper(n / 16);
		cnt += ft_puthex_upper(n % 16);
	}
	else
	{
		cnt += ft_putchar(values[n]);
	}
	return (cnt);
}
