/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 05:58:46 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/13 19:00:48 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube_bonus.h"

static void	ft_wall_pixel_enemy(t_cube *cube, int x, int y, double column_size);

void	draw_column_enemy(double dist, t_cube *cube, int x)
{
	int		wall_size;
	int		half_of_wall_size;
	int		y;

	if (dist < 0.1)
		dist = 0.1;
	wall_size = WIN_HEIGHT / (dist);
	half_of_wall_size = wall_size / 2;
	if (half_of_wall_size > WIN_HEIGHT / 2)
		half_of_wall_size = WIN_HEIGHT / 2;
	y = WIN_HEIGHT / 2 - half_of_wall_size + cube->height - 1;
	cube->id = ft_cat_frame(cube);
	while (y <= WIN_HEIGHT / 2 + half_of_wall_size + cube->height - 1)
	{
		ft_wall_pixel_enemy(cube, x, y, wall_size);
		y++;
	}
}

static void	ft_wall_pixel_enemy(t_cube *cube, int x, int y, double column_size)
{
	double			x_wall;
	double			y_wall;
	unsigned int	color;

	x_wall = cube->player.x_wall * cube->sprites[cube->id].img_width;
	y_wall = ((double)column_size / (double)cube->sprites[cube->id].img_width);
	y_wall = (y - (WIN_HEIGHT / 2 - (column_size / 2) + cube->height)) / y_wall;
	color = get_pixel_img(cube->sprites[cube->id], x_wall, y_wall);
	if (!(color == 0xFFFFFF || color == 0xFF000000 || color == 0x000000))
		ft_pixel(cube->img, x, y + column_size / 4, color);
}

int	ft_cat_frame(t_cube *cube)
{
	time_t	time;
	int		id;

	time = (ft_time() - cube->start) % 1000;
	if (time > 500)
		cube->player.x_wall = 1 - cube->player.x_wall;
	if (cube->id == HURT_ENEMY)
		return (CAT_HURT);
	if (cube->id == DEAD_ENEMY)
		return (CAT_DEAD);
	if (cube->id == ENEMY)
		return (CAT0);
	time = time % 500;
	if (time > 750 / 2)
		id = CAT4;
	if (time > 500 / 2)
		id = CAT3;
	if (time > 250 / 2)
		id = CAT2;
	else
		id = CAT1;
	return (id);
}

int	ft_valid_pos_enemy(t_cube *cube, double x, double y)
{
	if (x < 0 || \
		y < 0 || \
		y > cube->map_width || \
		x > cube->map_lenght || \
		cube->map[(int)x][(int)y] == END || \
		cube->map[(int)x][(int)y] == WALL)
		return (END);
	if (cube->map[(int)x][(int)y] <= ENEMY)
		return (cube->map[(int)x][(int)y]);
	return (0);
}
