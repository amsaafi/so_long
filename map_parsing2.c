/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 22:09:06 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/07 23:27:44 by samsaafi         ###   ########.fr       */
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
}
