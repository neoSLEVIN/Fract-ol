/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grad.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 20:19:49 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/17 20:19:49 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grad.h"

void			change_grad(t_grad *grad, int color, int left)
{
	if (color == 0 || color >= grad->col_cnt - 1)
		return ;
	if (left && grad->range[color] - RANGE >= grad->range[color + 1])
		grad->range[color] -= RANGE;
	else if (!left && grad->range[color] + RANGE <= grad->range[color - 1])
		grad->range[color] += RANGE;
}

static t_rgb	true_color(t_rgb col1, t_rgb col2, double d_r)
{
	t_rgb	color;

	col1.r > 255 ? col1.r = 511 - col1.r : 0;
	col1.g > 255 ? col1.g = 511 - col1.g : 0;
	col1.b > 255 ? col1.b = 511 - col1.b : 0;
	col2.r > 255 ? col2.r = 511 - col2.r : 0;
	col2.g > 255 ? col2.g = 511 - col2.g : 0;
	col2.b > 255 ? col2.b = 511 - col2.b : 0;
	color.r = col1.r + d_r * (col2.r - col1.r);
	color.g = col1.g + d_r * (col2.g - col1.g);
	color.b = col1.b + d_r * (col2.b - col1.b);
	return (color);
}

t_rgb			get_grad_color(t_grad *grad, double t)
{
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
	return (true_color(grad->col[part], grad->col[part - 1], d_r));
}
