/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:47:22 by oissa             #+#    #+#             */
/*   Updated: 2024/12/20 17:59:15 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
	get_enemy_number(&game);
	initialize_enemies(&game);
	srand(time(NULL));
	mlx_hook(game.mlx_win, 17, 0, close_window, &game);
	mlx_hook(game.mlx_win, KeyPress, KeyRelease, handle_keypress, &game);
	display_map(&game);
	mlx_loop_hook(game.mlx, move_enemies, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
