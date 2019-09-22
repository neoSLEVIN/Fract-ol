/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 07:09:12 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/22 01:50:19 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	switch_color(t_frac *ftl)
{
	ftl->flg->flag ^= F_COL;
	set_grad_colors(ftl, ftl->flg);
}

static void	choose_number(t_frac *ftl, int key)
{
	if (key == ONE_KEY)
		ftl->mem.color = 1;
	else if (key == TWO_KEY)
		ftl->mem.color = 2;
	else if (key == THREE_KEY)
		ftl->mem.color = 3;
	else if (key == FOUR_KEY)
		ftl->mem.color = 4;
	else if (key == FIVE_KEY)
		ftl->mem.color = 5;
	else if (key == SIX_KEY)
		ftl->mem.color = 6;
	else if (key == SEVEN_KEY)
		ftl->mem.color = 7;
	else if (key == EIGHT_KEY)
		ftl->mem.color = 8;
	else if (key == NINE_KEY)
		ftl->mem.color = 9;
	else if (key == ZERO_KEY)
		ftl->mem.color = 0;
	if ((ftl->type != NEWTON && ftl->mem.color > ftl->grad.col_cnt) ||
		(ftl->type == NEWTON && ftl->mem.color > ftl->root.cnt))
		ftl->mem.color = 0;
}

static void	shift_fractol(t_frac *ftl, int key)
{
	int	i;

	i = -1;
	key == F_KEY ? --ftl->type : ++ftl->type;
	key == F_KEY ? --ftl->img->type : ++ftl->img->type;
	if (ftl->type == CNT_OF_TYPES)
	{
		ftl->type = MANDELBROT;
		ftl->img->type = MANDELBROT;
	}
	if (ftl->type > CNT_OF_TYPES)
	{
		ftl->type = CNT_OF_TYPES - 1;
		ftl->img->type = CNT_OF_TYPES - 1;
	}
	while (++i < 5)
		if (ftl->side_imgs[i].type == ftl->type)
		{
			key == F_KEY ? ++ftl->side_imgs[i].type : --ftl->side_imgs[i].type;
			if (ftl->side_imgs[i].type == CNT_OF_TYPES)
				ftl->side_imgs[i].type = MANDELBROT;
			if (ftl->side_imgs[i].type > CNT_OF_TYPES)
				ftl->side_imgs[i].type = CNT_OF_TYPES - 1;
			return ;
		}
}

static void	deal_key3(t_frac *ftl, int key)
{
	t_img	*temp;

	if (key == X_KEY || key == FIVE_NUM || key == ENTER_NUM || key == ENTER)
		move_std(ftl, key);
	else if (key == Z_KEY || key == ZERO_NUM || key == ONE_NUM)
		zoom_std(ftl, key);
	else if (is_move(key))
		move_camera(ftl, key);
	else if (key == MINUS || key == PLUS || key == DIV || key == MULT)
		zoom_camera(ftl, key);
	else if ((key == INC_IMG && ftl->size != 500) ||
		(key == DEC_IMG && ftl->size != 100))
	{
		temp = ftl->img;
		ftl->size += 10 * (key == INC_IMG ? 1 : -1);
		ftl->size > 500 ? ftl->size = 500 : 0;
		ftl->size < 100 ? ftl->size = 100 : 0;
		new_image(ftl, ftl->size);
		mlx_destroy_image(ftl->mlx_ptr, temp->img_ptr);
		free(temp);
	}
	else
		choose_number(ftl, key);
}

void		deal_key2(t_frac *ftl, int key)
{
	if (key == TAB)
		ftl->mem.ui ^= 1;
	else if (key == C_KEY || key == DOT)
		switch_color(ftl);
	else if (key == F_KEY || key == G_KEY)
		shift_fractol(ftl, key);
	else if ((key == L_BRACKET || key == R_BRACKET) && ftl->type == NEWTON)
	{
		ftl->root.damping.re += key == L_BRACKET ? -0.05 : 0.05;
		ftl->root.damping.re < 0.6 ? ftl->root.damping.re = 0.6 : 0;
		ftl->root.damping.re > 1.9 ? ftl->root.damping.re = 1.9 : 0;
	}
	else if (ftl->mem.color == 0 && (key == L_BRACKET || key == R_BRACKET))
	{
		ftl->iter += (key == L_BRACKET ? -10 : 10);
		ftl->iter < 20 ? ftl->iter = 20 : 0;
	}
	else if (ftl->mem.color != 0 && (key == L_BRACKET || key == R_BRACKET))
		change_grad(&ftl->grad, ftl->mem.color - 1, key == L_BRACKET ? 1 : 0);
	else
		deal_key3(ftl, key);
}
