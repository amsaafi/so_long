#include "so_long.h"

void    ft_draw_elements(t_data *data)
{
    ft_draw_walls_floor(data);
    ft_draw_exit(data);
    ft_draw_player(data);
    ft_draw_collec(data);
    ft_draw_killer(data);
}

void    ft_draw_map(t_data *data)
{
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, data->map_W * 50, data->map_H * 50, "So_______LONG");
	data->exit_xpm = mlx_xpm_file_to_image(data->mlx, "./textures/exit.xpm",
			&data->img_W, &data->img_H);
	data->player_xpm = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm",
			&data->img_W, &data->img_H);
	data->heart_xpm = mlx_xpm_file_to_image(data->mlx, "./textures/heart.xpm",
			&data->img_W, &data->img_H);
	data->floor_xpm = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm",
			&data->img_W, &data->img_H);
	data->wall_xpm = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm",
			&data->img_W, &data->img_H);
	data->fire_xpm = mlx_xpm_file_to_image(data->mlx, "./textures/fire.xpm",
	 		&data->img_W, &data->img_H);
    ft_draw_elements(data);
}
