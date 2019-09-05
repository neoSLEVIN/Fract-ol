/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 22:26:06 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/05 22:28:32 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_color(int key)
{
	return (key == A_KEY || key == W_KEY || key == D_KEY || key == S_KEY ||
			key == Q_KEY || key == E_KEY);
}

static int	is_move(int key)
{
	return (key == UP || key == DOWN || key == LEFT || key == RIGHT ||
	key == EIGHT_NUM || key == TWO_NUM || key == FOUR_NUM || key == SIX_NUM);
}

//	printf("%f\t%f\n", ftl->cam.re, ftl->cam.im);
//		print_info(ftl, ftl->flg);

static void	zoom_std(t_frac *ftl, int key)
{
	double	temp;

	temp = ftl->zoom;
	if (ftl->zoom == ftl->flg->zoom || ftl->zoom == 1)
		ftl->zoom = ftl->mem.zoom;
	else
		ftl->zoom = (key == ONE_NUM) ? 1 : ftl->flg->zoom;
	ftl->mem.zoom = temp;
}

static void	move_std(t_frac *ftl, int key)
{
	t_complex	temp;

	temp = ftl->cam;
	if (ftl->cam.re == ftl->flg->comp.re && ftl->cam.im == ftl->flg->comp.im)
		ftl->cam = ftl->mem.cam;
	else if (ftl->cam.re == 0 && ftl->cam.im == 0)
		ftl->cam = ftl->mem.cam;
	else
		ftl->cam = (key == ENTER_NUM) ? set_complex(0, 0) : ftl->flg->comp;
	ftl->mem.cam = temp;
}

static void	zoom_camera(t_frac *ftl, int key)
{
	if (key == MINUS || key == PLUS)
		ftl->zoom *= (key == MINUS ? (1 / ZOOM) : ZOOM);
	else
		ftl->zoom *= (key == DIV) ? 1 / (10 * ZOOM) : (10 * ZOOM);
	ftl->zoom < 0.05 ? ftl->zoom = 0.05 : 0;
}

static void	move_camera(t_frac *ftl, int key)
{
	if (key == LEFT || key == FOUR_NUM)
		ftl->cam.re -= ((key == LEFT) ? SPEED : (4 * SPEED)) / ftl->zoom;
	if (key == RIGHT || key == SIX_NUM)
		ftl->cam.re += ((key == RIGHT) ? SPEED : (4 * SPEED)) / ftl->zoom;
	if (key == UP || key == EIGHT_NUM)
		ftl->cam.im -= ((key == UP) ? SPEED : (4 * SPEED)) / ftl->zoom;
	if (key == DOWN || key == TWO_NUM)
		ftl->cam.im += ((key == DOWN) ? SPEED : (4 * SPEED)) / ftl->zoom;
	printf("%f\t%f\n", ftl->cam.re, ftl->cam.im);
}

static void	change_color(t_frac *ftl, int key)
{
	int	i;

	i = -1;
	while (++i < ftl->grad.col_cnt)
	{
		if (key == Q_KEY)
			ftl->grad.col[i].r = (ftl->grad.col[i].r + 3) % 256;
		else if (key == W_KEY)
			ftl->grad.col[i].g = (ftl->grad.col[i].g + 3) % 256;
		else if (key == E_KEY)
			ftl->grad.col[i].b = (ftl->grad.col[i].b + 3) % 256;
		else if (key == A_KEY)
			ftl->grad.col[i].r = (253 + ftl->grad.col[i].r) % 256;
		else if (key == S_KEY)
			ftl->grad.col[i].g = (253 + ftl->grad.col[i].g) % 256;
		else if (key == D_KEY)
			ftl->grad.col[i].b = (253 + ftl->grad.col[i].b) % 256;
	}
}

int			deal_key(int key, void *param)
{
	t_frac	*ftl;

	ftl = (t_frac*)param;
	if (key == ESC)
		red_x_button(ftl);
	else if (key == Z_KEY || key == ZERO_NUM || key == ONE_NUM)
		zoom_std(ftl, key);
	else if (key == X_KEY || key == FIVE_NUM || key == ENTER_NUM)
		move_std(ftl, key);
	else if	(key == MINUS || key == PLUS || key == DIV || key == MULT)
		zoom_camera(ftl, key);
	else if (is_move(key))
		move_camera(ftl, key);
	else if (is_color(key))
		change_color(ftl, key);
	else if (key == C_KEY || key == DOT)
	{
		ftl->flg->flag ^= F_COL + F_GRD;
		set_grad_colors(ftl, ftl->flg);
	}
	else if (key == F_KEY)
		++ftl->type;
	draw(ftl);
	return (0);
}
