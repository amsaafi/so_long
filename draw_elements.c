/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:23:30 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/17 17:02:34 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_walls_floor(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (!data->wall_xpm || !data->floor_xpm)
		exit(1);
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->wall_xpm, x * 50, y * 50);
			if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->floor_xpm, x * 50, y * 50);
			x++;
		}
		y++;
	}
}

void	ft_draw_exit(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (!data->exit_xpm)
		exit(1);
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			if (data->map[y][x] == 'E')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->floor_xpm, x * 50, y * 50);
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->exit_xpm, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}

void	ft_draw_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (!data->player_xpm || !data->player_left_xpm)
		exit(1);
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			ft_player(data, x, y);
			x++;
		}
		y++;
	}
}

void	ft_draw_collec(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	if (!data->colec_xpm)
		exit(1);
	while (y < data->map_h)
	{
		x = 0;
		while (x < data->map_w)
		{
			if (data->map[y][x] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->floor_xpm, x * 50, y * 50);
				mlx_put_image_to_window(data->mlx, data->mlx_win,
					data->colec_xpm, x * 50, y * 50);
			}
			x++;
		}
		y++;
	}
}
