
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:47:22 by oissa             #+#    #+#             */
/*   Updated: 2024/12/06 17:47:22 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void free_resources(t_game *game)
{
    if (game->player_img)
        mlx_destroy_image(game->mlx, game->player_img);
    if (game->wall_img)
        mlx_destroy_image(game->mlx, game->wall_img);
    // if (game->exit_img)
    //     mlx_destroy_image(game->mlx, game->exit_img);
    // if (game->collectible_img)
    //     mlx_destroy_image(game->mlx, game->collectible_img);
    if (game->floor_img)
        mlx_destroy_image(game->mlx, game->floor_img);
    if (game->mlx_win)
        mlx_destroy_window(game->mlx, game->mlx_win);
    mlx_destroy_display(game->mlx);
    if (game->mlx)
        free(game->mlx);
    free_map(game);
}

void display_image_in_window(t_game *game, int x, int y, void *img)
{
    if (img)
        mlx_put_image_to_window(game->mlx, game->mlx_win, img, x * WIDTH_SIZE, y * HEIGHT_SIZE);
}

void display_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (game->map[i][j] == '1')
                // display_image_in_window(game, j, i, game->wall_img);
                display_image_in_window(game, j, i, game->wall_img);
            else if (game->map[i][j] == 'P')
                display_image_in_window(game, j, i, game->player_img);
                // display_image_in_window(game, j, i, game->player_img);
            // else if (game->map[i][j] == 'E')
            //     display_image_in_window(game, j, i, game->exit_img);
            // else if (game->map[i][j] == 'C')
            //     display_image_in_window(game, j, i, game->collectible_img);
            else
                display_image_in_window(game, j, i, game->floor_img);
            j++;
        }
        i++;
    }
}

int handle_keypress(int keycode, void *param)
{
    t_game *game;

    game = (t_game *)param;
    if (keycode == 113)
    {
        free_resources(game);
        exit(EXIT_SUCCESS);
    }
    return (EXIT_SUCCESS);
}

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
    game.mlx = mlx_init();
    if (!game.mlx)
    {
        ft_dprintf(2, "Error: mlx_init() failed\n");
        free_map(&game);
        exit(EXIT_FAILURE);
    }
    game.mlx_win = mlx_new_window(game.mlx, game.map_width * STANDARD_SIZE, game.map_height * STANDARD_SIZE, "so_long");
    if (!game.mlx_win)
    {
        ft_dprintf(2, "Error: mlx_new_window() failed\n");
        free_resources(&game);
        exit(EXIT_FAILURE);
    }

    // game.img_width = STANDARD_SIZE;
    // game.img_height = STANDARD_SIZE;
   
    // Ensure all images are loaded before using them
    game.floor_img = mlx_xpm_file_to_image(game.mlx, IMAGE_WALL_PATH, &game.img_width, &game.img_height);
    game.player_img = mlx_xpm_file_to_image(game.mlx, IMAGE_PLAYER_PATH, &game.img_width, &game.img_height);
    
    // game.exit_img = mlx_xpm_file_to_image(game.mlx, IMAGE_EXIT_PATH, &width, &height);
    // game.collectible_img = mlx_xpm_file_to_image(game.mlx, IMAGE_COLLECTIBLE_PATH, &width, &height);
    game.wall_img = mlx_xpm_file_to_image(game.mlx, IMAGE_FLOOR_PATH, &game.img_width, &game.img_height);

    if (!game.wall_img || !game.player_img)
    {
        ft_dprintf(2, "Error: failed to load one or more images\n");
        free_resources(&game);
        exit(EXIT_FAILURE);
    }

    mlx_key_hook(game.mlx_win, handle_keypress, &game);
    display_map(&game);
    mlx_loop(game.mlx);
    free_resources(&game);
    return (0);
}
