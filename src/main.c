/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:07:30 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/01 01:34:51 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			error(char *err_msg)
{
	if (err_msg)
	{
		ft_putstr("Error: ");
		ft_putendl(err_msg);
	}
	exit(ERR_EXIT);
}

void		draw(t_frac *ftl)
{
	if (ftl->type == MANDELBROT)
		mandelbrot(ftl);
	mlx_put_image_to_window(ftl->mlx_ptr, ftl->win_ptr,
							ftl->img->img_ptr, 0, 0);
}

static void	input_hook(t_frac *ftl)
{
	mlx_mouse_hook(ftl->win_ptr, mouse_click, ftl);
	mlx_hook(ftl->win_ptr, 17, 1, red_x_button, (void *)0);
	mlx_hook(ftl->win_ptr, 2, 3, deal_key, ftl);
}

int			main(int argc, char **argv)
{
	t_frac	*ftl;
	t_flg	*flg;

	if (argc == 1)
		usage(argv[0]);
	if (!(flg = (t_flg*)malloc(sizeof(t_flg))))
		error("No memory allocated for FLAGS");
	if (!(ftl = (t_frac*)malloc(sizeof(t_frac))))
		error("No memory allocated for FRACTOL");
	init_flg(flg, argc, argv);
	init_fractol(ftl, flg);
	draw(ftl);
	input_hook(ftl);
	mlx_loop(ftl->mlx_ptr);
	return (0);
}
