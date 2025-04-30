/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bakarabu <bakarabu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:44:18 by bakarabu          #+#    #+#             */
/*   Updated: 2025/04/07 21:48:12 by bakarabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*a;
	size_t			i;

	a = s;
	i = 0;
	while (i < n)
	{
		a[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;
	int		len;

	i = 0;
	len = 0;
	while (s1[len] != '\0')
		len++;
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_error(char *message, t_game *game)
{
	if (message)
		ft_printf("%s", message);
	if (game->map)
		free_map(game->map);
	free (game);
	exit (1);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	if (map)
		free (map);
}
