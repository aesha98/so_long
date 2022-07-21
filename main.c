/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shahida <shahida@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:45:34 by shahida           #+#    #+#             */
/*   Updated: 2022/07/21 13:09:49 by shahida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
    t_program  program;

    program.mlx = mlx_init();
    program.window = ft_new_window(program.mlx, 1980, 1080, "so_long");

    program.sprite = ft_new_sprite(program.mlx, "block.xpm");
    program.sprite_position.x = 0;
    program.sprite_position.y = 0;

    mlx_put_image_to_window(program.mlx, program.window.ref, 
    program.sprite.ref, program.sprite_position.x, program.sprite_position.y);

    mlx_key_hook(program.window.ref, *ft_input, &program);
    mlx_loop_hook(program.mlx, *ft_update, &program);
    /*keep the program in constant state of runnning*/
    mlx_loop(program.mlx);
}