/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 07:19:57 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/12 08:09:15 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube_bonus.h"

static void	ft_key_enemy_dead(int key, t_cube *cube, int range);
static void	ft_key_enemy_hurt(int key, t_cube *cube, int range);
static void	ft_key_enemy_alive(int key, t_cube *cube, int range);

void	ft_key_enemy(int key, t_cube *cube)
{
	ft_key_enemy_dead(key, cube, ATTACK_RANGE_SWORD);
	ft_key_enemy_hurt(key, cube, ATTACK_RANGE_SWORD);
	ft_key_enemy_alive(key, cube, ATTACK_RANGE_SWORD);
}

static void	ft_key_enemy_dead(int key, t_cube *cube, int range)
{
	double	i;

	i = 0.01;
	while (i < range)
	{
		if (ft_valid_pos_enemy(cube, cube->player.x + \
			cos(cube->player.angle) * i, cube->player.y + \
			sin(cube->player.angle) * i) == DEAD_ENEMY)
			break ;
		i += 0.01;
	}
	if (i < range)
	{
		if (key == SPACE_KEY)
		{
			cube->map[(int)(cube->player.x + cos(cube->player.angle) \
				* i)][(int)(cube->player.y + sin(cube->player.angle) \
				* i)] = 0;
			cube->sword = 1;
			return ;
		}
	}
}

static void	ft_key_enemy_hurt(int key, t_cube *cube, int range)
{
	double	i;

	i = 0.01;
	while (i < range)
	{
		if (ft_valid_pos_enemy(cube, cube->player.x + \
			cos(cube->player.angle) * i, cube->player.y + \
			sin(cube->player.angle) * i) == HURT_ENEMY)
			break ;
		i += 0.01;
	}
	if (i < range)
	{
		if (key == SPACE_KEY)
		{
			cube->map[(int)(cube->player.x + cos(cube->player.angle) \
				* i)][(int)(cube->player.y + sin(cube->player.angle) \
				* i)] = DEAD_ENEMY;
			cube->sword = 1;
			return ;
		}
	}
}

static void	ft_key_enemy_alive(int key, t_cube *cube, int range)
{
	double	i;

	i = 0.01;
	while (i < range)
	{
		if (ft_valid_pos_enemy(cube, cube->player.x + \
			cos(cube->player.angle) * i, cube->player.y + \
			sin(cube->player.angle) * i) == ENEMY)
			break ;
		i += 0.01;
	}
	if (i < range)
	{
		if (key == SPACE_KEY)
		{
			cube->map[(int)(cube->player.x + cos(cube->player.angle) \
				* i)][(int)(cube->player.y + sin(cube->player.angle) \
				* i)] = HURT_ENEMY;
			cube->sword = 1;
			return ;
		}
	}
}
