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

static void	change_color(t_frac *ftl, int key)
{
	int	i;

	i = -1;
	while (++i < ftl->grad.col_cnt)
	{
		if (key == Q_KEY || key == R_SHIFT)
			ftl->grad.col[i].r = (ftl->grad.col[i].r + 8) % 512;
		else if (key == W_KEY || key == R_SHIFT)
			ftl->grad.col[i].g = (ftl->grad.col[i].g + 8) % 512;
		else if (key == E_KEY || key == R_SHIFT)
			ftl->grad.col[i].b = (ftl->grad.col[i].b + 8) % 512;
		else if (key == A_KEY || key == R_CTRL)
			ftl->grad.col[i].r = (504 + ftl->grad.col[i].r) % 512;
		else if (key == S_KEY || key == R_CTRL)
			ftl->grad.col[i].g = (504 + ftl->grad.col[i].g) % 512;
		else if (key == D_KEY || key == R_CTRL)
			ftl->grad.col[i].b = (504 + ftl->grad.col[i].b) % 512;
	}
}

static void	shift_color(t_frac *ftl, int key)
{
	t_rgb	temp;
	int		i;

	if (key == L_SHIFT)
	{
		i = ftl->grad.col_cnt;
		temp = ftl->grad.col[i - 1];
		while (--i > 0)
			ftl->grad.col[i] = ftl->grad.col[i - 1];
		ftl->grad.col[0] = temp;
	}
	else
	{
		i = -1;
		temp = ftl->grad.col[0];
		while (++i < ftl->grad.col_cnt - 1)
			ftl->grad.col[i] = ftl->grad.col[i + 1];
		ftl->grad.col[ftl->grad.col_cnt - 1] = temp;
	}
}

static void	deal_key2(t_frac *ftl, int key)
{
	if (key == F_KEY)
		++ftl->type;
	printf("%f\t%f\n", ftl->cam.re, ftl->cam.im);
}

int			deal_key(int key, void *param)
{
	t_frac	*ftl;

	ftl = (t_frac*)param;
	if (key == ESC)
		red_x_button(ftl);
	if (key == X_KEY || key == FIVE_NUM || key == ENTER_NUM || key == ENTER)
		move_std(ftl, key);
	else if (key == Z_KEY || key == ZERO_NUM || key == ONE_NUM)
		zoom_std(ftl, key);
	else if (is_move(key))
		move_camera(ftl, key);
	else if	(key == MINUS || key == PLUS || key == DIV || key == MULT)
		zoom_camera(ftl, key);
	else if (is_color(key) || key == R_SHIFT || key == R_CTRL)
		change_color(ftl, key);
	else if (key == L_SHIFT || key == L_CTRL)
		shift_color(ftl, key);
	else if (key == C_KEY || key == DOT)
	{
		ftl->flg->flag ^= F_COL + F_GRD;
		set_grad_colors(ftl, ftl->flg);
	}
	deal_key2(ftl, key);
	draw(ftl);
	return (0);
}
