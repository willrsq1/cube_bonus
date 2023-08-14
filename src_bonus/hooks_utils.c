/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:13:23 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/12 22:31:12 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube_bonus.h"

static void	ft_move_right(t_cube *cube);
static void	ft_move_left(t_cube *cube);

void	ft_key_pressed(int key, t_cube *cube)
{
	if (key == ESC_KEY || cube->escape)
		esc_key_function(key, cube);
	if (key == H_KEY || cube->help_menu)
		help_menu_function(key, cube);
	if (key == A_KEY)
		cube->player.angle -= 0.07;
	if (key == Z_KEY)
		cube->player.angle += 0.07;
	if (key == UP_ARROW)
	{
			cube->player.x += cos(cube->player.angle) / 10;
			cube->player.y += sin(cube->player.angle) / 10;
	}
	if (key == DOWN_ARROW)
	{
		cube->player.x -= cos(cube->player.angle) / 10;
		cube->player.y -= sin(cube->player.angle) / 10;
	}
	if (key == RIGHT_ARROW)
		ft_move_right(cube);
	if (key == LEFT_ARROW)
		ft_move_left(cube);
	if (key == P_KEY && cube->welcome_window)
		cube->animation = (cube->animation + 1) % 2;
	ft_key_enemy(key, cube);
}

static void	ft_move_right(t_cube *cube)
{
	if (cube->player.angle > 0 && cube->player.angle < PI)
	{
		cube->player.x -= cos(cube->player.angle + PI / 2) / 10;
		cube->player.y -= sin(cube->player.angle + PI / 2) / 10;
	}
	else
	{
		cube->player.x += cos(cube->player.angle - PI / 2) / 10;
		cube->player.y += sin(cube->player.angle - PI / 2) / 10;
	}
}

static void	ft_move_left(t_cube *cube)
{
	if (cube->player.angle > 0 && cube->player.angle < PI)
	{
		cube->player.x -= cos(cube->player.angle - PI / 2) / 10;
		cube->player.y -= sin(cube->player.angle - PI / 2) / 10;
	}
	else
	{
		cube->player.x += cos(cube->player.angle + PI / 2) / 10;
		cube->player.y += sin(cube->player.angle + PI / 2) / 10;
	}
}
