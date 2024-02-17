/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:43:06 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/17 15:19:46 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_right(t_data *data)
{
	if (data->map[data->player_x][data->player_y + 1] == '0')
	{
		data->map[data->player_x][data->player_y] = '0';
		data->map[data->player_x][data->player_y + 1] = 'P';
		data->player_y++;
		data->moves++;
		data->flag = 1;
		mlx_clear_window(data->mlx, data->mlx_win);
		ft_draw_elements(data);
	}
	else if (data->map[data->player_x][data->player_y + 1] == 'C')
	{
		data->map[data->player_x][data->player_y] = '0';
		data->map[data->player_x][data->player_y + 1] = 'P';
		data->player_y++;
		data->moves++;
		data->flag = 1;
		mlx_clear_window(data->mlx, data->mlx_win);
		ft_draw_elements(data);
		data->collectives--;
	}
	else if (data->map[data->player_x][data->player_y + 1] == 'E'
		&& data->collectives == 0)
		data->player_y++;
	ft_check_exit(data);
}

void	ft_left(t_data *data)
{
	if (data->map[data->player_x][data->player_y - 1] == '0')
	{
		data->map[data->player_x][data->player_y] = '0';
		data->map[data->player_x][data->player_y - 1] = 'P';
		data->player_y--;
		data->moves++;
		data->flag = -1;
		mlx_clear_window(data->mlx, data->mlx_win);
		ft_draw_elements(data);
	}
	else if (data->map[data->player_x][data->player_y - 1] == 'C')
	{
		data->map[data->player_x][data->player_y] = '0';
		data->map[data->player_x][data->player_y - 1] = 'P';
		data->player_y--;
		data->moves++;
		mlx_clear_window(data->mlx, data->mlx_win);
		ft_draw_elements(data);
		data->collectives--;
	}
	else if (data->map[data->player_x][data->player_y - 1] == 'E'
		&& data->collectives == 0)
		data->player_y--;
	ft_check_exit(data);
}

void	ft_up(t_data *data)
{
	if (data->map[data->player_x - 1][data->player_y] == '0')
	{
		data->map[data->player_x][data->player_y] = '0';
		data->map[data->player_x - 1][data->player_y] = 'P';
		data->player_x--;
		data->moves++;
		mlx_clear_window(data->mlx, data->mlx_win);
		ft_draw_elements(data);
	}
	else if (data->map[data->player_x - 1][data->player_y] == 'C')
	{
		data->map[data->player_x][data->player_y] = '0';
		data->map[data->player_x - 1][data->player_y] = 'P';
		data->player_x--;
		data->moves++;
		mlx_clear_window(data->mlx, data->mlx_win);
		ft_draw_elements(data);
		data->collectives--;
	}
	else if (data->map[data->player_x - 1][data->player_y] == 'E'
		&& data->collectives == 0)
		data->player_x--;
	ft_check_exit(data);
}

void	ft_down(t_data *data)
{
	if (data->map[data->player_x + 1][data->player_y] == '0')
	{
		data->map[data->player_x][data->player_y] = '0';
		data->map[data->player_x + 1][data->player_y] = 'P';
		data->player_x++;
		data->moves++;
		mlx_clear_window(data->mlx, data->mlx_win);
		ft_draw_elements(data);
	}
	else if (data->map[data->player_x + 1][data->player_y] == 'C')
	{
		data->map[data->player_x][data->player_y] = '0';
		data->map[data->player_x + 1][data->player_y] = 'P';
		data->player_x++;
		data->moves++;
		mlx_clear_window(data->mlx, data->mlx_win);
		ft_draw_elements(data);
		data->collectives--;
	}
	else if (data->map[data->player_x + 1][data->player_y] == 'E'
		&& data->collectives == 0)
		data->player_x++;
	ft_check_exit(data);
}

int	ft_key_hook(int keycode, t_data *data)
{
	if (keycode == 124)
		ft_right(data);
	else if (keycode == 123)
		ft_left(data);
	else if (keycode == 126)
		ft_up(data);
	else if (keycode == 125)
		ft_down(data);
	else if (keycode == 53)
		ft_esc(data);
	return (0);
}
