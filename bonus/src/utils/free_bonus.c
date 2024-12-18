/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:09:12 by oissa             #+#    #+#             */
/*   Updated: 2024/12/18 23:33:30 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
void	free_collectibles(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->collectibles_img_count)
	{
		if (game->collectible_img[i])
			mlx_destroy_image(game->mlx, game->collectible_img[i]);
		i++;
	}
	free(game->collectible_img);
}

void	free_resources(t_game *game)
{
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->collectible_img)
		free_collectibles(game);
	if (game->floor_img)
		mlx_destroy_image(game->mlx, game->floor_img);
	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->enemy_img)
		mlx_destroy_image(game->mlx, game->enemy_img);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->enemies)
		free(game->enemies);
	if (game->mlx)
		free(game->mlx);
	if (game->map)
		free_map(game);
}
