#include "so_long.h"

void free_map(char **map)
{
    if (map == NULL)
        return;

    int i = 0;
    while (map[i] != NULL) {
        free(map[i]);
        i++;
    }
    free(map);
}

void check_map_surrounded_by_walls(t_data *data)
{
    int map_H;
    int i;
    int j;
    int map_W;

    i = 0;
    j = 0;
    map_H = data->map_H;
    map_W = data->map_W;
    while (i < map_W) {
        if (data->map[0][i] != '1' || data->map[map_H - 1][i] != '1') {
            ft_putstr("Error: Map is not surrounded by walls\n");
            exit(1);
        }
        i++;
    }
    while (j < map_H) {
        if (data->map[j][0] != '1' || data->map[j][map_W - 1] != '1') {
            ft_putstr("Error: Map is not surrounded by walls\n");
            exit(1);
        }
        j++;
    }
}
void	ft_count_charachters(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_H)
	{
		j = 0;
		while (j < data->map_W)
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
	while (x < data->map_H)
	{
		y = 0;
		while (y < data->map_W)
		{
			if (data->map[x][y] != 'P' && data->map[x][y] != 'C' && data->map[x][y] != 'E' && data->map[x][y] != 'F'
            && data->map[x][y] != '0' && data->map[x][y] != '1')//WARNING<---------
            {
                ft_putstr("MAP CHARACHTERS INVALID!\n");
                exit(1);
            }
			y++;
		}
		x++;
	}
}



void validate_map(t_data *data)
{
    if (data->map == NULL || data->map[0] == NULL) {
        ft_putstr("Error: Empty map\n");
        exit(1);
    }
    check_map_charachters(data);
    ft_count_charachters(data);
    check_map_surrounded_by_walls(data);
    if (data->player != 1 || data->collectives < 1 || data->exit != 1)
	{
		ft_putstr("Error: Map should contain one player, one exit, and at least one collectible\n");
		exit(1);
	}
    ft_is_Playable(data);
}
