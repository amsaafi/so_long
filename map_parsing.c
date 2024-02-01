#include "so_long.h" // Include necessary headers

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
            printf("Error: Map is not surrounded by walls\n");
            free(data->map);
            exit(1);
        }
        i++;
    }
    while (j < map_H) {
        if (data->map[j][0] != '1' || data->map[j][map_W - 1] != '1') {
            printf("Error: Map is not surrounded by walls\n");
            free(data->map);
            exit(1);
        }
        j++;
    }
}
void	check_map_charachters(t_data *data)
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



void validate_map(t_data *data)
{
    int i;
    int cols;
    int ex;
    int player;

    i = 0;
    cols = 0;
    ex = 0;
    player = 0;
    if (data->map == NULL || data->map[0] == NULL) {
        printf("Error: Empty map\n");//warning.
        exit(1);
    }
    // // Check if the map is rectangular
    // cols = strlen(data->map[0]);//warning
    // while (data->map[i] != NULL)
    // {
    //     if (strlen(data->map[i]) != cols) {
    //         printf("Error: Map is not rectangular\n");
    //         exit(1);
    //     }
    //     i++;
    // }
    check_map_charachters(data);
    // cols = count_collectibles(data);
    // player = count_player(data);
    // ex = count_exit(data);
    check_map_surrounded_by_walls(data);
    if (data->player != 1 || data->collectives < 1 || data->exit != 1)
	{
		printf("Error: Map should contain one player, one exit, and at least one collectible\n");//warning
		exit(1);
	}
}
