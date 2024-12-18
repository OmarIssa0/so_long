/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler_map_too_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:47:35 by oissa             #+#    #+#             */
/*   Updated: 2024/12/17 22:56:18 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	check_map_shape(t_game *game)
{
	int	i;
	int	row_len;

	i = 0;
	row_len = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != row_len)
		{
			ft_dprintf(2, "Error: map is not rectangular\n");
			free_resources(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	check_map_content(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'A')
			{
				ft_dprintf(2, "Error: invalid map content\n");
				free_resources(game);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	exit_error_and_close_fd(char *message, int fd)
{
	ft_dprintf(2, "%s\n", message);
	close(fd);
	exit(EXIT_FAILURE);
}

void	exit_error(char *message, t_game *game, int fd, char *tmp)
{
	ft_dprintf(2, "%s\n", message);
	close(fd);
	free(tmp);
	free_resources(game);
	exit(EXIT_FAILURE);
}

void	check_map_too(t_game *game)
{
	check_width_and_height(game);
	check_map_content(game);
	check_map_walls(game);
	check_collectibles(game);
	check_player(game);
	check_exit(game);
	check_map_shape(game);
}
