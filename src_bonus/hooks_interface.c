/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_interface.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 22:30:10 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/12 22:30:44 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube_bonus.h"

static void	pause_screen_image(int key, t_cube *cube);

void	esc_key_function(int key, t_cube *cube)
{
	ft_create_image(cube);
	if (cube->escape)
	{
		if ((key == ENTER_KEY && cube->escape == PAUSE_RIGHT) || key == ESC_KEY)
			ft_free_exit(cube);
		else if (key == ENTER_KEY && cube->escape == PAUSE_LEFT)
		{
			cube->escape = 0;
			cube->start = ft_time();
			if (!cube->welcome_window)
				put_my_img_to_img(0, 0, cube->sprites[LANDING], cube->img);
		}
		else if (key == LEFT_ARROW || key == RIGHT_ARROW)
			pause_screen_image(key, cube);
		else
			put_my_img_to_img(0, 0, cube->sprites[cube->escape], cube->img);
	}
	else
	{
		cube->escape = PAUSE_LEFT;
		put_my_img_to_img(0, 0, cube->sprites[PAUSE_LEFT], cube->img);
	}
	ft_destroy_image(cube);
}

static void	pause_screen_image(int key, t_cube *cube)
{
	if (key == LEFT_ARROW)
	{
		cube->escape = PAUSE_LEFT;
		put_my_img_to_img(0, 0, cube->sprites[PAUSE_LEFT], cube->img);
	}
	else if (key == RIGHT_ARROW)
	{
		cube->escape = PAUSE_RIGHT;
		put_my_img_to_img(0, 0, cube->sprites[PAUSE_RIGHT], cube->img);
	}
}

void	help_menu_function(int key, t_cube *cube)
{
	ft_create_image(cube);
	if (cube->help_menu)
	{
		cube->help_menu = 0;
		if (key == ENTER_KEY && !cube->welcome_window)
			put_my_img_to_img(0, 0, cube->sprites[LANDING], cube->img);
		else if (cube->escape)
			put_my_img_to_img(0, 0, cube->sprites[cube->escape], cube->img);
		else if (!cube->welcome_window)
			put_my_img_to_img(0, 0, cube->sprites[LANDING], cube->img);
		else
			put_my_img_to_img(0, 0, cube->sprites[HELP], cube->img);
	}
	else
	{
		cube->help_menu = 1;
		put_my_img_to_img(0, 0, cube->sprites[HELP], cube->img);
	}
	ft_destroy_image(cube);
}
