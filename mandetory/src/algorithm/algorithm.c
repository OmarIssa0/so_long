/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:58:35 by oissa             #+#    #+#             */
/*   Updated: 2024/12/17 19:05:09 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/*
    Algorithm DFS to find the shortest path 
    Depth First Search (DFS) is an algorithm for traversing 
    or searching tree or graph data structures.


    dfs(game, x + 1, y, visited) -> right
    dfs(game, x - 1, y, visited) -> left
    dfs(game, x, y + 1, visited) -> down
    dfs(game, x, y - 1, visited) -> up
*/
void	dfs(t_game *game, int x, int y, bool **visited)
{
	int		rows;
	int		cols;
	char	**map;

	rows = game->map_height;
	cols = game->map_width;
	map = game->map;
	if (x < 0 || y < 0 || x >= cols || y >= rows || map[y][x] == '1'
		|| visited[y][x])
		return ;
	visited[y][x] = true;
	dfs(game, x + 1, y, visited);
	dfs(game, x - 1, y, visited);
	dfs(game, x, y + 1, visited);
	dfs(game, x, y - 1, visited);
}

/*
    Free the visited array
*/
void	free_visited(bool **visited, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

/*
    Validate the malloc function
*/
void	validate_malloc(bool **visited, int rows, int cols, t_game *game)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		visited[i] = ft_calloc(cols, sizeof(bool));
		if (!visited[i])
		{
			ft_dprintf(2, "Error: memory allocation failed\n");
			free_visited(visited, rows);
			free_resources(game);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

/*
    Check if the player can finish the game
*/
bool	can_finish_game(t_game *game, bool **visited, int rows, int cols)
{
	int	y;
	int	x;

	y = 0;
	while (y < rows)
	{
		x = 0;
		while (x < cols)
		{
			if (game->map[y][x] == 'C' && !visited[y][x])
				return (false);
			if (game->map[y][x] == 'E' && !visited[y][x])
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

/*
    Check if the player can finish the game
*/
bool	can_player_finish_game(t_game *game)
{
	int		rows;
	int		cols;
	bool	**visited;
	bool	can_finish;

	rows = game->map_height;
	cols = game->map_width;
	visited = malloc(rows * sizeof(bool *));
	if (!visited)
	{
		ft_dprintf(2, "Error: memory allocation failed\n");
		free_resources(game);
		exit(EXIT_FAILURE);
	}
	validate_malloc(visited, rows, cols, game);
	dfs(game, game->player_x, game->player_y, visited);
	can_finish = true;
	can_finish = can_finish_game(game, visited, rows, cols);
	free_visited(visited, rows);
	return (can_finish);
}
