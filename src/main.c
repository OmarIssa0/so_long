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


int main()
{
    void *mlx;
    void *mlx_win;

    mlx = mlx_init();
    if (!mlx)
    {
        fprintf(stderr, "Error: mlx_init() failed.\n");
        return 1;
    }

    mlx_win = mlx_new_window(mlx, 500, 500, "Test Window");
    if (!mlx_win)
    {
        fprintf(stderr, "Error: mlx_new_window() failed.\n");
        return 1;
    }

    // for (int i = 0; i < 100; i++)
    //     mlx_pixel_put(mlx, mlx_win, 250 + i,250 + i, 0x00FF0000);
    mlx_pixel_put(mlx, mlx_win, 250, 250, 0x00FF0000);
    mlx_loop(mlx);
    return 0;
}
