/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 07:09:12 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/19 06:52:11 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	switch_color(t_frac *ftl)
{
	ftl->flg->flag ^= F_COL + F_GRD;
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

void		deal_key2(t_frac *ftl, int key)
{
	if (key == F_KEY || key == G_KEY)
		key == F_KEY ? --ftl->type : ++ftl->type;
	else if (key == TAB)
		ftl->mem.ui ^= 1;
	else if (key == C_KEY || key == DOT)
		switch_color(ftl);
	else if (key == SPACE)
		ftl->mem.center ^= 1;
	else if (key == I_KEY)
		print_info(ftl);
	else if (key == O_KEY)
		print_cmd(ftl);
/*	else if (key == U_KEY)
		print_ui(ftl);*/
	else if (key == PLUS_KEY || (key == MINUS_KEY && ftl->pow > 2))
		key == PLUS_KEY ? ++ftl->pow : --ftl->pow;
	else if (ftl->mem.color == 0 && (key == L_BRACKET || key == R_BRACKET))
	{
		ftl->iter += (key == L_BRACKET ? -10 : 10);
		ftl->iter < 2 ? ftl->iter = 2 : 0;
	}
	else if (ftl->mem.color != 0 && (key == L_BRACKET || key == R_BRACKET))
		change_grad(&ftl->grad, ftl->mem.color - 1, key == L_BRACKET ? 1 : 0);
	else
		choose_number(ftl, key);
}
