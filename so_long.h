/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shahida <shahida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:46:06 by shahida           #+#    #+#             */
/*   Updated: 2022/07/21 13:06:27 by shahida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

typedef struct s_vector
{
    int x;
    int y;
}   t_vector;

typedef struct s_window
{
    void        *ref;
    t_vector    size;
}               t_window;

typedef struct s_color
{
    int r;
    int g;
    int b;
    int a;
} t_color;

typedef struct s_images
{
    void		*ref;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
} t_image;

typedef struct s_program
{
    void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
} t_program;

int ft_input(int keycode, void *param);
int ft_update (void *param);


void ft_img_to_color(t_image *img, t_color color);
void ft_pixel_to_color(char *pixel, t_color color);
void ft_img_to_color(t_image *img, t_color color);

t_color ft_new_color(int r, int g, int b, int a);

t_image ft_new_image(int height, int width, void* mlx_pointer);
t_image ft_new_sprite(void *mlx_pointer, char *path);

t_window ft_new_window(int width, int height, void *mlx, char *name);

#endif