/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:34:14 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/18 18:27:19 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

t_complex		set_complex(double re, double im);
t_complex		c_plus(t_complex c1, t_complex c2);
t_complex		c_minus(t_complex c1, t_complex c2);
t_complex		c_mult(t_complex c1, t_complex c2);
t_complex		c_divide(t_complex c1, t_complex c2);
t_complex		c_pow(t_complex c, int pow);
t_complex		c_rev_im(t_complex c);
t_complex		c_abs_re(t_complex c);
t_complex		c_abs_im(t_complex c);
double			c_abs_sq(t_complex c);

t_complex		*set_complex_p(double re, double im, t_complex *temp);
t_complex		*cp_plus(t_complex *c1, t_complex *c2, t_complex *temp);
t_complex		*cp_minus(t_complex *c1, t_complex *c2, t_complex *temp);
t_complex		*cp_mult(t_complex *c1, t_complex *c2, t_complex *temp);
t_complex		*cp_divide(t_complex *c1, t_complex *c2, t_complex *temp);
t_complex		*cp_pow(t_complex *c, int pow, t_complex *temp);
t_complex		*cp_rev_im(t_complex *c, t_complex *temp);
t_complex		*cp_abs_re(t_complex *c, t_complex *temp);
t_complex		*cp_abs_im(t_complex *c, t_complex *temp);
double			cp_abs_sq(t_complex *c);

#endif
