/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:24:17 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/27 22:37:53 by cschoen          ###   ########.fr       */
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

static void	init_mem(t_mem *mem)
{
	mem->cam = set_complex(0, 0);
	mem->mouse_hook = 0;
	mem->mouse_zoom = 0;
	mem->no_hook = 0;
	mem->center = 0;
	mem->color = 0;
	mem->zoom = 1;
	mem->side = 0;
	mem->ui = 0;
}

void		init_root_pos(t_root *root, int cnt)
{
	root->roots[0] = set_complex(0.0, 0.0);
	if (cnt == 2)
	{
		root->roots[0] = set_complex(-0.9, 0.9);
		root->roots[1] = set_complex(0.9, -0.9);
	}
	else if (cnt == 3)
	{
		root->roots[1] = set_complex(0.0, 0.5);
		root->roots[2] = set_complex(0.0, -0.5);
	}
	else if (cnt == 4)
	{
		root->roots[1] = set_complex(0.0, 0.3);
		root->roots[2] = set_complex(0.75, -0.5);
		root->roots[3] = set_complex(-0.75, -0.5);
	}
	else
	{
		root->roots[1] = set_complex(-0.5444, 0.736);
		root->roots[2] = set_complex(0.5444, 0.736);
		root->roots[3] = set_complex(0.5444, -0.736);
		root->roots[4] = set_complex(-0.5444, -0.736);
	}
}

static void	init_root(t_root *root, int cnt, t_grad *grad)
{
	int	i;

	i = -1;
	root->cnt = cnt > 5 ? 5 : cnt;
	root->damping = set_complex(1.5, 0);
	hex_to_rgb("0ff", &root->cols[0]);
	hex_to_rgb("0", &root->cols[1]);
	hex_to_rgb("ff0", &root->cols[2]);
	hex_to_rgb("00f", &root->cols[3]);
	hex_to_rgb("f00", &root->cols[4]);
	while (++i < grad->col_cnt && i < 5)
		root->cols[i] = grad->col[i];
	init_root_pos(root, cnt);
}

void		init_fractol(t_frac *ftl, t_flg *flg)
{
	if (!(ftl->mlx_ptr = mlx_init()))
		error("Failed to set up the connection to the X server");
	ftl->size = flg->size;
	ftl->win_ptr = mlx_new_window(ftl->mlx_ptr, 1000, 600, "fract'ol");
	!ftl->win_ptr ? error("Failed to create a new window") : 0;
	ftl->type = flg->type;
	new_image(ftl, ftl->size);
	new_black_image(ftl);
	new_side_image(ftl, 99);
	flg->flag = ((flg->flag & F_COL) || (flg->flag & F_GRD)) ? F_COL : 0;
	set_grad_colors(ftl, flg);
	ftl->iter = flg->iter;
	ftl->zoom = flg->zoom;
	ftl->cam = flg->cam;
	ftl->pow = flg->pow;
	ftl->k = flg->k;
	init_mem(&ftl->mem);
	init_root(&ftl->root, flg->pow, &ftl->grad);
}
