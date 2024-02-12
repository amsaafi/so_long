#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct s_data
{
    void    *mlx;
    void    *mlx_win;
    char    **map;
    char    **map_flood;
    char    **map_flood_colec;
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
    int     exit_X;
    int     exit_Y;
    int     moves;
    int     flag;
    void    *player_xpm;
    void    *player_left_xpm;
    void    *heart_xpm;
    void    *fire_xpm;
    void    *exit_xpm;
    void    *wall_xpm;
    void    *floor_xpm;

}   t_data;

void    check_map_surrounded_by_walls(t_data *data);
void    validate_map(t_data *data);
void    free_map(t_data *data);
void    ft_map_W(char *path, t_data *data);
void    ft_map_H(char *path, t_data *data);
void	*ft_memset(void *ptr, int value, size_t num);
char	*ft_strdup(const char *s);
size_t  ft_strlenl2(const char *str);
void    ft_fill_map(char *path, t_data *data);
char	*ft_strchr(const char *s, int c);
void    check_path_format(char *path);
void    ft_draw_map(t_data *data);
void    ft_draw_elements(t_data *data);
void    ft_draw_walls_floor(t_data *data);
void    ft_draw_exit(t_data *data);
void    ft_draw_player(t_data *data);
void    ft_draw_collec(t_data *data);
void    ft_draw_killer(t_data *data);
void    ft_flood_fill(t_data *data);
void    ft_flood_fill_colec(t_data *data);
void    ft_get_player_demensions(t_data *data);
void    ft_is_Playable(t_data *data);
void    ft_dup_map(t_data *data);
void    ft_dup_map_colec(t_data *data);
void    ft_flood_fill_colec(t_data *data);
void    ft_Not_game(t_data *data);
int ft_key_hook(int keycode, t_data *data);
int ft_esc(t_data *data);
void    ft_check_exit(t_data *data);
void    ft_get_exit_demensions(t_data *data);



#endif