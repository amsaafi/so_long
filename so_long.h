#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "gnl/get_next_line.h"

typedef struct s_data
{
    void    *mlx;
    void    *mlx_win;
    char    **map;
    char    **map_flood;
    int     map_W;
    int     map_H;
    int     zero;
    int     one;
    int     player;
    int     collectives;
    int     exit;
    int     img_W;
    int     img_H;
    int     player_X;
    int     player_Y;
    void    *player_xpm;
    void    *heart_xpm;
    void    *fire_xpm;
    void    *exit_xpm;
    void    *wall_xpm;
    void    *floor_xpm;

}   t_data;

void check_map_surrounded_by_walls(t_data *data);
void validate_map(t_data *data);
void free_map(char **map);
void ft_map_W(char *path, t_data *data);
void ft_map_H(char *path, t_data *data);
void	*ft_memset(void *ptr, int value, size_t num);
size_t	ft_strlenl2(const char *str);
void ft_fill_map(char *path, t_data *data);
void	ft_putstr(char *str);

// void count_collectibles(t_data *data);
// void count_player(t_data *data);
// void count_exit(t_data *data);
// void count_floors(t_data *data);
// void count_walls(t_data *data);
// void map_comp(t_data *data);

#endif