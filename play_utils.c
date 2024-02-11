/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:08:51 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/11 17:00:32 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_esc(t_data *data)
{
    mlx_clear_window(data->mlx, data->mlx_win);
    mlx_destroy_window(data->mlx, data->mlx_win);
    exit(1);
}

void    ft_check_exit(t_data *data)
{
    printf("player X : %d / player Y : %d \n", data->player_X, data->player_Y);
    if (((data->map[data->player_X][data->player_Y + 1] == 'E') ||
    (data->map[data->player_X][data->player_Y - 1] == 'E') ||
    (data->map[data->player_X + 1][data->player_Y] == 'E') ||
    (data->map[data->player_X - 1][data->player_Y] == 'E')) && data->collectives == 0)
    {
        data->map[data->player_X][data->player_Y] = '0';
        data->player_Y++;
        printf("\nafter\n\nplayer X : %d / player Y : %d \n", data->player_X, data->player_Y);
        data->moves++;
        ft_putstr("HOLLLLLLLLEY YOU WIN :)\n");
        ft_esc(data);
    }
}

// void    ft_check_fire(t_data *data)
// {
//     if (data->map[data->player_X][data->player_Y + 1] == 'F')
//     {
//         data->map[data->player_X][data->player_Y] = '0';
//         data->player_Y++;
//         data->moves++;
//         ft_putstr("HOLLLLLLLLEY YOU WIN :)\n");
//         ft_esc(data);
//     }
// }
