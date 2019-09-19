/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grad.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:25:36 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/19 04:55:40 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAD_H
# define GRAD_H

# define RANGE 0.03

# include "rgb.h"

typedef struct	s_gradient
{
	int			col_cnt;
	double		range[9];
	t_rgb		col[9];
	t_rgb		tmp;
}				t_grad;

t_rgb	*get_grad_color(t_grad *grad, double *t);
void	change_grad(t_grad *grad, int color, int key);

#endif
