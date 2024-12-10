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

// int handle_keypress(int keycode, void *param)
// {
//     t_game *game = (t_game *)param;

//     if (keycode == 53)
//     {
//         mlx_destroy_window(game->mlx, game->mlx_win);
//         exit(0);
//     }
//     return (0);
// }

// int close_window(void *param)
// {
//     (void)param;
//     exit(0);
// }
// int main(int ac, char **av)
// {
//     t_game game;

//     if (ac != 2)
//     {
//         ft_dprintf(2, "Error: invalid number of arguments\n");
//         return (1);
//     }
//     char *map_file = av[1];

//     int fd = open(map_file, O_RDONLY);
//     if (fd == -1)
//     {
//         ft_dprintf(2, "Error: open() failed\n");
//         return (1);
//     }
//     char *line = NULL;
//     line = malloc(100);
//     if (!line)
//     {
//         ft_dprintf(2, "Error: malloc() failed\n");
//         return (1);
//     }
//     game.map = malloc(100 * sizeof(char *));
//     int i = 0;
//     while ((line = get_next_line(fd)))
//     {
//         game.map[i] = ft_strdup(line);
//         printf("%s", game.map[i++]);
//         free(line);
//     }
//     close(fd);
//     game.mlx = mlx_init();
//     if (!game.mlx)
//     {
//         ft_dprintf(2, "Error: mlx_init() failed\n");
//         return (1);
//     }
//     game.mlx_win = mlx_new_window(game.mlx, 800, 600, "so_long");
//     if (!game.mlx_win)
//     {
//         ft_dprintf(2, "Error: mlx_new_window() failed\n");
//         return (1);
//     }
//     game.player_img = mlx_xpm_file_to_image(game.mlx, IMAGE_PLAYER_PATH, &game.img_width, &game.img_height);
//     if (!game.player_img)
//     {
//         ft_dprintf(2, "Error: mlx_xpm_file_to_image() failed\n");
//         return (1);
//     }
//     mlx_put_image_to_window(game.mlx, game.mlx_win, game.player_img, 200, 200);
//     mlx_key_hook(game.mlx_win, handle_keypress, &game);
//     mlx_hook(game.mlx_win, 17, 0, close_window, NULL);
//     mlx_loop(game.mlx);

//     return (0);
// }


int main (int ac, char *av[])
{
    t_game game;

    if (ac != 2)
    {
        ft_dprintf(2, "Error: invalid number of arguments\n");
        exit (EXIT_FAILURE);
    }
    save_for_map(av[1], &game);
    check_map(&game);
    free_map(&game);
    return (0);
}