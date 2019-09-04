/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:58:33 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/04 23:22:25 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_click(int button, int x, int y, void *param)
{
	t_frac	*ftl;

	ftl = (t_frac*)param;
	ftl->cam.re += x / (ftl->size.x - 1) / ftl->zoom;

//	ftl->cam.re += 4 / ftl->zoom / (ftl->size.x - 1) * ((x - (double)(ftl->size.x - 1) / 2) / 2);
//	ftl->cam.im += 4 / ftl->zoom / (ftl->size.x - 1) * ((y - (double)(ftl->size.y - 1) / 2) / 2);
	printf("%f\t%f\n", ftl->cam.re, ftl->cam.im);
	if (button == 4)
		ftl->zoom *= ZOOM;
	if (button == 5)
		ftl->zoom /= ZOOM;
	ftl->zoom < 0.05 ? ftl->zoom = 0.05 : 0;
	draw(ftl);
	return (0);
}
