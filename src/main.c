/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:07:30 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/20 22:28:10 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		plot(t_img *img, t_point *coord, t_rgb *color)
{
	int	*i;

	i = (int *)img->data;
	i[coord->y * img->size + coord->x] =
		(color->r > 255 ? 511 - color->r : color->r) << 16 |
		(color->g > 255 ? 511 - color->g : color->g) << 8 |
		(color->b > 255 ? 511 - color->b : color->b);
}

static void	init_edge(t_frac *ftl)
{
	double	step;

	ftl->min = set_complex((-2.0 / ftl->zoom), (-2.0 / ftl->zoom));
	ftl->max = set_complex((2.0 / ftl->zoom), (2.0 / ftl->zoom));
	step = 4.0 / ftl->zoom / (ftl->size - 1);
	ftl->step = set_complex(step, step);
}

void		draw(t_frac *ftl)
{
	if (ftl->type == CNT_OF_TYPES)
		ftl->type = MANDELBROT;
	if (ftl->type > CNT_OF_TYPES)
		ftl->type = CNT_OF_TYPES - 1;
	init_edge(ftl);
	if (ftl->type == JULIA)
		julia(ftl);
	else if (ftl->type == BURNING_SHIP)
		burning_ship(ftl);
	else if (ftl->type == MANDELBAR)
		mandelbar(ftl);
	else if (ftl->type == CELTIC)
		celtic(ftl);
	else if (ftl->type == NEWTON)
		newton(ftl);
	else
		mandelbrot(ftl);
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
	mlx_hook(ftl->win_ptr, 6, (1L << 6), mouse_move, ftl);
	mlx_loop_hook(ftl->mlx_ptr, no_hook, ftl);
}

int			main(int argc, char **argv)
{
	t_frac	*ftl;

	if (argc == 1)
		usage(argv[0]);
	if (!(ftl = (t_frac*)malloc(sizeof(t_frac))))
		error("No memory allocated for FRACTOL");
	if (!(ftl->flg = (t_flg*)malloc(sizeof(t_flg))))
		error("No memory allocated for FLAGS");
	if (!(ftl->cp = (t_complex*)malloc(sizeof(t_complex) * 2)))
		error("No memory allocated for COMPLEX POINTERS");
	init_flg(ftl->flg, argc, argv);
	init_fractol(ftl, ftl->flg);
	draw(ftl);
	input_hook(ftl);
	mlx_loop(ftl->mlx_ptr);
	return (0);
}
