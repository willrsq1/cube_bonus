/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 23:21:29 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/12 08:07:18 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube_bonus.h"

int	ft_key_hook(int key, t_cube *cube)
{
	cube->player.prev_x = cube->player.x;
	cube->player.prev_y = cube->player.y;
	ft_key_pressed(key, cube);
	if (ft_check_player_position(cube) == CANCEL_THE_MOVEMENT)
		return (1);
	ft_key_hook_bonus(key, cube);
	return (1);
}

void	ft_update_image(t_cube *cube)
{
	cube->img->img_ptr = mlx_new_image(cube->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cube->img->img_ptr)
	{
		perror("at mlx_new_image in ft_update_image");
		ft_free_exit(cube);
	}
	cube->img->addr = mlx_get_data_addr(cube->img->img_ptr, &cube->img->bpp, \
		&cube->img->size_line, &cube->img->endian);
	if (!cube->img->addr)
	{
		perror("at mlx_new_image in launch_mlx");
		ft_free_exit(cube);
	}
	ft_raycasting(cube, &cube->player);
	ft_update_image_bonus(cube);
	if (cube->animation)
	{
		if (!cube->sword)
			put_my_img_to_img(WIN_WIDTH * 0.6, WIN_HEIGHT - 250, cube->sprites[SWORD], cube->img);
		else
			put_my_img_to_img(WIN_WIDTH * 0.4, WIN_HEIGHT - 350, cube->sprites[SWORD2], cube->img);
		cube->sword = 0;
	}
	ft_destroy_image(cube);
}

void	ft_destroy_image(t_cube *cube)
{
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img->img_ptr, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img->img_ptr);
	cube->img->img_ptr = NULL;
}

int	ft_close(t_cube *cube)
{
	ft_free_exit(cube);
	return (1);
}
