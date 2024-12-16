/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 21:01:58 by oissa             #+#    #+#             */
/*   Updated: 2024/12/16 14:39:23 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/*
    Escape key: 65307 && 113 -> exit the game
    Q key: 113
    W key: 119
    S key: 115
    A key: 97
    D key: 100
    UP key: 65362
    DOWN key: 65364
    LEFT key: 65361
    RIGHT key: 65363
*/
int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == ESC || keycode == Q)
	{
		free_resources(game);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == UP || keycode == W)
		player_control(game, 0, -1);
	else if (keycode == DOWN || keycode == S)
		player_control(game, 0, 1);
	else if (keycode == LEFT || keycode == A)
		player_control(game, -1, 0);
	else if (keycode == RIGHT || keycode == D)
		player_control(game, 1, 0);
	display_map(game);
	return (EXIT_SUCCESS);
}

/*
    find the player position in the map
*/
void	find_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

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

void	player_control_too(t_game *game, int new_x, int new_y)
{
	if (game->remaining_collectibles == 0)
	{
		game->player_moves++;
		ft_printf("Steps: %d\n", game->player_moves);
		ft_dprintf(2, "You won the game!\n");
		free_resources(game);
		exit(EXIT_SUCCESS);
	}
	else
	{
		game->player_moves++;
		if (game->map[game->player_y][game->player_x] == 'E')
			game->map[game->player_y][game->player_x] = 'E';
		else
			game->map[game->player_y][game->player_x] = '0';
		game->player_x = new_x;
		game->player_y = new_y;
		display_map(game);
		ft_printf("Steps: %d\n", game->player_moves);
		return ;
	}
}

void	player_control_three(t_game *game, int new_x, int new_y)
{
	if (game->map[game->player_y][game->player_x] == 'E')
		game->map[game->player_y][game->player_x] = 'E';
	else
		game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->player_moves++;
}

void	player_control(t_game *game, int x, int y)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x + x;
	new_y = game->player_y + y;
	if (game->map[new_y][new_x] == '1')
		return ;
	if (game->map[new_y][new_x] == 'E')
		player_control_too(game, new_x, new_y);
	if (game->map[new_y][new_x] == 'C')
	{
		game->map[new_y][new_x] = '0';
		game->remaining_collectibles--;
	}
	if (game->map[new_y][new_x] == '0' || (game->map[new_y][new_x] == 'E'
			&& game->remaining_collectibles == 0))
		player_control_three(game, new_x, new_y);
	display_map(game);
	ft_printf("Steps: %d\n", game->player_moves);
}
