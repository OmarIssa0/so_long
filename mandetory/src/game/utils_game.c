/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:19:44 by oissa             #+#    #+#             */
/*   Updated: 2024/12/18 17:16:44 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	player_hook(t_game *game, int x, int y)
{
	if (game->map[game->player_y + y][game->player_x + x] == '1')
		return ;
	if (game->map[game->player_y + y][game->player_x + x] == 'E')
	{
		ft_dprintf(2, "Error: you won the game\n");
		free_resources(game);
		exit(EXIT_SUCCESS);
	}
	if (game->map[game->player_y + y][game->player_x + x] == 'C')
	{
		game->player_moves++;
		game->map[game->player_y + y][game->player_x + x] = '0';
		game->remaining_collectibles--;
	}
	if (game->map[game->player_y + y][game->player_x + x] == '0')
	{
		game->player_moves++;
	}
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y + y][game->player_x + x] = 'P';
	game->player_x += x;
	game->player_y += y;
}

void	save_image_mlx(t_game *game, int x, int y, void *img)
{
	if (img)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * WIDTH_SIZE, y
			* HEIGHT_SIZE);
	}
}

int	close_window(t_game *game)
{
	free_resources(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	can_play(t_game *game)
{
	if (!can_player_finish_game(game))
	{
		ft_dprintf(2, "Error: no valid path to win the game\n");
		free_resources(game);
		exit(EXIT_SUCCESS);
	}
}
