/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 20:26:07 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/22 02:28:19 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	new_image(t_frac *ftl, int size)
{
	if (!(ftl->img = (t_img*)malloc(sizeof(t_img))))
		error("No memory allocated for new image");
	if (!(ftl->img->img_ptr = mlx_new_image(ftl->mlx_ptr, size, size)))
		error("Failed to create a new image");
	ftl->img->data = mlx_get_data_addr(ftl->img->img_ptr, &ftl->img->bpp,
									&ftl->img->size_line, &ftl->img->endian);
	ftl->img->size = size;
	ftl->img->pos.x = SCREEN + (SCREEN - size) / 2;
	ftl->img->pos.y = (SCREEN - size) / 2;
	ftl->img->type = ftl->type;
}

void	new_black_image(t_frac *ftl)
{
	if (!(ftl->black_img = (t_img *)malloc(sizeof(t_img))))
		error("No memory allocated for new image");
	if (!(ftl->black_img->img_ptr = mlx_new_image(ftl->mlx_ptr, 500, 500)))
		error("Failed to create a new image");
	ftl->black_img->data = mlx_get_data_addr(ftl->black_img->img_ptr,
					&ftl->black_img->bpp, &ftl->black_img->size_line,
						&ftl->black_img->endian);
	ftl->black_img->size = 500;
	ftl->black_img->pos.x = 0;
	ftl->black_img->pos.y = 0;
	ftl->black_img->type = 0;
}

void	new_side_image(t_frac *ftl, int size)
{
	t_img	*side;
	int		i;

	i = -1;
	if (!(ftl->side_imgs = (t_img*)malloc(sizeof(t_img) * 5)))
		error("No memory allocated for new image");
	side = ftl->side_imgs;
	while (++i < 5)
	{
		if (!(side[i].img_ptr = mlx_new_image(ftl->mlx_ptr, size, size)))
			error("Failed to create a new image");
		side[i].data = mlx_get_data_addr(side[i].img_ptr, &side[i].bpp,
									&side[i].size_line, &side[i].endian);
		side[i].size = size;
		side[i].pos.x = SCREEN + i * (size + 1);
		side[i].pos.y = SCREEN + 1;
		side[i].type = i + (i >= (int)ftl->type ? 1 : 0);
	}
}
