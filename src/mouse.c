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
	double		zoom;

	ftl = (t_frac*)param;
	zoom = ZOOM * 1.5;
	edge.re = ((double)x - ((double)ftl->size / 2)) / ftl->size;
	edge.im = ((double)y - ((double)ftl->size / 2)) / ftl->size;
	edge.re *= ftl->max.re - ftl->min.re;
	edge.im *= ftl->max.re - ftl->min.re;
	if (button == 1)
		ftl->cam = set_complex(ftl->cam.re + edge.re, ftl->cam.im - edge.im);
	else if (ftl->type != JULIA &&
		(button == 4 || (button == 5 && ftl->zoom / zoom > 0.05)))
	{
		ftl->cam.re += edge.re * (1.0 - ((button == 4) ? (1.0 / zoom) : zoom));
		ftl->cam.im -= edge.im * (1.0 - ((button == 4) ? (1.0 / zoom) : zoom));
		ftl->zoom *= (button == 4) ? zoom : (1.0 / zoom);
	}
	else if (ftl->type == JULIA && (button == 4 || button == 5))
		ftl->k = set_complex(ftl->cam.re + edge.re, ftl->cam.im - edge.im);
	draw(ftl);
	return (0);
}
