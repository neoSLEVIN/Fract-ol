/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:26:06 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/01 05:11:35 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
static int	is_color(int key)
{
	return (key == A_KEY || key == W_KEY || key == D_KEY || key == S_KEY ||
			key == Q_KEY || key == E_KEY);
}
*/
static int	is_move(int key)
{
	return (key == UP || key == DOWN || key == LEFT || key == RIGHT ||
	key == EIGHT_NUM || key == TWO_NUM || key == FOUR_NUM || key == SIX_NUM);
}

static void	zoom_camera(t_frac *ftl, int key)
{
	if (key == MINUS || key == PLUS)
		ftl->zoom += (key == MINUS ? ZOOM : -ZOOM);
	else
		ftl->zoom += (key == DIV) ? (10 * ZOOM) : -(10 * ZOOM);
	ftl->zoom < ZOOM ? ftl->zoom = ZOOM : 0;
}

static void	move_camera(t_frac *ftl, int key)
{
	if (key == LEFT || key == FOUR_NUM)
		ftl->cam.re -= ((key == LEFT) ? SPEED : (4 * SPEED));
	if (key == RIGHT || key == SIX_NUM)
		ftl->cam.re += ((key == RIGHT) ? SPEED : (4 * SPEED));
	if (key == UP || key == EIGHT_NUM)
		ftl->cam.im -= ((key == UP) ? SPEED : (4 * SPEED));
	if (key == DOWN || key == TWO_NUM)
		ftl->cam.im += ((key == DOWN) ? SPEED : (4 * SPEED));
}

int			deal_key(int key, void *param)
{
	t_frac	*ftl;

	ftl = (t_frac*)param;
	if (key == ESC)
		red_x_button(ftl);
	else if (key == Z_KEY || key == ZERO_NUM)
		ftl->zoom = 1;
	else if	(key == MINUS || key == PLUS || key == DIV || key == MULT)
		zoom_camera(ftl, key);
	else if (key == C_KEY || key == DOT)
	{
		ftl->flg->flag ^= F_COL + F_GRD;
		set_grad_colors(ftl, ftl->flg);
	}
	else if (key == F_KEY || key == ONE_NUM)
		++ftl->type;
	else if (is_move(key))
		move_camera(ftl, key);
	draw(ftl);
	return (0);
}
