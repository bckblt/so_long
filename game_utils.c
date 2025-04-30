/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:44:10 by bakarabu          #+#    #+#             */
/*   Updated: 2025/04/08 03:53:16 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_img(t_game *game)
{
	game->width = 64;
	game->height = 64;
	game->board = mlx_xpm_file_to_image(game->init,
			"textures/board.xpm", &game->width, &game->height);
	game->king = mlx_xpm_file_to_image(game->init,
			"textures/king.xpm", &game->width, &game->height);
	game->pawn = mlx_xpm_file_to_image(game->init,
			"textures/pawn.xpm", &game->width, &game->height);
	game->flag = mlx_xpm_file_to_image(game->init,
			"textures/flag.xpm", &game->width, &game->height);
	game->wall = mlx_xpm_file_to_image(game->init,
			"textures/wall.xpm", &game->width, &game->height);
	if (!game->board || !game->king
		|| !game->pawn || !game->flag || !game->wall)
	{
		ft_printf("Error\nWrong Assets Path");
		exit_game(game);
	}
}

int	exit_game(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->window)
		mlx_destroy_window(game->init, game->window);
	if (game->init)
	{
		if (game->board)
			mlx_destroy_image(game->init, game->board);
		if (game->king)
			mlx_destroy_image(game->init, game->king);
		if (game->pawn)
			mlx_destroy_image(game->init, game->pawn);
		if (game->flag)
			mlx_destroy_image(game->init, game->flag);
		if (game->wall)
			mlx_destroy_image(game->init, game->wall);
		mlx_destroy_display(game->init);
		free(game->init);
	}
	free_map(game->map);
	free(game);
	exit(0);
	return (0);
}

void	draw_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < game->max_y)
	{
		x = 0;
		while (x < game->max_x - 1)
		{
			img = game->board;
			if (game->map[y][x] == '1')
				img = game->wall;
			else if (game->map[y][x] == 'P')
				img = game->king;
			else if (game->map[y][x] == 'E')
				img = game->flag;
			else if (game->map[y][x] == 'C')
				img = game->pawn;
			mlx_put_image_to_window(game->init,
				game->window, img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
