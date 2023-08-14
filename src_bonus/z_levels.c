/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_levels.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:16:05 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/13 11:38:36 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube_bonus.h"

void	ft_levels(t_cube *cube)
{
	char	*s[2];

	cube->win = 0;
	if (cube->lvl == 1)
		s[1] = "maps/level_2.cub";
	if (cube->lvl == 2)
		s[1] = "maps/level_3.cub";
	if (cube->lvl == 3)
		s[1] = "maps/level_4.cub";
	if (cube->lvl == 4)
		s[1] = "maps/level_5.cub";
	cube->win = 0;
	cube->lvl += 1;
	ft_free(cube);
	ft_cube(s, cube->lvl);
}
