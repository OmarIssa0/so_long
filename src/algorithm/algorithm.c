/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oissa <oissa@student.42amman.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:58:35 by oissa             #+#    #+#             */
/*   Updated: 2024/12/14 16:58:35 by oissa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/*
    Algorithm DFS to find the shortest path 
    Depth First Search (DFS) is an algorithm for traversing 
    or searching tree or graph data structures.
*/

// void dfs(char **map, int rows, int cols, int x, int y, bool **visited)
// {
//     // إذا خرجنا عن حدود الخريطة أو كان الموقع غير صالح
//     if (x < 0 || y < 0 || x >= cols || y >= rows || map[y][x] == '1' || visited[y][x])
//         return;

//     // وضع علامة على هذا الموقع كمُزار
//     visited[y][x] = true;

//     // تحرك في الاتجاهات الأربعة
//     dfs(map, rows, cols, x + 1, y, visited); // يمين
//     dfs(map, rows, cols, x - 1, y, visited); // يسار
//     dfs(map, rows, cols, x, y + 1, visited); // أسفل
//     dfs(map, rows, cols, x, y - 1, visited); // أعلى
// }

// bool can_player_finish_game(t_game *game)
// {
//     int rows = game->map_height; // عدد صفوف الخريطة
//     int cols = game->map_width; // عدد أعمدة الخريطة

//     // إنشاء مصفوفة لتتبع المواقع التي تمت زيارتها
//     bool **visited = malloc(rows * sizeof(bool *));
//     int i = 0;
//     while (i < rows)
//     {
//         visited[i] = ft_calloc(cols, sizeof(bool));
//         if (!visited[i])
//         {
//             ft_dprintf(2, "Error: memory allocation failed\n");
//             free_resources(game);
//             exit(EXIT_FAILURE);
//         }
//         i++;
//     }

//     // تشغيل DFS من موقع اللاعب
//     dfs(game->map, rows, cols, game->player_x, game->player_y, visited);

//     // التحقق مما إذا كان جميع العناصر القابلة للجمع والخروج قد تم الوصول إليها
//     bool can_finish = true;
//     int y = 0;
//     while (y < rows)
//     {
//         int x = 0;
//         while (x < cols)
//         {
//             if (game->map[y][x] == 'C' && !visited[y][x])
//             {
//                 can_finish = false; // لم يتم الوصول إلى أحد العناصر
//             }
//             if (game->map[y][x] == 'E' && !visited[y][x])
//             {
//                 can_finish = false; // لم يتم الوصول إلى الخروج
//             }
//             x++;
//         }
//         y++;
//     }

//     // تحرير الذاكرة
//     i = 0;
//     while (i < rows)
//     {
//         free(visited[i]);
//         i++;
//     }
//     free(visited);

//     return can_finish;
// }

#include "../../include/so_long.h"
#include <stdbool.h>
#include <stdlib.h>

void dfs(char **map, int rows, int cols, int x, int y, bool **visited)
{
    if (x < 0 || y < 0 || x >= cols || y >= rows || map[y][x] == '1' || visited[y][x])
        return;

    visited[y][x] = true;

    dfs(map, rows, cols, x + 1, y, visited);
    dfs(map, rows, cols, x - 1, y, visited);
    dfs(map, rows, cols, x, y + 1, visited);
    dfs(map, rows, cols, x, y - 1, visited);
}

bool can_player_finish_game(t_game *game)
{
    int rows = game->map_height;
    int cols = game->map_width;

    bool **visited = malloc(rows * sizeof(bool *));
    for (int i = 0; i < rows; i++)
    {
        visited[i] = ft_calloc(cols, sizeof(bool));
    }

    dfs(game->map, rows, cols, game->player_x, game->player_y, visited);

    bool can_finish = true;
    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            if (game->map[y][x] == 'C' && !visited[y][x])
            {
                can_finish = false;
            }
            if (game->map[y][x] == 'E' && !visited[y][x])
            {
                can_finish = false;
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        free(visited[i]);
    }
    free(visited);

    return can_finish;
}
