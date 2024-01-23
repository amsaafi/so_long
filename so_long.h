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
    char    **map2;
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
    void    *enemy_xpm;
    void    *exit_xpm;
    void    *wall_xpm;
    void    *floor_xpm;

}   t_data;

#endif