/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:19:44 by oissa             #+#    #+#             */
/*   Updated: 2024/12/19 18:29:36 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

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

void	display_steps(t_game *game)
{
	char	*steps_str;
	char	*message;
	int		x;
	int		y;

	steps_str = ft_itoa(game->player_moves);
	if (!steps_str)
	{
		ft_dprintf(2, "Error: memory allocation failed\n");
		free_resources(game);
		exit(EXIT_FAILURE);
	}
	message = ft_strjoin("Steps: ", steps_str);
	if (!message)
	{
		ft_dprintf(2, "Error: memory allocation failed\n");
		free_resources(game);
		exit(EXIT_FAILURE);
	}
	x = 10;
	y = 10;
	mlx_string_put(game->mlx, game->mlx_win, x + 10, y + 10, 0x000000, message);
	free(steps_str);
	free(message);
}
