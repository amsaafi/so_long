/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:09:06 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/11 19:45:38 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_is_Playable(t_data *data)
{
    int x;
    int y;

    ft_flood_fill(data);   
    x = 0;
    while (x < data->map_H)
    {
        y = 0;
        while (y < data->map_W)
        {
            if (data->map_flood[x][y] == 'E' || data->map_flood[x][y] == 'C')
            {
                ft_putstr("THE MAP IS UNPLAYABLE!\n");
                exit(1);
            }
            y++;
        }
        x++;
    }
    ft_Not_game(data);
}

void    ft_Not_game(t_data *data)
{
    int x;
    int y;
    
    ft_flood_fill_colec(data);   
    x = 0;
    while (x < data->map_H)
    {
        y = 0;
        while (y < data->map_W)
        {
            if (data->map_flood_colec[x][y] == 'C')
            {
                ft_putstr("YOU CAN NOT PLAY THIS GAME.\n");
                int i = 0;
                while (data->map_flood_colec[i])
                {
                    printf("%s", data->map_flood_colec[i]);
                    i++;
                }
                exit(1);
            }
            y++;
        }
        x++;
    }
}
