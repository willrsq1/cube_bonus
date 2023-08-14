/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_cube.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:57:24 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/13 20:44:29 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube_bonus.h"

static void	ft_init(char **argv, t_cube *cube, t_img *img);
static void	launch_mlx(t_cube *cube);
static void	launch_assets(t_cube *cube);
static void	launch_window(t_cube *cube);

void	ft_cube(char **argv, int level)
{
	t_cube	cube;
	t_img	img;

	ft_init(argv, &cube, &img);
	cube.lvl = level;
	launch_mlx(&cube);
	launch_assets(&cube);
	launch_window(&cube);
}

static void	ft_init(char **argv, t_cube *cube, t_img *img)
{
	ft_bzero(cube, sizeof(t_cube));
	ft_bzero(img, sizeof(t_img));
	cube->fd = -1;
	cube->ceiling_color = -1;
	cube->floor_color = -1;
	cube->minimap = 1;
	cube->mouse_drag = 1;
	cube->animation = 1;
	cube->weapon = SWORD;
	cube->map = ft_map(argv[1], cube);
	print_map(cube->map, cube->map_lenght, cube);
	ft_check_map_is_closed(cube, cube->map);
	get_player_position(cube);
	cube->img = img;
	cube->start = ft_time();
	cube->id = CAT1;
}

static void	launch_mlx(t_cube *cube)
{
	cube->mlx = mlx_init();
	if (!cube->mlx)
		ft_error("at mlx_init in launch_mlx", ": malloc", NULL, cube);
	cube->mlx_win = mlx_new_window(cube->mlx, WIN_WIDTH, WIN_HEIGHT, "Cube");
	if (!cube->mlx_win)
		ft_error("at mlx_new_window in launch_mlx", ": malloc", NULL, cube);
	cube->img->img_ptr = mlx_new_image(cube->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cube->img->img_ptr)
		ft_error("at mlx_new_image in launch_mlx", ": malloc", NULL, cube);
	cube->img->addr = mlx_get_data_addr(cube->img->img_ptr, &cube->img->bpp, \
		&cube->img->size_line, &cube->img->endian);
	if (!cube->img->addr)
		ft_error("at mlx_data_addr in launch_mlx", ": malloc", NULL, cube);
}

static void	launch_assets(t_cube *cube)
{
	get_img(cube, &cube->sprites[MINNIE], "assets/minnie.xpm");
	get_img(cube, &cube->sprites[CAT1], "assets/cat/cat1.xpm");
	get_img(cube, &cube->sprites[CAT2], "assets/cat/cat2.xpm");
	get_img(cube, &cube->sprites[CAT3], "assets/cat/cat3.xpm");
	get_img(cube, &cube->sprites[CAT4], "assets/cat/cat4.xpm");
	get_img(cube, &cube->sprites[DOOR], "assets/cat/cat4.xpm");
	get_img(cube, &cube->sprites[BRICK], "assets/cat/cat4.xpm");
	get_img(cube, &cube->sprites[NORTH], cube->text_north);
	get_img(cube, &cube->sprites[SOUTH], cube->text_south);
	get_img(cube, &cube->sprites[WEST], cube->text_west);
	get_img(cube, &cube->sprites[EAST], cube->text_east);
	get_img(cube, &cube->sprites[CAT0], "assets/cat/cat_5.xpm");
	get_img(cube, &cube->sprites[CAT_HURT], "assets/cat/cat_6.xpm");
	get_img(cube, &cube->sprites[CAT_DEAD], "assets/cat/cat_7.xpm");
	get_img(cube, &cube->sprites[SWORD], "assets/cat/sword.xpm");
	get_img(cube, &cube->sprites[SWORD2], "assets/cat/sword2.xpm");
	get_img(cube, &cube->sprites[GUN], "assets/cat/gun.xpm");
	get_img(cube, &cube->sprites[GUN2], "assets/cat/gun2.xpm");
	get_img(cube, &cube->sprites[LANDING], "assets/cat/landing.xpm");
	get_img(cube, &cube->sprites[PAUSE_LEFT], "assets/cat/pause_left.xpm");
	get_img(cube, &cube->sprites[PAUSE_RIGHT], "assets/cat/pause_right.xpm");
	get_img(cube, &cube->sprites[LOST], "assets/cat/lost.xpm");
	get_img(cube, &cube->sprites[HELP], "assets/cat/help.xpm");
	get_img(cube, &cube->sprites[WIN], "assets/cat/victory.xpm");
	get_img(cube, &cube->sprites[TOMB], "assets/cat/tomb.xpm");
	get_img(cube, &cube->sprites[MINI_HURT], "assets/cat/cat_hurt.xpm");
}

static void	launch_window(t_cube *cube)
{
	put_my_img_to_img(0, 0, cube->sprites[LANDING], cube->img);
	mlx_hook(cube->mlx_win, 2, 1L << 0, ft_key_hook, cube);
	mlx_hook(cube->mlx_win, 17, 1L << 17, ft_close, cube);
	ft_hooks_bonus(cube);
	mlx_loop_hook(cube->mlx, update_loop, cube);
	mlx_put_image_to_window(cube->mlx, cube->mlx_win, cube->img->img_ptr, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img->img_ptr);
	cube->img->img_ptr = NULL;
	mlx_loop(cube->mlx);
}
