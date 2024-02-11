/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 01:43:06 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/11 14:07:09 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_right(t_data *data)
{
    if (data->map[data->player_X][data->player_Y + 1] == '0')
    {
        data->map[data->player_X][data->player_Y] = '0';
        data->map[data->player_X][data->player_Y + 1] = 'P';
        data->player_Y++;
        data->moves++;
        data->flag = 1;
        mlx_clear_window(data->mlx, data->mlx_win);
        ft_draw_elements(data);
    }
    else if (data->map[data->player_X][data->player_Y + 1] == 'C')
    {
        data->map[data->player_X][data->player_Y] = '0';
        data->map[data->player_X][data->player_Y + 1] = 'P';
        data->player_Y++;
        data->moves++;
        data->flag = 1;
        mlx_clear_window(data->mlx, data->mlx_win);
        ft_draw_elements(data);
        data->collectives--;
    }
}

void    ft_left(t_data *data)
{
    if (data->map[data->player_X][data->player_Y - 1] == '0')
    {
        data->map[data->player_X][data->player_Y] = '0';
        data->map[data->player_X][data->player_Y - 1] = 'P';
        data->player_Y--;
        data->moves++;
        data->flag = -1;
        mlx_clear_window(data->mlx, data->mlx_win);
        ft_draw_elements(data);
    }
    else if (data->map[data->player_X][data->player_Y - 1] == 'C')
    {
        data->map[data->player_X][data->player_Y] = '0';
        data->map[data->player_X][data->player_Y - 1] = 'P';
        data->player_Y--;
        data->moves++;
        mlx_clear_window(data->mlx, data->mlx_win);
        ft_draw_elements(data);
        data->collectives--;
    }
}

void    ft_up(t_data *data)
{
    if (data->map[data->player_X - 1][data->player_Y] == '0')
    {
        data->map[data->player_X][data->player_Y] = '0';
        data->map[data->player_X - 1][data->player_Y] = 'P';
        data->player_X--;
        data->moves++;
        mlx_clear_window(data->mlx, data->mlx_win);
        ft_draw_elements(data);
    }
    else if (data->map[data->player_X - 1][data->player_Y] == 'C')
    {
        data->map[data->player_X][data->player_Y] = '0';
        data->map[data->player_X - 1][data->player_Y] = 'P';
        data->player_X--;
        data->moves++;
        mlx_clear_window(data->mlx, data->mlx_win);
        ft_draw_elements(data);
        data->collectives--;
    }
}

void    ft_down(t_data *data)
{
    if (data->map[data->player_X + 1][data->player_Y] == '0')
    {
        data->map[data->player_X][data->player_Y] = '0';
        data->map[data->player_X + 1][data->player_Y] = 'P';
        data->player_X++;
        data->moves++;
        mlx_clear_window(data->mlx, data->mlx_win);
        ft_draw_elements(data);
    }
    else if (data->map[data->player_X + 1][data->player_Y] == 'C')
    {
        data->map[data->player_X][data->player_Y] = '0';
        data->map[data->player_X + 1][data->player_Y] = 'P';
        data->player_X++;
        data->moves++;
        mlx_clear_window(data->mlx, data->mlx_win);
        ft_draw_elements(data);
        data->collectives--;
    }
}

int ft_key_hook(int keycode, t_data *data)
{
    if (keycode == 124)
    {
        ft_right(data);
        return (0);
    }
    else if (keycode == 123)
    {
        ft_left(data);
        return (0);
    }
    else if (keycode == 126)
    {
        ft_up(data);
        return (0);
    }
    else if (keycode == 125)
    {
        ft_down(data);
        return (0);
    }
    return (0);
}
