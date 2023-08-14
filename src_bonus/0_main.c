/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wruet-su <william.ruetsuquet@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 18:57:37 by wruet-su          #+#    #+#             */
/*   Updated: 2023/08/13 09:16:50 by wruet-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube_bonus.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (write(2, "Input one arg only\n", 19), 1);
	ft_cube(argv, 1);
}
