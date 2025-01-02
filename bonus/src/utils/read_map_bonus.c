/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:42:57 by oissa             #+#    #+#             */
/*   Updated: 2025/01/02 18:16:26 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	check_map_width(t_game *game, char *tmp, int fd)
{
	int	i;
	int	width;
	int	current_width;

	i = 0;
	width = 0;
	current_width = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
		{
			if (width == 0)
				width = current_width;
			else if (current_width != width)
				exit_error("Error: invalid map width", game, fd, tmp);
			current_width = 0;
		}
		else
			current_width++;
		i++;
	}
	game->map_width = width;
}

void	read_for_fd(char *map_file, int *fd, char **tmp)
{
	*fd = open(map_file, O_RDONLY);
	if (*fd == -1)
	{
		ft_dprintf(2, "Error: open() failed\n");
		exit(EXIT_FAILURE);
	}
	*tmp = ft_strdup("");
	if (!tmp)
	{
		ft_dprintf(2, "Error: memory allocation failed\n");
		close(*fd);
		exit(EXIT_FAILURE);
	}
}

void	save_for_map(char *map_file, t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*new_tmp;

	check_file_name(map_file);
	read_for_fd(map_file, &fd, &tmp);
	line = get_next_line_bonus(fd);
	while (line)
	{
		new_tmp = ft_strjoin(tmp, line);
		if (!new_tmp)
		{
			free(tmp);
			free(line);
			exit_error_and_close_fd("Error: memory allocation failed", fd);
		}
		free(tmp);
		free(line);
		tmp = new_tmp;
		if (!tmp)
			exit_error_and_close_fd("Error: memory allocation failed", fd);
		line = get_next_line_bonus(fd);
	}
	check_map_empty(game, tmp, fd);
}

/*
	example:
	111111
	\n
	111111
	result -> error
*/
void	check_map_line(t_game *game, char *tmp, int fd)
{
	int	i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n' && (i == 0 || tmp[i - 1] == '\n'))
			exit_error("Error: invalid map with empty lines", game, fd, tmp);
		i++;
	}
}

void	check_map_empty(t_game *game, char *tmp, int fd)
{
	if (tmp[0] == '\0' || !tmp)
		exit_error("Error: empty map", game, fd, tmp);
	check_map_line(game, tmp, fd);
	check_map_width(game, tmp, fd);
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
