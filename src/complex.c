/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:26:45 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/18 17:35:46 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_complex	set_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_complex	c_plus(t_complex c1, t_complex c2)
{
	return (set_complex(c1.re + c2.re, c1.im + c2.im));
}

t_complex	c_minus(t_complex c1, t_complex c2)
{
	return (set_complex(c1.re - c2.re, c1.im - c2.im));
}

t_complex	c_mult(t_complex c1, t_complex c2)
{
	return (set_complex(c1.re * c2.re - c1.im * c2.im,
						c1.re * c2.im + c1.im * c2.re));
}

t_complex	c_divide(t_complex c1, t_complex c2)
{
	double	divider;

	divider = c2.re * c2.re + c2.im * c2.im;
	return (set_complex((c1.re * c2.re + c1.im * c2.im) / divider,
						(c1.im * c2.re - c1.re * c2.im) / divider));
}
