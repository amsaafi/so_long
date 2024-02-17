/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:50:34 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/17 15:30:06 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_elements(t_data *data)
{
	ft_draw_walls_floor(data);
	ft_draw_exit(data);
	ft_draw_player(data);
	ft_draw_collec(data);
	ft_draw_killer(data);
}

void	ft_draw_map(t_data *data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->map_w * 50, data->map_h
			* 50, "So_______LONG");
	data->flag = 1;
	data->exit_xpm = mlx_xpm_file_to_image(data->mlx, "./textures/exit.xpm",
			&data->img_w, &data->img_h);
	data->player_xpm = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm",
			&data->img_w, &data->img_h);
	data->colec_xpm = mlx_xpm_file_to_image(data->mlx, "./textures/colec.xpm",
			&data->img_w, &data->img_h);
	data->floor_xpm = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm",
			&data->img_w, &data->img_h);
	data->wall_xpm = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm",
			&data->img_w, &data->img_h);
	data->player_left_xpm = mlx_xpm_file_to_image(data->mlx,
			"./textures/player-left.xpm", &data->img_w, &data->img_h);
	data->fire_xpm = mlx_xpm_file_to_image(data->mlx, "./textures/fire.xpm",
			&data->img_w, &data->img_h);
	ft_draw_elements(data);
}

void	ft_player(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'P' && data->flag == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor_xpm, x
			* 50, y * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_xpm, x
			* 50, y * 50);
	}
	else if (data->map[y][x] == 'P' && data->flag == -1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor_xpm, x
			* 50, y * 50);
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_left_xpm,
			x * 50, y * 50);
	}
}
