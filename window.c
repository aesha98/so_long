/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shahida <shahida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:55:04 by shahida           #+#    #+#             */
/*   Updated: 2022/07/21 13:09:11 by shahida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

int ft_close()
{
    exit(0);
}

t_window ft_new_window(int width, int height, void *mlx, char *name)
{
    t_window window;

    window.ref = mlx_new_window(mlx, width, height, name);
    window.size.x = width;
    window.size.y = height;

    mlx_hook(mlx, 17, 0, ft_close, NULL);

    return(window);
}