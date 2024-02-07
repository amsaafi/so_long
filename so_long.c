#include "so_long.h"

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
    ft_flood_fill(&data);
    // int i = 0;
    // while (i < data.map_H)
    // {
    //     printf("%s\n", data.map_flood[i]);
    //     i++;
    // }
    // ft_putstr("===================map======================\n");
    // i = 0;
    // while (i < data.map_H)
    // {
    //     printf("%s\n", data.map[i]);
    //     i++;
    // }
    // system("leaks so_long");
    ft_draw_map(&data);
    mlx_loop(data.mlx);
}
