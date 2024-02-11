#include "so_long.h"

void    ft_draw_walls_floor(t_data *data)
{
    int x;
    int y;

    y = 0;
    if (!data->wall_xpm || !data->floor_xpm)
        exit(1);
    while(y < data->map_H)
    {
        x = 0;
        while(x < data->map_W)
        {
            if (data->map[y][x] == '1')
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall_xpm, x*50, y*50);
            if (data->map[y][x] == '0')
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor_xpm, x*50, y*50);
            x++;
        }
        y++;
    }
}

void    ft_draw_exit(t_data *data)
{
    int x;
    int y;

    y = 0;
    if (!data->exit_xpm)
        exit(1);
    while(y < data->map_H)
    {
        x = 0;
        while(x < data->map_W)
        {
            if (data->map[y][x] == 'E')
            {
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor_xpm, x*50, y*50);
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->exit_xpm, x*50, y*50);
            }
            x++;
        }
        y++;
    }
}

void    ft_draw_player(t_data *data)
{
    int x;
    int y;

    y = 0;
    if (!data->player_xpm || !data->player_left_xpm)
    {
        exit(1);
    }
    while(y < data->map_H)
    {
        x = 0;
        while(x < data->map_W)
        {
            if (data->map[y][x] == 'P' && data->flag == 1)
            {
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor_xpm, x*50, y*50);
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_xpm, x*50, y*50);
            }
            else if (data->map[y][x] == 'P' && data->flag == -1)
            {
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor_xpm, x*50, y*50);
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_left_xpm, x*50, y*50);
            }
            x++;
        }
        y++;
    }
}

void    ft_draw_collec(t_data *data)
{
    int x;
    int y;

    y = 0;
    if (!data->heart_xpm)
        exit(1);
    while(y < data->map_H)
    {
        x = 0;
        while(x < data->map_W)
        {
            if (data->map[y][x] == 'C')
            {
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor_xpm, x*50, y*50);
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->heart_xpm, x*50, y*50);
            }
            x++;
        }
        y++;
    }
}

void    ft_draw_killer(t_data *data)
{
    int x;
    int y;

    y = 0;
    if (!data->fire_xpm)
        exit(1);
    while(y < data->map_H)
    {
        x = 0;
        while(x < data->map_W)
        {
            if (data->map[y][x] == 'F')
            {
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->floor_xpm, x*50, y*50);
                mlx_put_image_to_window(data->mlx, data->mlx_win, data->fire_xpm, x*50, y*50);
            }
            x++;
        }
        y++;
    }
}
