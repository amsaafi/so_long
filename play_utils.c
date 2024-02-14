/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:08:51 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/14 15:24:09 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_esc(t_data *data)
{
    mlx_clear_window(data->mlx, data->mlx_win);
    mlx_destroy_window(data->mlx, data->mlx_win);
    exit(0);
    return (0);
}

void    ft_get_exit_demensions(t_data *data)
{
    int x;
    int y;

    x = 0;
    while (x < data->map_H)
    {
        y = 0;
        while (y < data->map_W)
        {
            if (data->map[x][y] == 'E')
            {
                data->exit_X = x;
                data->exit_Y = y;
            }
            y++;
        }
        x++;
    }
   
}



void    ft_check_exit(t_data *data)
{
    printf("Move: %d\n",data->moves);
    if ((data->player_X == data->exit_X && data->player_Y == data->exit_Y) && data->collectives == 0)
    {
        data->map[data->player_X][data->player_Y] = '0';
        data->moves++;
        printf("Move: %d\n",data->moves);
        ft_printf("\033[92mHOLLLLLLLLEY YOU WIN :)\n\033[92m");
        ft_esc(data);
    }
}

// void    ft_check_fire(t_data *data)
// {
//     if (data->map[data->player_X][data->player_Y + 1] == 'F' ||
//     data->map[data->player_X][data->player_Y - 1] == 'F' ||
//     data->map[data->player_X + 1][data->player_Y] == 'F' ||
//     data->map[data->player_X - 1][data->player_Y] == 'F')
//     {
//         printf("Move: %d\n",data->moves);
//         mlx_clear_window(data->mlx, data->mlx_win);
//         mlx_destroy_window(data->mlx, data->mlx_win);
//         ft_printf("\033[91mOoooops!!! YOU LOSE :(\n\033[91m");
//         exit(1);
//     }
// }
