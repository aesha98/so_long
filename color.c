/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shahida <shahida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:54:50 by shahida           #+#    #+#             */
/*   Updated: 2022/07/20 18:11:18 by shahida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_color ft_new_color(int r, int g, int b, int a)
{
    t_color color;
    
    color.r = (char)r;
    color.g = (char)g;
    color.b = (char)b;
    color.a = (char)a;
    return(color);
}

void ft_pixel_to_color(char *pixel, t_color color)
{
    pixel[0] = color.r;
    pixel[1] = color.g;
    pixel[2] = color.b;
    pixel[3] = color.a;
}

void ft_img_to_color(t_image *img, t_color color)
{
    int x;
    int y;

    y = 0;
    while (y < img->size.y)
    {
        x = 0;
        while (x < img->size.x)
        {
            ft_pixel_to_color(&img->pixels[x * 4 + img->line_size * y], color);
            x++;
        }
        y++;
    }
    
}