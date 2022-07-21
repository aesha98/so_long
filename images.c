/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shahida <shahida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:54:58 by shahida           #+#    #+#             */
/*   Updated: 2022/07/21 13:02:22 by shahida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_image ft_new_image(int height, int width, void* mlx_pointer)
{
    t_image img;

    img.ref = mlx_new_image(mlx_pointer, width, height);
    img.size.x = width;
    img.size.y = height;
    img.pixels = mlx_get_data_addr(img.ref, &img.bits_per_pixel, &img.line_size, &img.endian);

    return (img);
}

t_image ft_new_sprite(void *mlx_pointer, char *path)
{
    t_image img;

    img.ref = mlx_xpm_file_to_image(mlx_pointer, path, &img.size.x, &img.size.y);
    img.pixels = mlx_get_data_addr(img.ref, &img.bits_per_pixel, &img.line_size, &img.endian);
    return(img);
}