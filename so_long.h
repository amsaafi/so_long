/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:59:44 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/17 17:02:42 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	char	**map_flood;
	char	**map_flood_colec;
	int		map_w;
	int		map_h;
	int		zero;
	int		one;
	int		player;
	int		collectives;
	int		exit;
	int		img_w;
	int		img_h;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		moves;
	int		flag;
	void	*player_xpm;
	void	*player_left_xpm;
	void	*colec_xpm;
	void	*exit_xpm;
	void	*wall_xpm;
	void	*floor_xpm;

}			t_data;

void		check_map_surrounded_by_walls(t_data *data);
void		validate_map(t_data *data);
void		free_map(t_data *data);
void		ft_map_w(char *path, t_data *data);
void		ft_map_h(char *path, t_data *data);
void		*ft_memset(void *ptr, int value, size_t num);
char		*ft_strdup(const char *s);
size_t		ft_strlenl2(const char *str);
void		ft_fill_map(char *path, t_data *data);
char		*ft_strrchr(const char *str, int c);
void		check_path_format(char *path);
void		ft_draw_map(t_data *data);
void		ft_draw_elements(t_data *data);
void		ft_draw_walls_floor(t_data *data);
void		ft_draw_exit(t_data *data);
void		ft_draw_player(t_data *data);
void		ft_draw_collec(t_data *data);
void		ft_flood_fill(t_data *data);
void		ft_flood_fill_colec(t_data *data);
void		ft_get_player_demensions(t_data *data);
void		ft_is_playable(t_data *data);
void		ft_dup_map(t_data *data);
void		ft_dup_map_colec(t_data *data);
void		ft_flood_fill_colec(t_data *data);
void		ft_not_game(t_data *data);
int			ft_key_hook(int keycode, t_data *data);
int			ft_esc(t_data *data);
void		ft_check_exit(t_data *data);
void		ft_get_exit_demensions(t_data *data);
void		ft_player(t_data *data, int x, int y);
#endif
