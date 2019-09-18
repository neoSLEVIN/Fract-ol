/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschoen <cschoen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 02:44:31 by cschoen           #+#    #+#             */
/*   Updated: 2019/09/17 15:48:01 by cschoen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "err_usg.h"

int	red_x_button(void *param)
{
	(void)param;
	exit(0);
}

int	error(char *err_msg)
{
	if (err_msg)
	{
		ft_putstr("Error: ");
		ft_putendl(err_msg);
	}
	exit(1);
}

int	lite_usage(char *app_name, _Bool list_of_frac)
{
	if (list_of_frac)
		list_of_fractol(app_name);
	ft_putstr("Try '");
	ft_putstr(app_name);
	ft_putendl(" --help' for more information.");
	exit(1);
}

int	err_usage(char *err_msg, char *app_name, _Bool full)
{
	if (err_msg)
	{
		ft_putstr("Error: ");
		ft_putendl(err_msg);
	}
	return (full ? usage(app_name) : lite_usage(app_name, 0));
}

