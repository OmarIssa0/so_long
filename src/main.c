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

int close_window(void *param)
{
    (void)param;
    exit(0);
}
int main(int ac, char **av)
{
    t_game game;

    if (ac != 2)
    {
        ft_dprintf(2, "Error: invalid number of arguments\n");
        return (1);
    }
    char *map_file = av[1];

    int fd = open(map_file, O_RDONLY);
    if (fd == -1)
    {
        ft_dprintf(2, "Error: open() failed\n");
        return (1);
    }
    char *line = NULL;
    line = malloc(100);
    if (!line)
    {
        ft_dprintf(2, "Error: malloc() failed\n");
        return (1);
    }
    game.map = malloc(100 * sizeof(char *));
    int i = 0;
    while ((line = get_next_line(fd)))
    {
        game.map[i] = ft_strdup(line);
        printf("%s", game.map[i++]);
        free(line);
    }
    close(fd);
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
    mlx_put_image_to_window(game.mlx, game.mlx_win, game.player_img, 200, 200);
    // mlx_key_hook(game.mlx_win, handle_keypress, &game);
    mlx_hook(game.mlx_win, 17, 0, close_window, NULL);
    mlx_loop(game.mlx);

    return (0);
}

/*
read map.

char *buffer;

while (1)
{
    buffer = get_next_line(fd);
    if (buffer == NULL)
        break;
    else
    {
        str = ft_strjoin(str, buffer);
        free(buffer);
    }
}
map = ft_split(str, '\n');
free(str);
*/

/*
    int i;
    int j;

    i = 0;
    while (map[i])
        i++;
    while (map[0][j])
        j++;
    width = i;
    high = j;
*/