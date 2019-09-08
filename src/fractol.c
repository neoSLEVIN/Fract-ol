/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:30:24 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/05 22:55:46 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb		get_grad_color(t_grad *grad, double t)
{
	t_rgb	color;
	double	d_r;
	int		part;

	if (t >= 1)
		return (grad->col[0]);
	else if (t <= 0)
		return (grad->col[grad->col_cnt - 1]);
	else
	{
		part = 0;
		while (++part < grad->col_cnt - 1)
			if (t < grad->range[part - 1] && t >= grad->range[part])
				break ;
	}
	d_r = (t - grad->range[part]) /
		(grad->range[part - 1] - grad->range[part]);
	color.r = grad->col[part].r +
		d_r * (grad->col[part - 1].r - grad->col[part].r);
	color.g = grad->col[part].g +
		d_r * (grad->col[part - 1].g - grad->col[part].g);
	color.b = grad->col[part].b +
		d_r * (grad->col[part - 1].b - grad->col[part].b);
	return (color);
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

static void	new_image(t_frac *ftl, t_point size)
{
	if (!(ftl->img = (t_img*)malloc(sizeof(t_img))))
		error("No memory allocated for new image");
	if (!(ftl->img->img_ptr = mlx_new_image(ftl->mlx_ptr, size.x, size.y)))
		error("Failed to create a new image");
	ftl->img->data = mlx_get_data_addr(ftl->img->img_ptr, &ftl->img->bpp,
									&ftl->img->size_line, &ftl->img->endian);
	ftl->img->size.x = size.x;
	ftl->img->size.y = size.y;
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
	new_image(ftl, set_point(ftl->size, ftl->size));
	set_grad_colors(ftl, flg);
	flg->flag =
		((flg->flag & F_COL) || (flg->flag & F_GRD)) ? (F_COL + F_GRD) : 0;
	ftl->type = flg->type;
	ftl->iter = flg->iter;
	ftl->zoom = flg->zoom;
	ftl->mem.zoom = 1;
	ftl->cam = flg->cam;
	ftl->mem.cam = set_complex(0, 0);
	ftl->mem.mouse_hook = 0;
	ftl->mem.color = 0;
	ftl->k = flg->k;
	ftl->flg = flg;
}
