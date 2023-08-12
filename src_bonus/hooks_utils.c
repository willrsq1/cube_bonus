/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:13:23 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/12 07:19:55 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube_bonus.h"

static void	ft_move_right(t_cube *cube);
static void	ft_move_left(t_cube *cube);

void	ft_key_pressed(int key, t_cube *cube)
{
	printf("%d\n", key);
	if (key == ESC_KEY)
		ft_free_exit(cube);
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
	if (key == P_KEY)
		cube->animation = (cube->animation + 1) % 2;
	ft_key_enemy(key, cube);
}

bool	ft_check_player_position(t_cube *cube)
{
	cube->enemy = 0;
	if (ft_valid_pos_bonus(cube, cube->player.x, cube->player.y) > 0)
	{
		if (ft_valid_pos_bonus(cube, cube->player.prev_x, cube->player.y) <= 0)
			cube->player.x = cube->player.prev_x;
		else if (ft_valid_pos_bonus(cube, \
			cube->player.x, cube->player.prev_y) <= 0)
			cube->player.y = cube->player.prev_y;
		else
		{
			cube->player.x = cube->player.prev_x;
			cube->player.y = cube->player.prev_y;
			return (CANCEL_THE_MOVEMENT);
		}
	}
	if (cube->enemy)
	{
		if (ft_valid_pos_enemy(cube, cube->player.x, cube->player.y) <= ENEMY)
		{
			cube->player.x = cube->player.prev_x;
			cube->player.y = cube->player.prev_y;
			return (CANCEL_THE_MOVEMENT);
		}
	}
	return (POSITION_IS_GOOD);
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
