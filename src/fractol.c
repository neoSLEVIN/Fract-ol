/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:30:24 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/01 01:34:36 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_rgb		get_grad_color(t_grad *grad, double t)
{
	t_rgb	color;
	double	d_r;
	int		part;

	if (t <= 0)
		return (grad->col[0]);
	else if (t >= 1)
		return (grad->col[grad->col_cnt - 1]);
	else
	{
		part = 0;
		while (++part < grad->col_cnt - 1)
			if (t >= grad->range[part - 1] && t < grad->range[part])
				break ;
	}
	d_r = (t - grad->range[part - 1]) /
		(grad->range[part] - grad->range[part - 1]);
	color.r = grad->col[part - 1].r +
		d_r * (grad->col[part].r - grad->col[part - 1].r);
	color.g = grad->col[part - 1].g +
		d_r * (grad->col[part].g - grad->col[part - 1].g);
	color.b = grad->col[part - 1].b +
		d_r * (grad->col[part].b - grad->col[part - 1].b);
	return (color);
}

void		set_grad_colors(t_frac *ftl, t_flg *flg)
{
	int	i;

	ftl->grad.col_cnt = flg->col_cnt;
	hex_to_rgb("f", &ftl->grad.col[0]);
	hex_to_rgb("8", &ftl->grad.col[1]);
	hex_to_rgb("0", &ftl->grad.col[2]);
	ftl->grad.range[0] = 0;
	ftl->grad.range[1] = 0.5;
	i = -1;
	if (flg->flag & F_COL)
		while (++i < flg->col_cnt)
		{
			ftl->grad.col[i].r = flg->grad.col[i].r;
			ftl->grad.col[i].g = flg->grad.col[i].g;
			ftl->grad.col[i].b = flg->grad.col[i].b;
		}
	i = 0;
	if (flg->flag & F_GRD)
		while (++i < flg->col_cnt - 1)
			ftl->grad.range[i] = flg->grad.range[i];
	ftl->grad.range[flg->col_cnt - 1] = 1;
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
	ftl->size = set_point(flg->size, flg->size);
	ftl->win_ptr =
		mlx_new_window(ftl->mlx_ptr, ftl->size.x, ftl->size.y, "fract'ol");
	if (!ftl->win_ptr)
		error("Failed to create a new window");
	new_image(ftl, ftl->size);
	set_grad_colors(ftl, flg);
	ftl->type = flg->type;
	ftl->iter = flg->iter;
	ftl->zoom = 1;
	ftl->flg = flg;
}
