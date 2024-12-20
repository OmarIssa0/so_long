/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:02:11 by oissa             #+#    #+#             */
/*   Updated: 2024/12/20 18:02:11 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	display_map_too(t_game *game, int x, int y)
{
	if (game->remaining_collectibles == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit_img, x
			* game->img_width, y * game->img_height);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor_img, x
			* game->img_width, y * game->img_height);
	if (game->player_x == x && game->player_y == y)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->player_img, x
			* game->img_width, y * game->img_height);
}

void	display_map_three(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player_img, x
		* game->img_width, y * game->img_height);
}

void	display_map_four(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall_img, x
			* game->img_width, y * game->img_height);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor_img, x
			* game->img_width, y * game->img_height);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->collectible_img[game->collectibles_img_index], x
			* game->img_width, y * game->img_height);
	else if (game->map[y][x] == 'E')
		display_map_too(game, x, y);
	else if (game->map[y][x] == 'P')
		display_map_three(game, x, y);
	else if (game->map[y][x] == 'A')
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy_img, x
			* game->img_width, y * game->img_height);
}

void	display_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			display_map_four(game, x, y);
			x++;
		}
		display_steps(game);
		y++;
	}
}
