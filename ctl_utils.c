/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:44:39 by bakarabu          #+#    #+#             */
/*   Updated: 2025/04/08 06:11:25 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	comp_utils(t_game *game, int p_count, int e_count, int c_count)
{
	if (p_count != 1)
		ft_error("Error\nThe number of P must be equal to one.\n", game);
	if (e_count != 1)
		ft_error("Error\nThe number of E must be equal to one.\n", game);
	if (c_count < 1)
		ft_error("Error\nThe map must contain C.\n", game);
	game->collected = c_count;
}

void	check_components(t_game *game, int p_count, int e_count, int c_count)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->p_x = x;
				game->p_y = y;
				p_count++;
			}
			else if (game->map[y][x] == 'E')
				e_count++;
			else if (game->map[y][x] == 'C')
				c_count++;
			x++;
		}
		y++;
	}
	comp_utils(game, p_count, e_count, c_count);
}

int	walls_check(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	map = game->map;
	x = 0;
	y = 0;
	while (x < game->max_x - 1)
	{
		if (map[0][x] != '1' || map[game->max_y - 1][x] != '1')
			return (0);
		x++;
	}
	while (y < game->max_y)
	{
		if (map[y][0] != '1' || map[y][game->max_x - 2] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	is_rectangular(char **map)
{
	int	i;
	int	width;
	int	current_len;

	if (!map || !map[0])
		return (0);
	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		current_len = ft_strlen(map[i]);
		if (map[i + 1] != NULL)
		{
			if (current_len != width)
				return (0);
		}
		else
			if (current_len != width && current_len != width - 1)
				return (0);
		i++;
	}
	return (1);
}
