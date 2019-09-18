/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:24:17 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/18 03:48:45 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_flg(t_flg *flg, int ac, char **av)
{
	flg->help = 0;
	flg->flag = 0;
	flg->args = 2;
	flg->size = 500;
	flg->iter = 100;
	flg->app = av[0];
	flg->pow = 2;
	flg->grad.col_cnt = 3;
	flg->grad.range[0] = 1;
	flg->grad.range[1] = 0.5;
	flg->grad.range[2] = 0;
	hex_to_rgb("f", &flg->grad.col[0]);
	hex_to_rgb("8", &flg->grad.col[1]);
	hex_to_rgb("0", &flg->grad.col[2]);
	flg->cam = set_complex(0, 0);
	flg->zoom = 1;
	flg->k = set_complex(-0.79, 0.15);
	valid_stdin(flg, ac, av);
}

static void	init_root(t_root *root)
{
	root->cnt = 5;
	root->damping = set_complex(1, 0);
	root->roots[0] = set_complex(0, 0);
	root->roots[1] = set_complex(0.5444, 0.736);
	root->roots[2] = set_complex(-0.5444, 0.736);
	root->roots[3] = set_complex(0.5444, -0.736);
	root->roots[4] = set_complex(-0.5444, -0.736);
	root->cols[0] = set_rgb(113, 162, 201);
	root->cols[1] = set_rgb(0, 112, 201);
	root->cols[2] = set_rgb(235, 222, 87);
	root->cols[3] = set_rgb(235, 213, 0);
	root->cols[4] = set_rgb(138, 255, 192);
}

static void	new_image(t_frac *ftl, int size)
{
	if (!(ftl->img = (t_img*)malloc(sizeof(t_img))))
		error("No memory allocated for new image");
	if (!(ftl->img->img_ptr = mlx_new_image(ftl->mlx_ptr, size, size)))
		error("Failed to create a new image");
	ftl->img->data = mlx_get_data_addr(ftl->img->img_ptr, &ftl->img->bpp,
									&ftl->img->size_line, &ftl->img->endian);
	ftl->img->size.x = size;
	ftl->img->size.y = size;
}

void		set_grad_colors(t_frac *ftl, t_flg *flg)
{
	int	i;

	i = -1;
	ftl->grad.col_cnt = flg->grad.col_cnt;
	if (!((flg->flag & F_COL) || (flg->flag & F_GRD)))
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

void		init_fractol(t_frac *ftl, t_flg *flg)
{
	if (!(ftl->mlx_ptr = mlx_init()))
		error("Failed to set up the connection to the X server");
	ftl->size = flg->size;
	ftl->win_ptr =
		mlx_new_window(ftl->mlx_ptr, ftl->size, ftl->size, "fract'ol");
	if (!ftl->win_ptr)
		error("Failed to create a new window");
	new_image(ftl, ftl->size);
	set_grad_colors(ftl, flg);
	flg->flag =
		((flg->flag & F_COL) || (flg->flag & F_GRD)) ? (F_COL + F_GRD) : 0;
	ftl->type = flg->type;
	ftl->iter = flg->iter;
	ftl->zoom = flg->zoom;
	ftl->cam = flg->cam;
	ftl->pow = flg->pow;
	ftl->mem.zoom = 1;
	ftl->mem.cam = set_complex(0, 0);
	ftl->mem.mouse_hook = 0;
	ftl->mem.mouse_zoom = 0;
	ftl->mem.color = 0;
	ftl->mem.center = 0;
	ftl->mem.ui = 0;
	ftl->k = flg->k;
	init_root(&ftl->root);
}
