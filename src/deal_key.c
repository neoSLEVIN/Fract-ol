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
			key == Q_KEY || key == E_KEY || key == R_SHIFT || key == R_CTRL);
}

static void	change_color(t_rgb *colors, int cnt, int color, int key)
{
	int	i;
	int	max;

	i = color > 0 ? color - 2 : -1;
	max = color > 0 ? color : cnt;
	while (++i < max)
	{
		if (key == Q_KEY || key == R_SHIFT)
			colors[i].r = (colors[i].r + COLOR) % 512;
		if (key == W_KEY || key == R_SHIFT)
			colors[i].g = (colors[i].g + COLOR) % 512;
		if (key == E_KEY || key == R_SHIFT)
			colors[i].b = (colors[i].b + COLOR) % 512;
		if (key == A_KEY || key == R_CTRL)
			colors[i].r = (512 - COLOR + colors[i].r) % 512;
		if (key == S_KEY || key == R_CTRL)
			colors[i].g = (512 - COLOR + colors[i].g) % 512;
		if (key == D_KEY || key == R_CTRL)
			colors[i].b = (512 - COLOR + colors[i].b) % 512;
	}
}

static void	shift_color(t_rgb *colors, int cnt, int key)
{
	t_rgb	temp;
	int		i;

	if (key == L_SHIFT)
	{
		i = cnt;
		temp = colors[i - 1];
		while (--i > 0)
			colors[i] = colors[i - 1];
		colors[0] = temp;
	}
	else
	{
		i = -1;
		temp = colors[0];
		while (++i < cnt - 1)
			colors[i] = colors[i + 1];
		colors[cnt - 1] = temp;
	}
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
	else if (is_color(key) && ftl->type == NEWTON)
		change_color(ftl->root.cols, ftl->root.cnt, ftl->mem.color, key);
	else if (is_color(key))
		change_color(ftl->grad.col, ftl->grad.col_cnt, ftl->mem.color, key);
	else if ((key == L_SHIFT || key == L_CTRL) && ftl->type == NEWTON)
		shift_color(ftl->root.cols, ftl->root.cnt, key);
	else if (key == L_SHIFT || key == L_CTRL)
		shift_color(ftl->grad.col, ftl->grad.col_cnt, key);
	else
		deal_key2(ftl, key);
	draw(ftl);
	return (0);
}
