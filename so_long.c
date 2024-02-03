#include "so_long.h"
#define MAX_ALLOCATIONS 10000
#define WARN(msg, line) (printf("Warning %d: %s\n", line, msg))


void ft_draw_map(t_data *data)
{
    int x;
    int y;

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
	// data->enemy_xpm = mlx_xpm_file_to_image(data->mlx, "./textures/fire.xpm",
	// 		&data->img_W, &data->img_H);
    x = 0;
    y = 0;
    while(y < data->map_H)
    {
        x = 0;
        while(x < data->map_W)
        {
            if(data->map[y][x] == '1')
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_xpm, x*50, y*50);

            if (data->map[y][x] == '0')
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor_xpm, x*50, y*50);
            if(data->map[y][x] == 'E')
            {
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor_xpm, x*50, y*50);
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit_xpm, x*50, y*50);
            }
            if(data->map[y][x] == 'P')
            {
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor_xpm, x*50, y*50);
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_xpm, x*50, y*50);
            }
            if(data->map[y][x] == 'C')
            {
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor_xpm, x*50, y*50);
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->heart_xpm, x*50, y*50);
            }
            x++;
        }
        y++;
    }
    mlx_loop(data->mlx);
    
}


int main(int ac, char *av[])
{
    t_data data;

	if (ac != 2)
	{
		ft_putstr("ONLY NEED 2 VALID PARAM!");
		return (1);
	}
    ft_memset(&data, 0, sizeof(data));
    ft_fill_map(av[1], &data);
	validate_map(&data);
    ft_draw_map(&data);
}
