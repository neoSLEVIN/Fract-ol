/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:58:33 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/01 00:42:46 by cschoen          ###   ########.fr       */
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
		ftl->zoom += 1;
	if (button == 5)
	{
		if (ftl->zoom >= 2)
			ftl->zoom -= 1;
		else
			ftl->zoom = 1;
	}
	draw(ftl);
	return (0);
}
