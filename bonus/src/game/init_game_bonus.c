/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:52:00 by oissa             #+#    #+#             */
/*   Updated: 2024/12/18 18:41:55 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"


void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_dprintf(2, "Error: mlx_init() failed\n");
		free_resources(game);
		exit(EXIT_FAILURE);
	}
	game->mlx_win = mlx_new_window(game->mlx, game->map_width * STANDARD_SIZE,
			game->map_height * STANDARD_SIZE, "so_long");
	if (!game->mlx_win)
	{
		ft_dprintf(2, "Error: mlx_new_window() failed\n");
		free_resources(game);
		exit(EXIT_FAILURE);
	}
	count_collectibles(game);
}

void	display_image(t_game *game)
{
	game->floor_img = mlx_xpm_file_to_image(game->mlx, IMAGE_FLOOR_PATH,
			&game->img_width, &game->img_height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, IMAGE_PLAYER_PATH,
			&game->img_width, &game->img_height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, IMAGE_WALL_PATH,
			&game->img_width, &game->img_height);
	game->collectible_img = mlx_xpm_file_to_image(game->mlx,
			IMAGE_COLLECTIBLE_PATH, &game->img_width, &game->img_height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, IMAGE_EXIT_PATH,
			&game->img_width, &game->img_height);
    game->enemy_img = mlx_xpm_file_to_image(game->mlx, IMAGE_ENEMIES_PATH,
            &game->img_width, &game->img_height);       
	if (!game->wall_img || !game->player_img || !game->floor_img
		|| !game->collectible_img || !game->exit_img || !game->enemy_img)
	{
		ft_dprintf(2, "Error: failed to load one or more images\n");
		free_resources(game);
		exit(EXIT_FAILURE);
	}
}

void display_map_in_window(t_game *game, int i, int j)
{
    if (game->map[i][j] == '1')
        save_image_mlx(game, j, i, game->wall_img);
    else if (game->map[i][j] == 'P')
        save_image_mlx(game, j, i, game->player_img);
    else if (game->map[i][j] == 'E')
    {
        if (game->remaining_collectibles == 0)
            save_image_mlx(game, j, i, game->exit_img);
        else
            save_image_mlx(game, j, i, game->floor_img);
        if (game->player_x == j && game->player_y == i)
            save_image_mlx(game, j, i, game->player_img);
    }
    else if (game->map[i][j] == 'C')
        save_image_mlx(game, j, i, game->collectible_img);
    else if (game->map[i][j] == 'A')
        save_image_mlx(game, j, i, game->enemy_img);
    else if (game->map[i][j] == '0')
        save_image_mlx(game, j, i, game->floor_img);
}

void	display_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			display_map_in_window(game, i, j);
			j++;
		}
		display_steps(game);
		i++;
	}
}

void	count_collectibles(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	game->remaining_collectibles = count;
	if (game->remaining_collectibles == 0)
	{
		ft_dprintf(2, "Error: no collectibles found\n");
		free_resources(game);
		exit(EXIT_FAILURE);
	}
}
