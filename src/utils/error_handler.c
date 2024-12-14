/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:44:20 by oissa             #+#    #+#             */
/*   Updated: 2024/12/10 16:44:20 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    check_file_name(char *map_file)
{
    int i;

    i = 0;
    while (map_file[i])
        i++;
    if (map_file[i - 4] != '.' || map_file[i - 3] != 'b' || map_file[i - 2] != 'e' || map_file[i - 1] != 'r')
    {
        ft_dprintf(2, "Error: invalid file name\n");
        exit (EXIT_FAILURE);
    }
}

void    check_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
        i++;
    game->map_height = i;
    j = 0;
    while (game->map[0][j])
        j++;
    game->map_width = j;
}
void    check_width_and_height(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
            j++;
        if (j != game->map_width)
        {
            ft_dprintf(2, "Error: invalid map width\n");
            free_resources(game);
            exit(EXIT_FAILURE);
        }
        i++;
    }
    if (i != game->map_height)
    {
        ft_dprintf(2, "Error: invalid map height\n");
        free_resources(game);
        exit(EXIT_FAILURE);
    }
}
void    check_map_content(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (game->map[i])
    {
        j = 0;
        while (game->map[i][j])
        {
            if (game->map[i][j] != '0' && game->map[i][j] != '1' && game->map[i][j] != 'C' && game->map[i][j] != 'E' && game->map[i][j] != 'P')
            {
                ft_dprintf(2, "Error: invalid map content\n");
                free_resources(game);
                exit(EXIT_FAILURE);
            }
            j++;
        }
        i++;
    }
}
void check_map_walls(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map_width)
    {
        if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
        {
            ft_dprintf(2, "Error: map is not surrounded by walls\n");
            free_resources(game);
            exit(EXIT_FAILURE);
        }
        i++;
    }

    i = 0;
    while (i < game->map_height)
    {
        if (game->map[i][0] != '1' || game->map[i][game->map_width - 1] != '1')
        {
            ft_dprintf(2, "Error: map is not surrounded by walls\n");
            free_resources(game);
            exit(EXIT_FAILURE);
        }
        i++;
    }
}

void    check_map_shape(t_game *game)
{
    int i;
    int row_len;

    i = 0;
    row_len = ft_strlen(game->map[0]);
    while (game->map[i])
    {
        if ((int)ft_strlen(game->map[i]) != row_len)
        {
            ft_dprintf(2, "Error: map is not rectangular\n");
            free_resources(game);
            exit(EXIT_FAILURE);
        }
        i++;
    }
}
void    check_exit(t_game *game)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (game->map[i][j] == 'E')
                count++;
            j++;
        }
        i++;
    }
    if (count != 1)
    {
        ft_dprintf(2, "Error: invalid number of exits\n");
        free_resources(game);
        exit(EXIT_FAILURE);
    }
}

void    check_collectibles(t_game *game)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (game->map[i][j] == 'C')
                count++;
            j++;
        }
        i++;
    }
    if (count == 0)
    {
        ft_dprintf(2, "Error: no collectibles found\n");
        free_resources(game);
        exit(EXIT_FAILURE);
    }
}

void    check_player(t_game *game)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (game->map[i][j] == 'P')
                count++;
            j++;
        }
        i++;
    }
    if (count != 1)
    {
        ft_dprintf(2, "Error: invalid number of players\n");
        free_resources(game);
        exit(EXIT_FAILURE);
    }
}


void    check_map_too(t_game *game)
{
    check_width_and_height(game);
    check_map_content(game);
    check_map_walls(game);
    check_collectibles(game);
    check_player(game);
    check_exit(game);
    check_map_shape(game);
}