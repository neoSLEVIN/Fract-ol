/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:58:33 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/05 23:07:28 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_click(int button, int x, int y, void *param)
{
	t_frac		*ftl;
	t_complex	edge;
	double		temp;

	ftl = (t_frac*)param;
	edge.re = (double)x - ((double)ftl->size / 2);
	edge.im = (double)y - ((double)ftl->size / 2);
	edge = set_complex(edge.re / (ftl->size - 1), edge.im / (ftl->size - 1));
	temp = 4.0 / ftl->zoom;
	edge = set_complex(edge.re / temp, edge.im / temp);
	if (button == 4)
	{
		ftl->cam.re += edge.re * (1.0 - 1.0 / ZOOM);
		ftl->cam.im += edge.im * (1.0 - 1.0 / ZOOM);
		ftl->zoom *= ZOOM;
	}
	else if (button == 5)
	{
		ftl->cam.re += edge.re * (1.0 - ZOOM);
		ftl->cam.im += edge.im * (1.0 - ZOOM);
		ftl->zoom /= ZOOM;
	}
	ftl->zoom < 0.05 ? ftl->zoom = 0.05 : 0;
	draw(ftl);
	return (0);
}
