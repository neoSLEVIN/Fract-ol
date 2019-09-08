/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 02:50:15 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/08 05:43:08 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		is_move(int key)
{
	return (key == UP || key == DOWN || key == EIGHT_NUM || key == TWO_NUM ||
		key == RIGHT || key == LEFT || key == FOUR_NUM || key == SIX_NUM);
}

void	zoom_std(t_frac *ftl, int key)
{
	double	temp;

	temp = ftl->zoom;
	if (ftl->zoom == ftl->flg->zoom || ftl->zoom == 1)
		ftl->zoom = ftl->mem.zoom;
	else
		ftl->zoom = (key == ONE_NUM) ? 1 : ftl->flg->zoom;
	ftl->mem.zoom = temp;
}

void	move_std(t_frac *ftl, int key)
{
	t_complex	temp;

	temp = ftl->cam;
	if (ftl->cam.re == ftl->flg->cam.re && ftl->cam.im == ftl->flg->cam.im)
		ftl->cam = ftl->mem.cam;
	else if (ftl->cam.re == 0 && ftl->cam.im == 0)
		ftl->cam = ftl->mem.cam;
	else if (key == ENTER_NUM || key == ENTER)
		ftl->cam = set_complex(0, 0);
	else
		ftl->cam = ftl->flg->cam;
	ftl->mem.cam = temp;
}

void	zoom_camera(t_frac *ftl, int key)
{
	if (key == MINUS || key == PLUS)
		ftl->zoom *= (key == MINUS ? (1.0 / ZOOM) : ZOOM);
	else
		ftl->zoom *= (key == DIV) ? 1.0 / (10 * ZOOM) : (10 * ZOOM);
	ftl->zoom < 0.05 ? ftl->zoom = 0.05 : 0;
}

void	move_camera(t_frac *ftl, int key)
{
	if (key == LEFT || key == FOUR_NUM)
		ftl->cam.re -= ((key == LEFT) ? SPEED : (4 * SPEED)) / ftl->zoom;
	if (key == RIGHT || key == SIX_NUM)
		ftl->cam.re += ((key == RIGHT) ? SPEED : (4 * SPEED)) / ftl->zoom;
	if (key == UP || key == EIGHT_NUM)
		ftl->cam.im += ((key == UP) ? SPEED : (4 * SPEED)) / ftl->zoom;
	if (key == DOWN || key == TWO_NUM)
		ftl->cam.im -= ((key == DOWN) ? SPEED : (4 * SPEED)) / ftl->zoom;
}
