/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:08:51 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/17 15:21:13 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_esc(t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}

void	ft_get_exit_demensions(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map_h)
	{
		y = 0;
		while (y < data->map_w)
		{
			if (data->map[x][y] == 'E')
			{
				data->exit_x = x;
				data->exit_y = y;
			}
			y++;
		}
		x++;
	}
}

void	ft_check_exit(t_data *data)
{
	printf("Move: %d\n", data->moves);
	if ((data->player_x == data->exit_x && data->player_y == data->exit_y)
		&& data->collectives == 0)
	{
		data->map[data->player_x][data->player_y] = '0';
		data->moves++;
		printf("Move: %d\n", data->moves);
		ft_printf("\033[92mHOLLLLLLLLEY YOU WIN :)\n\033[92m");
		ft_esc(data);
	}
}
