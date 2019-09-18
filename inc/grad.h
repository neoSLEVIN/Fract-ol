/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grad.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:25:36 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/17 20:24:02 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAD_H
# define GRAD_H

# define RANGE 0.03

# include "rgb.h"

typedef struct	s_gradient
{
	int			col_cnt;
	t_rgb		col[9];
	double		range[9];
}				t_grad;

t_rgb	get_grad_color(t_grad *grad, double t);
void	change_grad(t_grad *grad, int color, int key);

#endif
