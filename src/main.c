/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:07:30 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/08 21:42:49 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_type(t_frac *ftl)
{
	if (ftl->type == CNT_OF_TYPE)
		ftl->type = MANDELBROT;
	if (ftl->type == MANDELBROT)
		mandelbrot(ftl);
	else if (ftl->type == JULIA)
		julia(ftl);
}

void		init_edge(t_frac *ftl)
{
	double	step;

	ftl->min = set_complex((-2.0 / ftl->zoom), (-2.0 / ftl->zoom));
	ftl->max = set_complex((2.0 / ftl->zoom), (2.0 / ftl->zoom));
	step = 4.0 / ftl->zoom / (ftl->size - 1);
	ftl->step = set_complex(step, step);
}

void		draw(t_frac *ftl)
{
	init_type(ftl);
	mlx_put_image_to_window(ftl->mlx_ptr, ftl->win_ptr,
							ftl->img->img_ptr, 0, 0);
	if (ftl->mem.center)
		mlx_pixel_put(ftl->mlx_ptr, ftl->win_ptr, (double)ftl->size / 2,
			(double)ftl->size / 2, (255 << 16));
}

static void	input_hook(t_frac *ftl)
{
	mlx_mouse_hook(ftl->win_ptr, mouse_click, ftl);
	mlx_hook(ftl->win_ptr, 17, 1, red_x_button, (void *)0);
	mlx_hook(ftl->win_ptr, 2, 3, deal_key, ftl);
	mlx_hook(ftl->win_ptr, 6, 0, mouse_move, ftl);
}

int			main(int argc, char **argv)
{
	t_frac	*ftl;
	t_flg	*flg;

	if (argc == 1)
		usage(argv[0]);
	if (!(flg = (t_flg*)malloc(sizeof(t_flg))))
		error("No memory allocated for FLAGS");
	if (!(ftl = (t_frac*)malloc(sizeof(t_frac))))
		error("No memory allocated for FRACTOL");
	init_flg(flg, argc, argv);
	init_fractol(ftl, flg);
	draw(ftl);
	input_hook(ftl);
	mlx_loop(ftl->mlx_ptr);
	return (0);
}
