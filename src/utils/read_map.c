/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:42:57 by oissa             #+#    #+#             */
/*   Updated: 2024/12/10 16:42:57 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    read_for_fd(char *map_file, int *fd, char **tmp)
{
    *fd = open(map_file, O_RDONLY);

    if (*fd == -1)
    {
        ft_dprintf(2, "Error: open() failed\n");
        exit (EXIT_FAILURE);
    }
    *tmp = ft_strdup(""); 
    if (!tmp)
    {
        ft_dprintf(2, "Error: memory allocation failed\n");
        close(*fd);
        exit(EXIT_FAILURE);
    }
}


void    save_for_map(char *map_file, t_game *game)
{
    int     fd;
    char    *line;
    char    *tmp;

    check_file_name(map_file);
    read_for_fd(map_file, &fd, &tmp);
    while ((line = get_next_line(fd)))
    {
        char *new_tmp = ft_strjoin(tmp, line);
        free(tmp); 
        free(line);
        tmp = new_tmp;
        if (!tmp)
        {
            ft_dprintf(2, "Error: memory allocation failed\n");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }
    check_map_empty(game, tmp, fd);
    // game->map = ft_split(tmp, '\n');
    // free(tmp);
    // close(fd);
}

void    check_map_empty(t_game *game, char *tmp, int fd)
{
    if (tmp[0] == '\0' || !tmp)
    {
        ft_dprintf(2, "Error: empty map\n");
        free(tmp);
        close(fd);
        free_resources(game);
        exit(EXIT_FAILURE);
    }

    game->map = ft_split(tmp, '\n');
    free(tmp);
    close(fd);
    if (!game->map)
    {
        ft_dprintf(2, "Error: memory allocation failed\n");
        free_resources(game);
        exit(EXIT_FAILURE);
    }
}
