/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_algorithm_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:44:28 by oissa             #+#    #+#             */
/*   Updated: 2024/12/20 17:44:28 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	get_enemy_number(t_game *game)
{
	int	i;
	int	j;
	int	num_enemies;

	i = 0;
	num_enemies = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'A')
				num_enemies++;
			j++;
		}
		i++;
	}
	game->num_enemies = num_enemies;
	game->enemies = (t_enemy *)malloc(sizeof(t_enemy) * num_enemies);
	if (!game->enemies)
		exit_and_free("Error: memory allocation failed\n", game);
}

void	initialize_enemies(t_game *game)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	index = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == 'A')
			{
				game->enemies[index].x = j;
				game->enemies[index].y = i;
				index++;
			}
			j++;
		}
		i++;
	}
}

void	move_enemy_too(t_game *game, t_enemy *enemy, int new_x, int new_y)
{
	if (new_x != enemy->x || new_y != enemy->y)
	{
		if (game->map[new_y][new_x] == 'P')
			exit_and_free("Game Over: You were caught by an enemy!\n", game);
		game->map[enemy->y][enemy->x] = '0';
		enemy->x = new_x;
		enemy->y = new_y;
		game->map[new_y][new_x] = 'A';
	}
}

/*
    direction:
    0: up
    1: down
    2: left
    3: right
*/
void	move_enemy(t_game *game, t_enemy *enemy)
{
	int	direction;
	int	new_x;
	int	new_y;

	direction = rand() % 4;
	new_x = enemy->x;
	new_y = enemy->y;
	if (direction == 0 && new_y > 0 && (game->map[new_y - 1][new_x] == '0'
		|| game->map[new_y - 1][new_x] == 'P'))
		new_y--;
	else if (direction == 1 && new_y < game->map_height - 1
		&& (game->map[new_y + 1][new_x] == '0'
		|| game->map[new_y + 1][new_x] == 'P'))
		new_y++;
	else if (direction == 2 && new_x > 0 && (game->map[new_y][new_x - 1] == '0'
		|| game->map[new_y][new_x - 1] == 'P'))
		new_x--;
	else if (direction == 3 && new_x < game->map_width - 1
		&& (game->map[new_y][new_x + 1] == '0' || game->map[new_y][new_x
		+ 1] == 'P'))
		new_x++;
	move_enemy_too(game, enemy, new_x, new_y);
}

int	move_enemies(t_game *game)
{
	static int	counter = 0;
	int			i;

	if (counter++ < 3000)
		return (0);
	counter = 0;
	i = 0;
	while (i < game->num_enemies)
	{
		move_enemy(game, &game->enemies[i]);
		i++;
	}
	game->collectibles_img_index = (game->collectibles_img_index + 1)
		% game->collectibles_img_count;
	display_map(game);
	return (0);
}
