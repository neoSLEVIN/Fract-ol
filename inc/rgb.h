/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:12:53 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/17 16:15:12 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RGB_H
# define RGB_H

typedef struct	s_rgb
{
	short		r;
	short		g;
	short		b;
}				t_rgb;

t_rgb			set_rgb(int red, int green, int blue);
void			hex_to_rgb(char *hex, t_rgb *color);
void			print_hex(t_rgb color);
int				rgbcmp(t_rgb rgb1, t_rgb rgb2);

#endif
