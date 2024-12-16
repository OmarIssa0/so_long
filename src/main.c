/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:47:22 by oissa             #+#    #+#             */
/*   Updated: 2024/12/16 20:04:46 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
	{
		ft_dprintf(2, "Error: invalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	ft_bzero(&game, sizeof(t_game));
	save_for_map(av[1], &game);
	check_map(&game);
	check_map_too(&game);
	find_player_position(&game);
	check_exit(&game);
	can_play(&game);
	init_game(&game);
	display_image(&game);
	mlx_hook(game.mlx_win, 17, 0, close_window, &game);
	mlx_hook(game.mlx_win, KeyPress, KeyRelease, handle_keypress, &game);
	display_map(&game);
	mlx_loop(game.mlx);
	free_resources(&game);
	return (EXIT_SUCCESS);
}
