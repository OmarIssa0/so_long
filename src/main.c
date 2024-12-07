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

void load_images(t_game *game)
{
    game->player_img = mlx_xpm_file_to_image(game->mlx, "./5.xpm", &game->img_width, &game->img_height);
    game->wall_img = mlx_xpm_file_to_image(game->mlx, "./5.xpm", &game->img_width, &game->img_height);
    game->exit_img = mlx_xpm_file_to_image(game->mlx, "./5.xpm", &game->img_width, &game->img_height);
    game->floor_img = mlx_xpm_file_to_image(game->mlx, "./5.xpm", &game->img_width, &game->img_height);
    game->collectible_img = mlx_xpm_file_to_image(game->mlx, "./5.xpm", &game->img_width, &game->img_height);

    if (!game->player_img || !game->wall_img || !game->exit_img || !game->floor_img || !game->collectible_img)
    {
        ft_dprintf(2, "Error: mlx_xpm_file_to_image() failed\n");
        exit(1);
    }
}

void render_map(t_game *game, char **map, int map_width, int map_height)
{
    int x;
    int y;

    y = 0;
    while (y < map_height)
    {
        x = 0;
        while (x < map_width)
        {
            if (map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall_img, x * 64, y * 64);
            else if (map[y][x] == 'E')
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit_img, x * 64, y * 64);
            else if (map[y][x] == 'C')
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->collectible_img, x * 64, y * 64);
            else
                mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor_img, x * 64, y * 64);
            x++;
        }
        y++;
    }
}

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == 53)
    {
        mlx_destroy_window(game->mlx, game->mlx_win);
        exit(0);
    }
    if (keycode == 13)
    {
        game->player_y--;
    }
    if (keycode == 1)
    {
        game->player_y++;
    }
    if (keycode == 0)
    {
        game->player_x--;
    }
    if (keycode == 2)
    {
        game->player_x++;
    }

    render_map(game, game->map, game->map_width, game->map_height);

    return (0);
}

int close_window(void *param)
{
    (void)param;
    exit(0);
}
int main(void)
{
    t_game game;

    game.mlx = mlx_init();
    if (!game.mlx)
    {
        ft_dprintf(2, "Error: mlx_init() failed\n");
        return (1);
    }

    game.mlx_win = mlx_new_window(game.mlx, 800, 600, "so_long");
    if (!game.mlx_win)
    {
        ft_dprintf(2, "Error: mlx_new_window() failed\n");
        return (1);
    }

    game.player_img = mlx_xpm_file_to_image(game.mlx, "./5.xpm", &game.img_width, &game.img_height);
    if (!game.player_img)
    {
        ft_dprintf(2, "Error: mlx_xpm_file_to_image() failed\n");
        return (1);
    }

    mlx_put_image_to_window(game.mlx, game.mlx_win, game.player_img, 0, 0);
    mlx_key_hook(game.mlx_win, handle_keypress, &game);
    mlx_hook(game.mlx_win, 17, 0, close_window, NULL);
    mlx_loop(game.mlx);

    return (0);
}

