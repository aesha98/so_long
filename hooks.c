/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shahida <shahida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:54:54 by shahida           #+#    #+#             */
/*   Updated: 2022/07/21 13:16:13 by shahida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int ft_input(int keycode, void *param)
{
    t_program *program;

    program = (t_program *) param;
   // mlx function that clears the window
	mlx_clear_window(program->mlx, program->window.ref);

	// move in a direction based on the key
	if (keycode == 124)
		program->sprite_position.x += program->sprite.size.x;
	else if (keycode == 123)
		program->sprite_position.x -= program->sprite.size.x;
	else if (keycode == 125)
		program->sprite_position.y += program->sprite.size.y;
	else if (keycode == 126)
		program->sprite_position.y -= program->sprite.size.y;
	// change color based on keys R, G and B.
	else if (keycode == 15)
		turn_img_to_color(&program->sprite, new_color(255,0,0,0));
	else if (keycode == 5)
		turn_img_to_color(&program->sprite, new_color(0,255,0,0));
	else if (keycode == 11)
		turn_img_to_color(&program->sprite, new_color(0,0,255,0));

	// mlx function that puts and image into a window at a given position
	// (the position 0,0 is the upper-left corner)
	mlx_put_image_to_window(program->mlx, program->window.ref,
		program->sprite.ref, program->sprite_position.x, program->sprite_position.y);

	// print the key pressed so you know the number of each key
	printf("Key pressed -> %d\n", keycode);
	return (0);
}

int ft_update(void *param)
{
    t_program *program;

    static int	frame;

	// add a frame and every x frames change the position by 1 pixel
	// so it looks like its animated
	frame++;
	if (frame == ANIMATION_FRAMES)
		program->sprite_position.y += 1;
	// every x*2 frames go back that pixel to loop the animation
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->sprite_position.y -= 1;
		frame = 0;
	}
	
	mlx_put_image_to_window(program->mlx, program->window.ref,
		program->sprite.ref, program->sprite_position.x, program->sprite_position.y);

	return (0);

}