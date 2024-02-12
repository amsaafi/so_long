/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:52:52 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/12 23:12:28 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char *av[])
{
    t_data data;

	if (ac != 2)
	{
		ft_printf("\033[91mONLY NEED 2 VALID PARAM!\033[91m\n");
		exit(1);
	}
    ft_memset(&data, 0, sizeof(data));
    check_path_format(av[1]);
    ft_fill_map(av[1], &data);
	validate_map(&data);
    ft_draw_map(&data);
    mlx_key_hook(data.mlx_win,ft_key_hook, &data);
    mlx_hook(data.mlx_win, 17, 0, ft_esc, &data);
    ft_printf("*************** main.c leaks ****************\n");
    system("leaks so_long");
    mlx_loop(data.mlx);
}
