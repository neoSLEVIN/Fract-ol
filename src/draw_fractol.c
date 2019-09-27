/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 00:19:35 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/28 01:03:39 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*choose_fractol(void *thr)
{
	t_thread	*th;
	t_img		*img;
	t_point		min_max;

	th = (t_thread*)thr;
	img = (th->img_id == -1) ? th->ftl->img : &th->ftl->side_imgs[th->img_id];
	min_max.x = th->y_min;
	min_max.y = th->y_max;
	if (img->type == MANDELBROT)
		mandelbrot(th->ftl, th->ftl_id, min_max, img);
/*	else if (img->type == BURNING_SHIP)
		burning_ship(th->ftl, th->ftl_id, min_max, img);
	else if (img->type == MANDELBAR)
		mandelbar(th->ftl, th->ftl_id, min_max, img);
	else if (img->type == CELTIC)
		celtic(th->ftl, th->ftl_id, min_max, img);*/
	else if (img->type == JULIA)
		julia(th->ftl, th->ftl_id, min_max, img);
//	else if (img->type == NEWTON)
//		newton(th->ftl, th->ftl_id, min_max, img);
	pthread_exit(0);
}

void		draw_fractol(t_frac *ftl, t_img *img, int img_id)
{
	pthread_t	t[img->t_max];
	t_thread	fr[img->t_max];
	int			i;

	img->type == NEWTON ? clean_image(img) : 0;
	i = -1;
	while(++i < img->t_max)
	{
		fr[i].ftl = ftl;
		fr[i].ftl_id = i;
		fr[i].img_id = img_id;
		fr[i].y_min = i * img->y_lines;
		fr[i].y_max =
				(i == img->t_max - 1) ? img->size : fr[i].y_min + img->y_lines;
		if (pthread_create(t + i, NULL, choose_fractol, (void*)&fr[i]))
			error("Bad pthread_create return value");
	}
	while (i--)
		if (pthread_join(t[i], NULL))
			error("Bad pthread_join return value");
}
