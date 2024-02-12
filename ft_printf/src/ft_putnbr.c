/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:43:55 by samsaafi          #+#    #+#             */
/*   Updated: 2023/12/19 17:37:19 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnbr(int n)
{
	int	cnt;

	cnt = 0;
	if (n == -2147483648)
	{
		cnt += ft_putstr("-2147483648");
		return (cnt);
	}
	if (n < 0)
	{
		cnt += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		cnt += ft_putnbr(n / 10);
		cnt += ft_putnbr(n % 10);
	}
	else
		cnt += ft_putchar(n + '0');
	return (cnt);
}
