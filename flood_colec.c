/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_colec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:06:00 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/11 19:56:44 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_dup_map_colec(t_data *data)
{
    int i;

    i = 0;
    data->map_flood_colec = (char **)malloc(data->map_H * sizeof(char *));
    if (!data->map_flood_colec)
        exit(1);
    while (i < data->map_H)
    {
        data->map_flood_colec[i] = ft_strdup(data->map[i]);
        if (!data->map_flood_colec[i])
            exit(1);
        i++;
    }
}

void ft_fill_colec(t_data *data, int x, int y)
{
    if (x < 0 || x >= data->map_H || y < 0 || y >= data->map_W)
        return;
    if (data->map_flood[x][y] == 'W')
        return;
    if (data->map_flood[x][y] != '1' && data->map_flood[x][y] != 'E')
    {
        data->map_flood[x][y] = 'W';
        ft_fill_colec(data, x - 1, y);
        ft_fill_colec(data, x + 1, y);
        ft_fill_colec(data, x, y - 1);
        ft_fill_colec(data, x, y + 1);
        ft_putstr("Rec\n");
    }
    ft_putstr("finished\n");
}

void    ft_flood_fill_colec(t_data *data)
{
    ft_dup_map_colec(data);
    ft_get_player_demensions(data);
    ft_fill_colec(data, data->player_X, data->player_Y);
    ft_putstr("here00\n");
}
