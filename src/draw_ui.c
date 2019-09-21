/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:50:21 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/22 00:04:27 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_keys(t_frac *ftl)
{
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 5, 40, 0x00cccccc,
			"KEYBOARD:");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 205, 40, 0x00cccccc,
			"NUMPAD:");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 60, 0x00cccccc,
			"Move: Arrows;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 210, 60, 0x00cccccc,
			"Fast move: {2, 4, 6, 8};");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 210, 80, 0x00cccccc,
			"Zoom: + -; Fast zoom: * /;");
}

void		draw_ui(t_frac *ftl)
{
	mlx_put_image_to_window(ftl->mlx_ptr, ftl->win_ptr,
							ftl->black_img->img_ptr, -1, 0);
	mlx_put_image_to_window(ftl->mlx_ptr, ftl->win_ptr,
							ftl->black_img->img_ptr, -1, 500);
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 5, 2, 0x00cccccc,
			ftl->mem.ui ? "TAB - switch to keys" : "TAB - switch to info");
	if (ftl->type == MANDELBROT)
		mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 5, 20, 0x00cccccc,
			"Mandelbrot");
	else if (ftl->type == JULIA)
		mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 5, 20, 0x00cccccc,
			"Julia");
	else if (ftl->type == BURNING_SHIP)
		mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 5, 20, 0x00cccccc,
			"Burning Ship");
	else if (ftl->type == MANDELBAR)
		mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 5, 20, 0x00cccccc,
			"Mandelbar");
	else if (ftl->type == CELTIC)
		mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 5, 20, 0x00cccccc,
			"Celtic");
	else if (ftl->type == NEWTON)
		mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 5, 20, 0x00cccccc,
			"Newton");
	ftl->mem.ui ? draw_info(ftl) : draw_keys(ftl);
}
