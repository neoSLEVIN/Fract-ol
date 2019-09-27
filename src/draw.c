/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:10:02 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/28 00:57:08 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_edge(t_frac *ftl)
{
	double	step;

	ftl->min = set_complex((-2.0 / ftl->zoom), (-2.0 / ftl->zoom));
	ftl->max = set_complex((2.0 / ftl->zoom), (2.0 / ftl->zoom));
	step = 4.0 / ftl->zoom / (ftl->size - 1);
	ftl->step = set_complex(step, step);
}

static void	draw_side(t_frac *ftl)
{
	t_img	*side;
	int		i;

	side = ftl->side_imgs;
	ftl->min = set_complex(-2.0, -2.0);
	ftl->max = set_complex(2.0, 2.0);
	ftl->step = set_complex(4.0 / (100 - 1), 4.0 / (100 - 1));
	i = -1;
	while (++i < 5)
		draw_fractol(ftl, &side[i], i);
	i = -1;
	while (++i < 5)
		mlx_put_image_to_window(ftl->mlx_ptr, ftl->win_ptr, side[i].img_ptr,
								side[i].pos.x, side[i].pos.y);
}

static void	draw_border(t_frac *ftl)
{
	int	x;
	int	y;
	int	end_x;
	int	end_y;

	x = ftl->img->pos.x - 1;
	y = ftl->img->pos.y - 1;
	end_x = x + ftl->size + 1;
	end_y = y + ftl->size + 1;
	mlx_pixel_put(ftl->mlx_ptr, ftl->win_ptr, x, y, 0x0000FF00);
	while (++x <= end_x)
	{
		mlx_pixel_put(ftl->mlx_ptr, ftl->win_ptr, x, y, 0x0000FF00);
		mlx_pixel_put(ftl->mlx_ptr, ftl->win_ptr, x, end_y, 0x0000FF00);
	}
	x = ftl->img->pos.x - 1;
	while (++y <= end_y)
	{
		mlx_pixel_put(ftl->mlx_ptr, ftl->win_ptr, x, y, 0x0000FF00);
		mlx_pixel_put(ftl->mlx_ptr, ftl->win_ptr, end_x, y, 0x0000FF00);
	}
}

void		draw(t_frac *ftl, int key)
{
	if (ftl->mem.side && key != TAB)
		draw_side(ftl);
	if (!ftl->mem.side && key == M_KEY)
		mlx_put_image_to_window(ftl->mlx_ptr, ftl->win_ptr,
								ftl->black_img->img_ptr, 500, 501);
	init_edge(ftl);
	if (key != TAB)
		draw_fractol(ftl, ftl->img, -1);
	if (key == INC_IMG || key == DEC_IMG)
		mlx_put_image_to_window(ftl->mlx_ptr, ftl->win_ptr,
								ftl->black_img->img_ptr, 500, -100);
	mlx_put_image_to_window(ftl->mlx_ptr, ftl->win_ptr, ftl->img->img_ptr,
							ftl->img->pos.x, ftl->img->pos.y);
	if (ftl->size < 500 && (key == M_KEY || key == INC_IMG || key == DEC_IMG))
		draw_border(ftl);
	if (ftl->mem.center)
		mlx_pixel_put(ftl->mlx_ptr, ftl->win_ptr, 750, 250, 0x00FF0000);
	if (ftl->mem.ui || key == TAB || key == F_KEY || key == G_KEY || key == -3)
		draw_ui(ftl);
}
