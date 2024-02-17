/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 21:52:46 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/17 16:56:09 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_h)
	{
		free(data->map_flood[i]);
		i++;
	}
	free(data->map_flood);
}

void	check_map_surrounded_by_walls(t_data *data)
{
	int	map_h;
	int	i;
	int	j;
	int	map_w;

	i = -1;
	j = -1;
	map_h = data->map_h;
	map_w = data->map_w;
	while (++i < map_w)
	{
		if (data->map[0][i] != '1' || data->map[map_h - 1][i] != '1')
		{
			ft_printf("\033[91mMap is not surrounded by walls\033[91m\n");
			exit(1);
		}
	}
	while (++j < map_h)
	{
		if (data->map[j][0] != '1' || data->map[j][map_w - 1] != '1')
		{
			ft_printf("\033[91mMap is not surrounded by walls\033[91m\n");
			exit(1);
		}
	}
}

void	ft_count_charachters(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_h)
	{
		j = 0;
		while (j < data->map_w)
		{
			if (data->map[i][j] == 'P')
				data->player += 1;
			if (data->map[i][j] == 'E')
				data->exit += 1;
			if (data->map[i][j] == 'C')
				data->collectives += 1;
			j++;
		}
		i++;
	}
}

void	check_map_charachters(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->map_h)
	{
		y = 0;
		while (y < data->map_w)
		{
			if (data->map[x][y] != 'P' && data->map[x][y] != 'C'
				&& data->map[x][y] != 'E' && data->map[x][y] != '0'
				&& data->map[x][y] != '1')
			{
				ft_printf("\033[91mUNVALID MAP CHARACHTERS!\033[0m\n");
				exit(1);
			}
			y++;
		}
		x++;
	}
}

void	validate_map(t_data *data)
{
	if (data->map == NULL || data->map[0] == NULL)
	{
		ft_printf("\033[91mEmpty map\033[91m\n");
		exit(1);
	}
	check_map_charachters(data);
	ft_count_charachters(data);
	check_map_surrounded_by_walls(data);
	if (data->player != 1 || data->collectives < 1 || data->exit != 1)
	{
		ft_printf("\033[91mMap should contain one Player,"
			" one Exit and at least one Collective\033[0m\n");
		exit(1);
	}
	ft_is_playable(data);
	free_map(data);
	ft_get_exit_demensions(data);
}
