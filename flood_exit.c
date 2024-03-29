/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:06:00 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/17 15:17:36 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_dup_map(t_data *data)
{
	int	i;

	i = 0;
	data->map_flood = (char **)malloc(data->map_h * sizeof(char *));
	if (!data->map_flood)
		exit(1);
	while (i < data->map_h)
	{
		data->map_flood[i] = ft_strdup(data->map[i]);
		if (!data->map_flood[i])
			exit(1);
		i++;
	}
}

void	ft_fill(t_data *data, int x, int y)
{
	if (x < 0 || x >= data->map_h || y < 0 || y >= data->map_w)
		return ;
	if (data->map_flood[x][y] == 'X')
		return ;
	if (data->map_flood[x][y] != '1')
	{
		data->map_flood[x][y] = 'X';
		ft_fill(data, x - 1, y);
		ft_fill(data, x + 1, y);
		ft_fill(data, x, y - 1);
		ft_fill(data, x, y + 1);
	}
}

void	ft_get_player_demensions(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map_h)
	{
		y = 0;
		while (y < data->map_w)
		{
			if (data->map[x][y] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
			y++;
		}
		x++;
	}
}

void	ft_flood_fill(t_data *data)
{
	ft_dup_map(data);
	ft_get_player_demensions(data);
	ft_fill(data, data->player_x, data->player_y);
}
