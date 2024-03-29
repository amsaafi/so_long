/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_filling.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samsaafi <samsaafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:33:21 by samsaafi          #+#    #+#             */
/*   Updated: 2024/02/18 12:37:59 by samsaafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_h(char *path, t_data *data)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(path, O_RDONLY);
	height = 0;
	if (fd < 0)
	{
		ft_printf("\033[91mTHE MAP PATH IS INVALID!\033[91m\n");
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	if (height == 0)
	{
		ft_printf("\033[91mMAP IS EMPTY!\033[91m\n");
		exit(1);
	}
	close(fd);
	data->map_h = height;
}

void	ft_map_w(char *path, t_data *data)
{
	int		fd;
	size_t	s;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("\033[91mTHE MAP PATH IS INVALID!\033[91m\n");
		exit(1);
	}
	line = get_next_line(fd);
	s = ft_strlenl2(line);
	while (line)
	{
		if (s != (ft_strlenl2(line)))
		{
			ft_printf("\033[91mINVALID MAP\033[91m\n");
			exit(1);
		}
		free(line);
		line = get_next_line(fd);
	}
	data->map_w = s;
	close(fd);
}

void	ft_fill_map(char *path, t_data *data)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	ft_map_h(path, data);
	ft_map_w(path, data);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(1);
	data->map = (char **)malloc((data->map_h) * sizeof(char **));
	if (!data->map)
		exit(1);
	line = get_next_line(fd);
	while (i < data->map_h && line)
	{
		data->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
}

void	check_path_format(char *path)
{
	char	*v;
	int		i;
	int		j;

	i = 0;
	j = 0;
	v = ".ber";
	if (ft_strrchr(path, '.') - 1 == ft_strrchr(path, '/'))
	{
		ft_printf("\033[91mINVALID MAP FORMAT1\033[91m\n");
		exit(1);
	}
	i = ft_strlen(path);
	while (path[i] != '.')
		i--;
	while (path[i])
	{
		if (path[i] != v[j])
		{
			ft_printf("\033[91mINVALID MAP FORMAT2\033[91m\n");
			exit(1);
		}
		j++;
		i++;
	}
}
