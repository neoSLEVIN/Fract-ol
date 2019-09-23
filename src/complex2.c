/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:26:17 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/23 07:14:52 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_complex	*cp_divide(t_complex *c1, t_complex *c2, t_complex *temp)
{
	double	divider;

	divider = c2->re * c2->re + c2->im * c2->im;
	return (set_complex_p((c1->re * c2->re + c1->im * c2->im) / divider,
					(c1->im * c2->re - c1->re * c2->im) / divider, temp));
}

t_complex	*cp_rev_im(t_complex *c, t_complex *temp)
{
	return (set_complex_p(c->re, -c->im, temp));
}

t_complex	*cp_abs_re(t_complex *c, t_complex *temp)
{
	return (set_complex_p(c->re < 0 ? -c->re : c->re, c->im, temp));
}

t_complex	*cp_abs_im(t_complex *c, t_complex *temp)
{
	return (set_complex_p(c->re, c->im < 0 ? -c->im : c->im, temp));
}

double		cp_abs_sq(t_complex *c)
{
	return (c->re * c->re + c->im * c->im);
}
