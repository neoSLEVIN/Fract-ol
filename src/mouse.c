/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:58:33 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/01 04:21:58 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_click(int button, int x, int y, void *param)
{
	t_frac	*ftl;

	ftl = (t_frac*)param;
	++x;
	++y;
	if (button == 4)
		ftl->zoom += ZOOM;
	if (button == 5)
		ftl->zoom -= ZOOM;
	ftl->zoom < ZOOM ? ftl->zoom = ZOOM : 0;
	draw(ftl);
	return (0);
}
