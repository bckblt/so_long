/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:44:35 by bakarabu          #+#    #+#             */
/*   Updated: 2025/04/08 06:11:03 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_chek_exit(t_game *game, int new_x, int new_y)
{
	static int	flag = 0;

	if (flag == 1 && (game->map[new_y][new_x] != '1'))
	{
		game->map[game->p_y][game->p_x] = 'E';
		game->map[new_y][new_x] = 'P';
		game->p_x = new_x;
		game->p_y = new_y;
		draw_map(game);
		flag = 0;
		return ;
	}
	else if (game->map[new_y][new_x] == 'E' && game->collected != 0)
	{
		if (flag == 0)
		{
			game->map[game->p_y][game->p_x] = '0';
			game->map[new_y][new_x] = 'P';
			flag = 1;
			game->p_x = new_x;
			game->p_y = new_y;
			draw_map(game);
			return ;
		}
	}
}

static void	ft_move(int new_x, int new_y, t_game *game)
{
	static int	move = 1;

	if ((game->map[new_y][new_x] != '1'))
	{
		if (game->map[new_y][new_x] != 'E')
		{
			game->map[game->p_y][game->p_x] = '0';
			game->p_x = new_x;
			game->p_y = new_y;
			game->map[new_y][new_x] = 'P';
			ft_printf("Number Of Moves = %d\n", move);
			move++;
		}
		draw_map(game);
		if (game->collected == 0 && game->map[new_y][new_x] == 'E')
		{
			ft_printf("Number Of Moves = %d\n", move);
			exit_game(game);
		}
	}
	return ;
}

static int	key_press(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->p_x;
	new_y = game->p_y;
	if ((!(keycode == 119) && !(keycode == 115) && !(keycode == 97)
			&& !(keycode == 100) && !(keycode == 65307)))
		return (0);
	if (keycode == 119)
		new_y--;
	else if (keycode == 115)
		new_y++;
	else if (keycode == 97)
		new_x--;
	else if (keycode == 100)
		new_x++;
	else if (keycode == 65307 || keycode == 17)
		exit_game(game);
	if (game->map[new_y][new_x] == 'C')
		game->collected--;
	ft_chek_exit(game, new_x, new_y);
	if ((game->map[new_y][new_x] != '1'))
		ft_move(new_x, new_y, game);
	return (0);
}

void	game_start(t_game *game)
{
	int	y;
	int	x;

	y = (game->max_y) * 64;
	x = (game->max_x - 1) * 64;
	game->init = mlx_init();
	if (!(game->init))
		ft_error("Error\nmlx_init_error\n", game);
	mlx_get_screen_size(game->init, &x, &y);
	if (!((game->max_y) * 64 <= y && (game->max_x - 1) * 64 <= x))
		ft_error("Error\nMap is so big\n", game);
	xpm_to_img(game);
	game->window = mlx_new_window((game->init), (game->max_x - 1) * 64,
			(game->max_y) * 64, "SO_LONG");
	if (!(game->window))
		ft_error("Error\nmlx_new_window_error\n", game);
	draw_map(game);
	mlx_key_hook(game->window, key_press, game);
	mlx_hook(game->window, 17, 0, exit_game, game);
	mlx_loop(game->init);
	free(game->init);
}
