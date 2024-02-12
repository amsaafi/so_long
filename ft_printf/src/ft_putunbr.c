/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:27:44 by samsaafi          #+#    #+#             */
/*   Updated: 2023/12/24 19:29:07 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	cnt;

	cnt = 0;
	if (n > 9)
	{
		cnt += ft_putnbr(n / 10);
		cnt += ft_putnbr(n % 10);
	}
	else
		cnt += ft_putchar(n + '0');
	return (cnt);
}
