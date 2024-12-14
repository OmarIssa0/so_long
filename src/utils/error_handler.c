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
    if (map_file[i - 4] != '.' || map_file[i - 3] != 'b' 
        || map_file[i - 2] != 'e' || map_file[i - 1] != 'r')
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
