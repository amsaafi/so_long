/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:43:52 by samsaafi          #+#    #+#             */
/*   Updated: 2023/12/19 18:38:47 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_puthex(unsigned long n)
{
	int		cnt;
	char	*values;

	cnt = 0;
	values = "0123456789abcdef";
	if (n >= 16)
	{
		cnt += ft_puthex(n / 16);
		cnt += ft_puthex(n % 16);
	}
	else
	{
		cnt += ft_putchar(values[n]);
	}
	return (cnt);
}
