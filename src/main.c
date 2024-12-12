/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:47:22 by oissa             #+#    #+#             */
/*   Updated: 2024/12/12 21:13:43 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int main(int ac, char *av[])
{
    t_game game;

    if (ac != 2)
    {
        ft_dprintf(2, "Error: invalid number of arguments\n");
        exit(EXIT_FAILURE);
    }
    save_for_map(av[1], &game);
    check_map(&game);
    check_map_too(&game);
    init_game(&game);
    find_player_position(&game);
    display_image(&game);
    mlx_key_hook(game.mlx_win, handle_keypress, &game);
    display_map(&game);
    mlx_loop(game.mlx);
    free_resources(&game);
    return (EXIT_SUCCESS);
}
