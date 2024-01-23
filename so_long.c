#include "so_long.h"

size_t	ft_strlenl(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
size_t	ft_strlenl2(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*byte_ptr;
	size_t			i;

	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		byte_ptr[i] = (unsigned char)value;
		i++;
	}
	return (ptr);
}

void ft_map_H(char *path, t_data *data)
{
    char    *line;
    int fd;
    int height;

    fd = open(path, O_RDONLY);
    height = 0;
    if (fd < 0)
    {
        printf("THE MAP PATH IS INVALID!");
        exit(1);
    }
    line = get_next_line(fd);
    while(line)
    {
        height++;
        free(line);
        line = get_next_line(fd);
    }
    if (height == 0)
    {
        printf("ERROR IN THE MAP!");
        exit(1);
    }
    close(fd);
    data->map_H = height;
}
void ft_map_W(char *path, t_data *data)
{
	int fd;
	int i;
	size_t s;
	char *line;
	i = 0;
	fd = open(path,O_RDONLY);
	if(fd < 0)
	{
		printf("THE MAP PATH IS INVALID!");
		exit(1);
	}
	line = get_next_line(fd);
	s = ft_strlenl2(line);
	while (line)
	{
		if(s != (ft_strlenl2(line)))
		{
			printf("THE MAP PATH IS INVALID!");
			exit(1);
		}
		line = get_next_line(fd);
	}
	data->map_W = s;
	close(fd);
}
void ft_fill_map(char *path, t_data *data)
{
    char    *line;
    int fd;
    int i;

    i = 0;
    ft_map_W(path, data);
    ft_map_H(path, data);
	fd = open(path, O_RDONLY);
    if (fd < 0 || data->map_H == 0)
        exit(1);
    data->map = (char **)malloc((data->map_H) * sizeof(char **));
    //protection
    line = get_next_line(fd);
    while (i < data->map_H && line)
    {
        data->map[i] = line;
        line = get_next_line(fd);
        i++;
    }
}

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
	// data->enemy_xpm = mlx_xpm_file_to_image(data->mlx, "./textures/enemy.xpm",
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
            x++;
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
        }
        y++;
    }
    mlx_loop(data->mlx);
    
}


int main(int ac, char *av[])
{
    t_data data;

    ft_memset(&data, 0, sizeof(data));
	if (ac != 2)
	{
		printf("ONLY NEED 2 VALID PARAM!");
		return (1);
	}
    ft_fill_map(av[1], &data);
    ft_draw_map(&data);


    // printf("map width: %d\n", data.map_W);
    // printf("map height: %d\n", data.map_H);
    
    // while(i < data.map_H)
    // {
    //     printf("%s", data.map[i]);
    //     i++;
    // }    
}
