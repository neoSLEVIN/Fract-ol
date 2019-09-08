/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 20:24:30 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/08 23:28:52 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	choose_number(t_frac *ftl, int key)
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
	if (ftl->mem.color > ftl->grad.col_cnt)
		ftl->mem.color = 0;
}

void	choose_gradient(t_frac *ftl, int key)
{
	int	color;

	color = ftl->mem.color - 1;
	if (color == 0 || color >= ftl->grad.col_cnt - 1)
		return ;
	if (key == L_BRACKET &&
		ftl->grad.range[color] - RANGE >= ftl->grad.range[color + 1])
		ftl->grad.range[color] -= RANGE;
	else if (key == R_BRACKET &&
		ftl->grad.range[color] + RANGE <= ftl->grad.range[color - 1])
		ftl->grad.range[color] += RANGE;
}
