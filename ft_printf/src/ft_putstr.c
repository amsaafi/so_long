/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:44:18 by samsaafi          #+#    #+#             */
/*   Updated: 2023/12/19 11:40:20 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *str)
{
	int	cnt;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	cnt = 0;
	while (str[cnt])
	{
		ft_putchar(str[cnt]);
		cnt++;
	}
	return (cnt);
}
