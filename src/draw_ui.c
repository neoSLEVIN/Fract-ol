/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ui.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 21:50:21 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/22 15:55:48 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_keys3(t_frac *ftl)
{
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 20, 280 + LM, 0x00cccccc,
			"Left Shift/Ctrl;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 300 + LM, 0x00cccccc,
			"Choose color:");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 15, 320 + LM, 0x00cccccc,
			"All: 0;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 15, 340 + LM, 0x00cccccc,
			"Certain: 1-9;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 380 + LM, 0x00cccccc,
			"Change RGB of color: Right Shift/Ctrl;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 400 + LM, 0x00cccccc,
			"Change Red|Green|Blue of color: Q A|W S|E D;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 440 + LM, 0x00cccccc,
			"Change Damping Number(NEWTON): < >;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 460 + LM, 0x00cccccc,
			"Change Max Iterations(Color = 0): < >;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 480 + LM, 0x00cccccc,
			"Change Gradient(Color [1-max color count]): < >;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 500 + LM, 0x00cccccc,
			"Change Image Size: F1 F2;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 540 + LM, 0x00cccccc,
			"Exit: Esc;");
}

static void	draw_keys2(t_frac *ftl)
{
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 210, 320 + LM, 0x00cccccc,
			"Choose side fractal: LMC;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 5, 60 + LM, 0x00cccccc,
			"KEYBOARD:");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 80 + LM, 0x00cccccc,
			"Move: Arrows;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 100 + LM, 0x00cccccc,
			"Fractals:");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 15, 120 + LM, 0x00cccccc,
			"Prev/Next: F G;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 15, 140 + LM, 0x00cccccc,
			"On/Off other: M;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 160 + LM, 0x00cccccc,
			"Center: Space;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 180 + LM, 0x00cccccc,
			"Psycho: P;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 200 + LM, 0x00cccccc,
			"Output cmd: O;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 220 + LM, 0x00cccccc,
			"Roots(max 5)/Power:");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 20, 240 + LM, 0x00cccccc,
			"+ -;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 10, 260 + LM, 0x00cccccc,
			"Switch colors:");
	draw_keys3(ftl);
}

static void	draw_keys(t_frac *ftl)
{
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 205, 60 + LM, 0x00cccccc,
			"NUMPAD:");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 210, 80 + LM, 0x00cccccc,
			"Fast move: {2, 4, 6, 8};");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 210, 100 + LM, 0x00cccccc,
			"Zoom: + -; Fast zoom: * /;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 210, 120 + LM, 0x00cccccc,
			"Centralize(default/custom):");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 220, 140 + LM, 0x00cccccc,
			"Zoom: 1 0; Camera: Enter 5;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 210, 160 + LM, 0x00cccccc,
			"Color mode: dot;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 205, 200 + LM, 0x00cccccc,
			"MOUSE:");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 210, 220 + LM, 0x00cccccc,
			"Move dot to center: LMC;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 210, 240 + LM, 0x00cccccc,
			"Zoom: Scroll;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 210, 260 + LM, 0x00cccccc,
			"K(Julia)/Root(Newton):Scroll;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 210, 280 + LM, 0x00cccccc,
			"Scroll mode: Scroll click;");
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 210, 300 + LM, 0x00cccccc,
			"Auto K/Root: RMC;");
	draw_keys2(ftl);
}

void		draw_ui(t_frac *ftl)
{
	mlx_put_image_to_window(ftl->mlx_ptr, ftl->win_ptr,
							ftl->black_img->img_ptr, -1, 0);
	mlx_put_image_to_window(ftl->mlx_ptr, ftl->win_ptr,
							ftl->black_img->img_ptr, -1, 500);
	ftl->type == MANDELBROT ? mlx_string_put(ftl->mlx_ptr, ftl->win_ptr,
			5, 2 + LM, 0x00cccccc, "Mandelbrot") : 0;
	ftl->type == JULIA ? mlx_string_put(ftl->mlx_ptr, ftl->win_ptr,
			5, 2 + LM, 0x00cccccc, "Julia") : 0;
	ftl->type == BURNING_SHIP ? mlx_string_put(ftl->mlx_ptr, ftl->win_ptr,
			5, 2 + LM, 0x00cccccc, "Burning Ship") : 0;
	ftl->type == MANDELBAR ? mlx_string_put(ftl->mlx_ptr, ftl->win_ptr,
			5, 2 + LM, 0x00cccccc, "Mandelbar") : 0;
	ftl->type == CELTIC ? mlx_string_put(ftl->mlx_ptr, ftl->win_ptr,
			5, 2 + LM, 0x00cccccc, "Celtic") : 0;
	ftl->type == NEWTON ? mlx_string_put(ftl->mlx_ptr, ftl->win_ptr,
			5, 2 + LM, 0x00cccccc, "Newton") : 0;
	mlx_string_put(ftl->mlx_ptr, ftl->win_ptr, 5, 25 + LM, 0x00cccccc,
			ftl->mem.ui ? "TAB - switch to keys" : "TAB - switch to info");
	ftl->mem.ui ? draw_info(ftl) : draw_keys(ftl);
}
