/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:44:21 by bakarabu          #+#    #+#             */
/*   Updated: 2025/04/08 04:02:47 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	arg_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 2 || !av[1] || av[1][0] == '\0')
	{
		ft_printf("Error\nUsage: %s <map's path>\n", av[0]);
		exit (1);
	}
	while (av[1][i] && av[1][i] != '.')
		i++;
	if (av[1][0] == '.')
		return (0);
	if (av[1][i - 1] != '/' && av[1][i] == '.' && av[1][i + 1] == 'b'
		&& av[1][i + 2] == 'e' && av[1][i + 3] == 'r' && av[1][i + 4] == '\0')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (!arg_check(ac, av))
	{
		ft_printf("Error\nWrong map name format");
		return (1);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	ft_memset(game, 0, sizeof(t_game));
	if (!map_cfg(av, game))
	{
		free(game);
		return (1);
	}
	if (!map_ctl(game))
	{
		free_map(game->map);
		free(game);
		return (1);
	}
	game->max_x = ft_strlen(game->map[0]);
	game_start(game);
	return (0);
}
