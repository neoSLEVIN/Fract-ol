/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:35:17 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/23 07:14:57 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_complex	*set_complex_p(double re, double im, t_complex *temp)
{
	temp->re = re;
	temp->im = im;
	return (temp);
}

t_complex	*cp_plus(t_complex *c1, t_complex *c2, t_complex *temp)
{
	return (set_complex_p(c1->re + c2->re, c1->im + c2->im, temp));
}

t_complex	*cp_minus(t_complex *c1, t_complex *c2, t_complex *temp)
{
	return (set_complex_p(c1->re - c2->re, c1->im - c2->im, temp));
}

t_complex	*cp_mult(t_complex *c1, t_complex *c2, t_complex *temp)
{
	return (set_complex_p(c1->re * c2->re - c1->im * c2->im,
						c1->re * c2->im + c1->im * c2->re, temp));
}

t_complex	*cp_pow(t_complex *c, int pow, t_complex *temp)
{
	if (pow <= 1)
		return (set_complex_p(c->re, c->im, temp));
	return (cp_mult(c, cp_pow(c, pow - 1, temp), temp));
}
