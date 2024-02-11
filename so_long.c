#include "so_long.h"

void ft_free_map(char **map)
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

int main(int ac, char *av[])
{
    t_data data;

	if (ac != 2)
	{
		ft_putstr("ONLY NEED 2 VALID PARAM!\n");
		exit(1);
	}
    ft_memset(&data, 0, sizeof(data));
    check_path_format(av[1]);
    ft_fill_map(av[1], &data);
	validate_map(&data);
    // ft_flood_fill(&data);
    ft_draw_map(&data);
    mlx_key_hook(data.mlx_win,ft_key_hook, &data);
    ft_putstr("*************** main.c leaks ****************\n");
    system("leaks so_long");
    mlx_loop(data.mlx);
}
