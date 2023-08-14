/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_img_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 05:40:06 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/13 11:30:15 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cube_bonus.h"

int	update_loop(t_cube *cube)
{
	if (!cube->welcome_window)
		return (1);
	if (!cube->mouse_drag)
		return (1);
	if (!cube->escape && !cube->lost && !cube->help_menu && !cube->win)
	{
		ft_update_image(cube);
		if (cube->map_has_enemies)
			ft_pollution(cube, cube->map);
	}
	return (1);
}
