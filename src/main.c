/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:07:30 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/22 02:34:15 by cschoen          ###   ########.fr       */
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

void		set_grad_colors(t_frac *ftl, t_flg *flg)
{
	int	i;

	i = -1;
	ftl->grad.col_cnt = flg->grad.col_cnt;
	if (!(flg->flag & F_COL))
	{
		ftl->grad.col_cnt = 3;
		hex_to_rgb("0", &ftl->grad.col[0]);
		hex_to_rgb("8", &ftl->grad.col[1]);
		hex_to_rgb("f", &ftl->grad.col[2]);
		ftl->grad.range[0] = 1;
		ftl->grad.range[1] = 0.5;
		ftl->grad.range[2] = 0;
	}
	else
		while (++i < flg->grad.col_cnt)
		{
			ftl->grad.col[i].r = flg->grad.col[i].r;
			ftl->grad.col[i].g = flg->grad.col[i].g;
			ftl->grad.col[i].b = flg->grad.col[i].b;
			ftl->grad.range[i] = flg->grad.range[i];
		}
}

static void	draw_lines(t_frac *ftl)
{
	int	x;
	int	y;

	x = 499;
	y = -1;
	while (++y <= 600)
		mlx_pixel_put(ftl->mlx_ptr, ftl->win_ptr, x, y, 0x0000FF00);
	y = 500;
	while (++x <= 1000)
		mlx_pixel_put(ftl->mlx_ptr, ftl->win_ptr, x, y, 0x0000FF00);
	while (++y <= 600)
	{
		mlx_pixel_put(ftl->mlx_ptr, ftl->win_ptr, 599, y, 0x0000FF00);
		mlx_pixel_put(ftl->mlx_ptr, ftl->win_ptr, 699, y, 0x0000FF00);
		mlx_pixel_put(ftl->mlx_ptr, ftl->win_ptr, 799, y, 0x0000FF00);
		mlx_pixel_put(ftl->mlx_ptr, ftl->win_ptr, 899, y, 0x0000FF00);
	}
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
	draw_lines(ftl);
	draw(ftl, M_KEY);
	draw_ui(ftl);
	input_hook(ftl);
	mlx_loop(ftl->mlx_ptr);
	return (0);
}
