/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 23:26:17 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/18 17:34:02 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_complex	c_pow(t_complex c, int pow)
{
	if (pow <= 1)
		return (c);
	return (c_mult(c, c_pow(c, pow - 1)));
}

t_complex	c_rev_im(t_complex c)
{
	return (set_complex(c.re, -c.im));
}

t_complex	c_abs_re(t_complex c)
{
	return (set_complex(c.re < 0 ? -c.re : c.re, c.im));
}

t_complex	c_abs_im(t_complex c)
{
	return (set_complex(c.re, c.im < 0 ? -c.im : c.im));
}

double		c_abs_sq(t_complex c)
{
	return (c.re * c.re + c.im * c.im);
}
