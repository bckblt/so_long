/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cfg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:44:29 by bakarabu          #+#    #+#             */
/*   Updated: 2025/04/08 05:16:04 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_coordinate(t_game *game)
{
	int		x;
	int		y;
	char	**smap;

	y = 0;
	smap = game->map;
	while (smap[y])
	{
		x = 0;
		while (smap[y][x])
		{
			if (smap[y][x] == 'P')
			{
				game->p_x = x;
				game->p_y = y;
			}
			x++;
		}
		y++;
	}
}

static int	size_y(char *map)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

static char	**read_map_file(int fd, int max_y)
{
	char	**f_map;
	char	*line;
	int		i;

	i = 0;
	f_map = (char **)malloc(sizeof(char *) * (max_y + 1));
	line = get_next_line(fd);
	if (!line)
	{
		free(f_map);
		return (NULL);
	}
	while (line)
	{
		f_map[i++] = line;
		line = get_next_line(fd);
	}
	free(line);
	f_map[i] = NULL;
	if (i != max_y)
	{
		free_map(f_map);
		return (NULL);
	}
	return (f_map);
}

int	map_cfg(char **av, t_game *game)
{
	int		fd;
	char	**f_map;

	game->max_y = size_y(av[1]);
	if (game->max_y <= 0)
		ft_error("Error\nEmpty map file\n", game);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("Error\nWrong map path!\n", game);
	f_map = read_map_file(fd, game->max_y);
	close(fd);
	if (!f_map)
		ft_error("Error\nMap reading error!\n", game);
	game->max_x = ft_strlen(f_map[0]);
	game->map = f_map;
	player_coordinate(game);
	return (1);
}
