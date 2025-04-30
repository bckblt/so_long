/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:56:45 by bakarabu          #+#    #+#             */
/*   Updated: 2025/04/08 04:00:25 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"
# include "./get_next_line/get_next_line.h"
# include <fcntl.h>

typedef struct s_game
{
	char	**map;
	int		max_x;
	int		max_y;
	int		p_x;
	int		p_y;
	int		width;
	int		height;
	int		collected;
	void	*init;
	void	*window;
	void	*board;
	void	*king;
	void	*pawn;
	void	*wall;
	void	*flag;
}	t_game;

int		ft_strlen(char *str);
int		map_ctl(t_game *game);
void	game_start(t_game *game);
char	*ft_strdup(const char *s1);
int		map_cfg(char **av, t_game *game);
void	ft_error(char *message, t_game *game);
void	free_map(char **map);
void	draw_map(t_game *game);
int		exit_game(void *param);
void	xpm_to_img(t_game *game);
void	*ft_memset(void *s, int c, size_t n);
void	check_components(t_game *game, int p_count, int e_count, int c_count);
int		walls_check(t_game *game);
int		is_rectangular(char **map);

#endif