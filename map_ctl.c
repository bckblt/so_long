/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ctl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:43:50 by bakarabu          #+#    #+#             */
/*   Updated: 2025/04/08 05:32:15 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

char	**copy_map(t_game *game)
{
	char	**new_map;
	int		i;

	i = 0;
	new_map = (char **)malloc(sizeof(char *) * (game->max_y + 1));
	if (!new_map)
		return (NULL);
	while (i < game->max_y)
	{
		new_map[i] = ft_strdup(game->map[i]);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

int	validate_path(t_game *game, int x, int y)
{
	char	**f_m;

	f_m = copy_map(game);
	flood_fill(f_m, game->p_x, game->p_y);
	while (f_m[y])
	{
		x = 0;
		while (f_m[y][x])
		{
			if (f_m[y][x] == 'C' || f_m[y][x] == 'E')
			{
				free_map(f_m);
				return (0);
			}
			x++;
		}
		y++;
	}
	free_map(f_m);
	return (1);
}

int	map_ctl(t_game *game)
{
	if (!is_rectangular(game->map))
		ft_error("Error\nMap is not rectangular\n", game);
	if (!walls_check(game))
		ft_error("Error\nThe map is not surrounded by walls!\n", game);
	check_components(game, 0, 0, 0);
	if (!validate_path(game, 0, 0))
		ft_error("Error\nThis map is unsolvable\n", game);
	return (1);
}
